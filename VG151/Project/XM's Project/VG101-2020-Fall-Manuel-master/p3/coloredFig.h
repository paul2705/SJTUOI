#ifndef COLOREDFIG_H
#define COLOREDFIG_H
#include <cmath>
#include <ctime>
#include <cstdlib>
static const float PI = (float) 3.1415926535;

// Immutable Vec class makes calculation easier
class Vec{
    private:
        float x,y;
    public:
        Vec(float _x=0,float _y=0) { x=_x, y=_y; };
        float getX(){ return x; };
        float getY(){ return y; };
        Vec operator+ (Vec v) { return Vec(x + v.getX(), y + v.getY()); }
        Vec operator- (Vec v){ return Vec(x-v.getX(),y-v.getY()); }
        Vec operator* (double k){ return Vec(x*(float)k,y*(float)k); }
        double operator* (Vec v){ return v.getX()*x+v.getY()*y; }
        Vec operator>> (float angle){ return Vec(x*(float)cos(angle)+y*(float)sin(angle),-(float)sin(angle)*x+(float)cos(angle)*y); }//clockwise
        Vec operator<< (float angle){ return Vec(x*(float)cos(angle)-y*(float)sin(angle),x*(float)sin(angle)+y*(float)cos(angle)); }//counter clockwise
        double operator> (Vec v){v=(*this)-v;return pow(pow(v.getX(),2)+pow(v.getY(),2),0.5);}
};

// Basic class for all shapes
class Shape {
    public:
        Shape():cen(0,0){}
        void virtual draw() = 0;
        void virtual move(Vec d_vec) = 0;
        void virtual rotate(float angle,Vec rot_cen) = 0;
        void virtual zoom(float scale) = 0;
        void paint();
        virtual ~Shape(){};
    protected:
        float r, g, b;
        Vec cen;
};

class Triangle: public Shape {
    public:
        Triangle(Vec temp_cen,Vec pt1={-.5,-.5}, Vec pt2={.5,-.5}, Vec pt3={0,.5}, float r=0, float g=0, float b=0);
        void move(Vec d_vec);
        void zoom(float scale);
        void rotate(float angle,Vec rot_cen);
        void draw();
    private:
        Vec p1,p2,p3;
};

class Quads: public Shape {
    public:
        Quads(Vec temp_cen,Vec pt1, Vec pt2, Vec pt3, Vec pt4, float r=0, float g=0, float b=0);
        void move(Vec d_vec);
        void zoom(float scale);
        void rotate(float angle,Vec rot_cen);
        void draw();
    private:
        Vec p1,p2,p3,p4;
};

class Polygon: public Shape {
    public:
        Polygon(Vec temp_cen,float temp_radius=1,float temp_rad=2*PI,int temp_sides=0,float temp_start=0,float r=0,float g=0,float b=0);
        ~Polygon() {};
        void draw();
        void move(Vec d_vec){cen = cen + d_vec;};
        void zoom(float scale){radius *= scale;};
        void rotate(float angle,Vec rot_cen);
        void change_size(int size);
    protected:
        float rad; //the central angle,2*PI refers to a whole circle, 1*PI refers to a semicircle;
        float radius;
        float start_angle; //the angle of one of the radium;
        int sides; //a circle's sides is 3600;
};

class Line: public Shape {
    public:
        Line(Vec temp_cen,Vec temp_p1={0,0}, Vec temp_p2={0,0}, int temp_type=0, int temp_width=0, float r=0, float g=0, float b=0);
        void draw();
        void move(Vec d_vec);
        void zoom(float scale);
        void rotate(float angle,Vec rot_cen);
        ~Line() {};
    private:
        Vec p1,p2;
        int type;
        int width;
};

#endif
