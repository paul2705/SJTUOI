#include"Shapes.h"

namespace ZJY{
    Vec::Vec(float _PointX, float _PointY)
            {
                x = _PointX;
                y = _PointY;
            }

    Vec Vec::get_normal_vector()
            {
                float r = (float)sqrt(x * x + y * y);
                return Vec(-y / r, x / r);
            }

    Vec Vec::get_unit_vector()
            {
                float r = (float)sqrt(x * x + y * y);
                return Vec(x / r, y / r);
            }

    Vec Vec::operator+(Vec v)
            {
                return Vec(x + v.getX(), y + v.getY());
            }

    Vec Vec::operator-(Vec v)
            {
                return Vec(x - v.getX(), y - v.getY());
            }

    Vec Vec::operator*(float k)
            {
                return Vec(x * k, y * k);
            }

    float Vec::operator*(Vec v)
            {
                return x * v.getX() + y * v.getY();
            }

    Vec Vec::operator<<(float a)
            {
                return Vec(x * cos(a) - y * sin(a), y * cos(a) + x * sin(a));
            }

    Vec Vec::operator>>(float a)
            {
                return Vec(x * cos(a) + y * sin(a), y * cos(a) - x * sin(a));
            }

    bool Vec::operator==(Vec v){
                if (x!=v.getX()) return false;
                if (y!=v.getY()) return false;
                return true;
            }

    bool Vec::operator!=(Vec v){
                if (operator==(v))return false;
                else return true;
            }
            
    void ColoredFig::draw()
    {
        glColor3f(r, g, b);
        if (points.size() <= 2)
            return;
        switch (points.size())
        {
        case 3:
            glBegin(GL_TRIANGLE_STRIP);
            break;
        case 4:
            glBegin(GL_QUADS);
            break;
        default:
            glBegin(GL_POLYGON);
            break;
        }
        std::vector<Vec>::iterator it;
        for (it = points.begin(); it != points.end(); it++)
        {
            glVertex2d(it->getX(), it->getY());
        }
        glEnd();
    }
    void ColoredFig::move(Vec dir)
    {
        std::vector<Vec>::iterator it;
        for (it = points.begin(); it != points.end(); it++)
        {
            *it = *it + dir;
        }
    }
    void ColoredFig::rotate(float angle)
    {
        std::vector<Vec>::iterator it;
        for (it = points.begin(); it != points.end(); it++)
        {
            Vec temp = *it - anchor;
            temp = temp << angle;
            *it = anchor + temp;
        }
    }
    void ColoredFig::zoom(float k)
    {
        std::vector<Vec>::iterator it;
        for (it = points.begin(); it != points.end(); it++)
        {
            Vec temp = *it - anchor;
            temp = temp * k;
            *it = anchor + temp;
        }
    }
    Line::Line(Vec pt1, Vec pt2, float Linewidth, float red, float green, float blue)
    {
        r = red;
        g = green;
        b = blue;
        Vec temp = pt1 - pt2;
        Vec nv = temp.get_normal_vector();
        nv = nv * (Linewidth / 2.0);
        Vec p1 = pt1 + nv;
        Vec p2 = pt2 + nv;
        Vec p3 = pt2 - nv;
        Vec p4 = pt1 - nv;
        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p3);
        points.push_back(p4);
        setAnchor((pt1 + pt2) * 0.5);
    }
    Circle::Circle(Vec pt1, float radius, float red, float green, float blue)
    {
        c = pt1;
        R = radius;
        r = red;
        g = green;
        b = blue;
        int n = 1024;
        for (int i = 0; i < n; i++)
        {
            points.push_back({(float)(R * cos(2 * PI * i / n) + c.getX()), (float)(R * sin(2 * PI * i / n) + c.getY())});
        }
        setAnchor(c);
    }
    Rect::Rect(Vec pt1, Vec pt2,
               float red, float green, float blue)
    {
        r = red;
        g = green;
        b = blue;
        points.push_back({pt1.getX(), pt1.getY()});
        points.push_back({pt2.getX(), pt1.getY()});
        points.push_back({pt2.getX(), pt2.getY()});
        points.push_back({pt1.getX(), pt2.getY()});
        setAnchor((pt1 + pt2) * 0.5);
    }
    
    Triangle::Triangle(Vec pt1, Vec pt2, Vec pt3,
                       float red, float green, float blue)
    {
        r = red;
        g = green;
        b = blue;
        points.push_back(pt1);
        points.push_back(pt2);
        points.push_back(pt3);
        setAnchor((pt1 + pt2 + pt3) * (1 / 3));
    }
    
    Parallelogram::Parallelogram(Vec pt1, Vec pt2, Vec pt3, float red, float green, float blue)
    {
        r = red;
        g = green;
        b = blue;
        points.push_back(pt1);
        points.push_back(pt3);
        points.push_back(pt2);
        points.push_back({pt1.getX() + pt2.getX() - pt3.getX(), pt1.getY() + pt2.getY() - pt3.getY()});
        setAnchor((pt1 + pt2) * 0.5);
    }
    
    Trapezium::Trapezium(Vec pt1, Vec pt2, Vec pt3, Vec pt4, float red, float green, float blue)
    {
        r = red;
        g = green;
        b = blue;
        points.push_back(pt1);
        points.push_back(pt2);
        points.push_back(pt3);
        points.push_back(pt4);
        setAnchor((pt1 + pt2 + pt3 + pt4) * 0.25);
    }
    
    void Group::draw()
    {
        
        std::vector<ColoredFig>::iterator it;
        for (it = fg.begin(); it != fg.end(); it++)
        {
            it->draw();
        }
        std::vector<Teleporter>::iterator it2;
        for (it2 = tp.begin(); it2 != tp.end(); it2++)
        {
            it2->draw();
        }
    }
    
    void Group::move(Vec dir)
    {
        std::vector<ColoredFig>::iterator it;
        for (it = fg.begin(); it != fg.end(); it++)
        {
            it->move(dir);
        }
    }
    
    void Group::rotate(float angle)
    {
        setFigAnchor(); // Ensure that all the figures rotate based on the same anchor i.g. the anchor of the Group
        std::vector<ColoredFig>::iterator it;
        for (it = fg.begin(); it != fg.end(); it++)
        {
            it->rotate(angle);
        }
    }
    
    void Group::zoom(float k)
    {
        setFigAnchor(); // Ensure that all the figures zoom based on the same anchor i.g. the anchor of the Group
        std::vector<ColoredFig>::iterator it;
        for (it = fg.begin(); it != fg.end(); it++)
        {
            it->zoom(k);
        }
    }
    
    void Group::setFigAnchor()
    {
        std::vector<ColoredFig>::iterator it;
        for (it = fg.begin(); it != fg.end(); it++)
        {
            it->setAnchor(anchor);
        }
    }
    
    allobjects *allobjects::getall(/* args */)
        {
            static allobjects *s = NULL;
            if (s == NULL)
                s = new allobjects;
            return s;
        }
    
    void allobjects::addFig(ColoredFig fg){
            data.push_back(fg);
        }
    
    void allobjects::move1(Vec dir,int ord){
            Vec temp=next(data.begin(),ord)->getAnchor();
            std::next(data.begin(),ord)->move(dir);
            next(data.begin(),ord)->setAnchor(temp+dir);
        }
    
    void allobjects::rotate1(Vec anchor, float angle,int ord){
            Vec temp=next(data.begin(),ord)->getAnchor();
            next(data.begin(),ord)->setAnchor(anchor);
            next(data.begin(),ord)->rotate(angle);
            temp<<angle;
            next(data.begin(),ord)->setAnchor(temp);
        }
    
    void allobjects::rotate1(float angle,int ord){
            
            next(data.begin(),ord)->rotate(angle);
            
        }
    
    void allobjects::zoom1(Vec anchor, float k,int ord){
            Vec temp=next(data.begin(),ord)->getAnchor();
            next(data.begin(),ord)->setAnchor(anchor);
            next(data.begin(),ord)->zoom(k);
            next(data.begin(),ord)->setAnchor(temp);
    
        }
    
    void allobjects::zoom1(float k,int ord){
            
            next(data.begin(),ord)->zoom(k);
            
    
        }
    
    void allobjects::draw(){
            for (auto i:data){
                i.draw();
            }
        }
    
    void allobjects::clear()
        {
            allobjects *s = getall();
            if (s != NULL)
                delete s;
        }
    
    
    
    void TimeStep(int n)
    {
        glutTimerFunc((unsigned int)n, TimeStep, n);
        allobjects* s;
        s=allobjects::getall();
        s->move1(Vec{0.001,0},0);
        s->rotate1(Vec(0,-0.5),0.001,1);
        s->zoom1(0.9999,1);
        //code for move
    
        glutPostRedisplay();
    }
    void glDraw()
    {
    
        //Car r(Vec{-0.5,0});
        //r.rotate(3);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //r.draw();
        
        allobjects::getall()->draw();
        glutSwapBuffers();
        glFlush();
    }
    
    
    void ZJYmain(int argc, char *argv[])
    {
        using namespace ZJY;
        Parallelogram a(Vec{-2,0},Vec{-1,1},Vec{0,0});
        (allobjects::getall())->addFig(a);
        allobjects* s;
        
        s=allobjects::getall();
        Rect b(Vec{-1,-1},Vec{0,0});
        s->addFig(b);
        /* initialize GLUT, using any commandline parameters passed to the program */
        glutInit(&argc, argv);
        /* setup the size, position, and display mode for new windows */
        // glutInitWindowSize(1000, 1000);
        glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
        /* create and set up a window */
        glutCreateWindow("Test");
        gluOrtho2D(-5,5,-5,5);
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glutDisplayFunc(glDraw);
        glutTimerFunc(1, TimeStep, 1);
        /* tell GLUT to wait for events */
        glutMainLoop();
        allobjects::clear();
        
    }
    
    
}



namespace jtc{
    vec::vec(){}
    vec::~vec(){}
    vec::vec(db x,db y){x0=x;y0=y;}
    db vec::x(){return x0;}
    db vec::y(){return y0;}
    vec vec::operator+ (vec v){return vec(x0+v.x(),y0+v.y());}
    vec vec::operator- (vec v){return vec(x0-v.x(),y0-v.y());}
    point vec::operator+ (point p){return p+vec(x0,y0);}
    vec vec::operator* (db k){return vec(x0*k,y0*k);}
    db vec::operator* (vec v){return x0*v.x()+y0*v.y();}
    vec vec::operator<< (db angle){
        db newX,newY;
        newX=x0*cos(angle)-y0*sin(angle);
        newY=x0*sin(angle)+y0*cos(angle);
        return vec(newX,newY);
    }
    vec vec::operator>> (db angle){return vec(x0,y0)<<-angle;}
    
    
    
    point::point(){}
    point::~point(){}
    point::point(db x,db y){x0=x;y0=y;}
    db point::x(){return x0;}
    db point::y(){return y0;}
    point point::operator+ (vec v){return point(x0+v.x(),y0+v.y());}
    point point::operator- (vec v){return point(x0,y0)+v*(-1);}
    vec point::operator- (point p){return vec(x0-p.x(),y0-p.y());}
    
    
    figure::figure(){}
    figure::~figure(){}
    void figure::setCenter(point newCenter){center=newCenter;}
    void figure::setAngle(db angl){angle=angl;}
    void figure::setSize(db siz){size=siz;}
    db figure::getAngle(){return angle;}
    db figure::getSize(){return size;}
    point figure::getCenter(){return center;}
    void figure::move(vec vec){center=center+vec;}
    void figure::rotate(db ang){angle=angle+ang;}
    void figure::zoom(db k){size=size*k;}
    
    
    
    shape::shape(){}
    shape::~shape(){}
    int shape::getType(){return type;}
    void shape::draw(){}
    
    rec::rec(){}
    rec::~rec(){}
    rec::rec(db width,db height,color co){
        halfWidth=width*0.5;
        halfHeight=height*0.5;
        size=1.0;
        c=co;
        type=1;
    }
    void rec::draw(){
        setColor(c);
        vec v1=vec(halfWidth,halfHeight)*size;
        vec v2=vec(-halfWidth,halfHeight)*size;
        vec v3=vec(-halfWidth,-halfHeight)*size;
        vec v4=vec(halfWidth,-halfHeight)*size;
        v1=v1<<angle;
        v2=v2<<angle;
        v3=v3<<angle;
        v4=v4<<angle;
        glStart();
        onePoint(center+v1);
        onePoint(center+v2);
        onePoint(center+v3);
        onePoint(center+v4);
        glEnd();
    }
    
    rttri::rttri(){}
    rttri::~rttri(){}
    rttri::rttri(db h,db b,color co){
        height=h;
        base=b;
        size=1.0;
        c=co;
        type=2;
    }
    void rttri::draw(){
        setColor(c);
        vec v1=vec(base,0.0)*size;
        vec v2=vec(0.0,height)*size;
        v1=v1<<angle;
        v2=v2<<angle;
        glStart();
        onePoint(center);
        onePoint(center+v1);
        onePoint(center+v2);
        glEnd();
    }
    
    circle::circle(){}
    circle::~circle(){}
    circle::circle(db radius,color co){
        r=radius;
        angle=0;
        size=1.0;
        c=co;
        type=3;
    }
    void circle::draw(){
        db step=2.0*PI/60.0;
        setColor(c);
        glStart();
        for(int i=0;i<=59;i++){
            onePoint(center+vec(cos(i*step),sin(i*step))*r*size);
        }
        glEnd();
    }
    
    halfcir::halfcir(){}
    halfcir::~halfcir(){}
    halfcir::halfcir(db radius,color co){
        r=radius;
        size=1.0;
        c=co;
        type=4;
    }
    void halfcir::draw(){
        db step=2.0*PI/60.0;
        setColor(c);
        glStart();
        for(int i=0;i<=30;i++){
            onePoint(center+((vec(cos(i*step),sin(i*step))*r*size)<<angle));
        }
        glEnd();
    }
    
    tri::tri(){}
    tri::~tri(){}
    tri::tri(vec vec1,vec vec2,vec vec3,color co){
        v1=vec1;
        v2=vec2;
        v3=vec3;
        angle=0;
        size=1;
        c=co;
        type=5;
    }
    void tri::draw(){
        setColor(c);
        glStart();
        onePoint(center+(v1<<angle)*size);
        onePoint(center+(v2<<angle)*size);
        onePoint(center+(v3<<angle)*size);
        glEnd();
    }
    
    pxsbx::pxsbx(){}
    pxsbx::~pxsbx(){}
    pxsbx::pxsbx(vec vec1,vec vec2,color co){
        v1=vec1;
        v2=vec2;
        c=co;
        size=1;
        angle=0;
        type=6;
    }
    void pxsbx::draw(){
        setColor(c);
        glStart();
        onePoint(center+(v1<<angle)*size);
        onePoint(center+(v2<<angle)*size);
        onePoint(center+(v1<<(PI+angle))*size);
        onePoint(center+(v2<<(PI+angle))*size);
        glEnd();
    }
    
    quad::quad(){}
    quad::~quad(){}
    quad::quad(vec vec1,vec vec2,vec vec3,vec vec4,color co){
        c=co;
        size=1;
        angle=0;
        type=7;
        v1=vec1;
        v2=vec2;
        v3=vec3;
        v4=vec4;
    }
    void quad::draw(){
        setColor(c);
        glStart();
        onePoint(center+((v1<<angle)*size));
        onePoint(center+((v2<<angle)*size));
        onePoint(center+((v3<<angle)*size));
        onePoint(center+((v4<<angle)*size));
        glEnd();
    }
    
    obj::obj(){
        status=-1;
        shapeNum=0;
        for(int i=0;i<=49;i++){shapes[i]=nullptr;}
    }
    obj::~obj(){
        for(int i=0;i<=49;i++){if(shapes[i]!=nullptr){delete shapes[i];}}
    }
    obj::obj(point centerPoint,db ang,db siz){
        status=0;
        shapeNum=0;
        center=centerPoint;
        angle=ang;
        size=siz;
        for(int i=0;i<=49;i++){shapes[i]=nullptr;}
    }
    int obj::getStatus(){return status;}
    void obj::setStatus(int sta){status=sta;}
    void obj::setShape(shape* sh,vec relaLoc,db relaAngle){
        int i=shapeNum;
        shapes[i]=sh;
        relativeLoc[i]=relaLoc;
        relativeAngle[i]=relaAngle;
        shapeNum++;
    }
    void obj::draw(){
        update();
        for(int i=0;i<=49;i++){
            if(shapes[i]==nullptr){continue;}
            shapes[i]->draw();
        }
    }
    void obj::update(){
        for(int i=0;i<=49;i++){
            if(shapes[i]==nullptr){continue;}
            shapes[i]->setAngle(angle+relativeAngle[i]);
            shapes[i]->setSize(size);
            shapes[i]->setCenter(center+((relativeLoc[i]*size)<<angle));
        }
    }
    
    all::all(){}
    all::~all(){}
    all::all(int value){
        t=0;
        if(value){}
        objs[1]=obj(point(100,100),0,1);
        objs[2]=obj(point(300,300),0,1);
        objs[1].setShape(new rec(100,50,randColor()),vec(0,0),0);
        objs[1].setShape(new tri(vec(-20,0),vec(20,0),vec(0,40),randColor()),vec(-25,25),0);
        objs[1].setShape(new tri(vec(-20,0),vec(20,0),vec(0,40),randColor()),vec(25,25),0);
        objs[1].setShape(new halfcir(10,randColor()),vec(-50,0),PI/2);
        objs[1].setShape(new circle(10,randColor()),vec(50,0),0);
        objs[1].setShape(new rttri(50,20,randColor()),vec(-10,-25),PI);
        objs[1].setShape(new pxsbx(vec(-10,20),vec(50,20),randColor()),vec(20,85),0);
        objs[1].setShape(new quad(vec(-20,15),vec(20,15),vec(30,-29),vec(-50,-40),randColor()),vec(40,-40),0);
        objs[2].setShape(new rec(100,50,randColor()),vec(0,0),0);
        objs[2].setShape(new tri(vec(-20,0),vec(20,0),vec(0,40),randColor()),vec(-25,25),0);
        objs[2].setShape(new tri(vec(-20,0),vec(20,0),vec(0,40),randColor()),vec(25,25),0);
        objs[2].setShape(new halfcir(10,randColor()),vec(-50,0),PI/2);
        objs[2].setShape(new circle(10,randColor()),vec(50,0),0);
        objs[2].setShape(new rttri(50,20,randColor()),vec(-10,-25),PI);
        objs[2].setShape(new pxsbx(vec(-10,20),vec(50,20),randColor()),vec(20,85),0);
        objs[2].setShape(new quad(vec(-20,15),vec(20,15),vec(30,-29),vec(-50,-40),randColor()),vec(40,-40),0);
    }
    void all::draw(){
        for(int i=0;i<=49;i++){
            if(objs[i].getStatus()!=-1){objs[i].draw();}
        }
    }
    void all::next(){ // 主要代码写在这里
        objs[1].setCenter(point(100+t,100+0.2*t));
        objs[1].setSize(1+t*0.005);
        objs[1].setAngle(t*0.01);
        objs[2].setCenter(point(300+t,300+0.2*t));
        objs[2].setSize(1-t*0.005);
        objs[2].setAngle(-t*0.01);
        // objs[1].move(vec(1,0.2));
        // objs[1].rotate(0.005);
        // objs[1].zoom(1.01);
        // objs[1].setCenter(objs[1].getCenter()+vec(1,0.2));
        // objs[1].setAngle(objs[1].getAngle()+0.01);
        // objs[1].setSize(objs[1].getSize()+0.005);
        drawLine(point(100,100),point(500,500));
        draw();
        t++;
    }
    
    
    db rand01(){
        return (db)rand()/(db)RAND_MAX;
    }
    color randColor(){
        color tmp;
        tmp.r=rand01();
        tmp.g=rand01();
        tmp.b=rand01();
        return tmp;
    }
    void glStart(){glBegin(GL_POLYGON);}
    void setColor(color c){glColor3f(c.r,c.g,c.b);}
    void onePoint(point p){glVertex2d(p.x(),p.y());}
    void drawLine(point p1,point p2){
        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(0.0,0.0,0.0);
        glVertex2d(p1.x(),p1.y());
        glVertex2d(p2.x(),p2.y());
        glEnd();
    }
    
    
    
    
    // ============================================================
    
    // void display(){}
    // void TimerFunction(int value){
    //     if(value){}
    //  glutTimerFunc(20,TimerFunction,0);
    //  glClear(GL_COLOR_BUFFER_BIT);
    //     all static al(1);
    //     al.next();
    
    //  glutSwapBuffers();
    //  // glutPostRedisplay();
    // }
    
    // int main() {
    //  srand((unsigned long)time(NULL));
    //  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    //  glutInitWindowSize(600,600);
    //  glutInitWindowPosition(0,0);
    //  glutCreateWindow("e3");
    //  // 转换坐标范围
    //  glOrtho(0,600,0,600,-15,15);
    //  glLineWidth(2);
    //  glutDisplayFunc(display);
    //  glutTimerFunc(20,TimerFunction,0);
    //  glClearColor(1.0f,1.0f,1.0f,1.0f);
    //  glutMainLoop();
    //  return 0;
    // }
    
    
}

namespace DLB{

    using namespace std;
    #define fabs(a) (a>=0?a:-a)
    #define Aabs(a) (a>=0?a:270+a)
    #define EPS 1e-5
    #define FIGITER vector<Figure*>::iterator
    #define DECITER vector<Decorating>::iterator
    #define VECITER vector<Vec>::iterator
    #define VECLSTITER initializer_list<Vec>::iterator
    #define FIGLSTITER initializer_list<Figure*>::iterator
    #define FIGDLSTITER initializer_list<Decorating>::iterator
    
    Vec::Vec(float X,float Y){ x=X; y=Y; }
    
    float Vec::GetX(){ return x; }
    
    float Vec::GetY(){ return y; }
    
    Vec Vec::operator + (Vec &a){ return Vec(x+a.GetX(),y+a.GetY()); }
    
    Vec Vec::operator - (Vec &a){ return Vec(x-a.GetX(),y-a.GetY()); }
    
    Vec Vec::operator * (float k){ return Vec(x*k,y*k); }
    
    Vec Vec::operator / (float k){ return Vec(x/k,y/k); }
    
    float Vec::operator * (Vec &a){ return x*a.GetX()+y*a.GetY(); }
    
    Vec Vec::operator ^ (Vec &a){ return Vec(x*a.GetX()-y*a.GetY(),y*a.GetX()+x*a.GetY()); }
    
    Vec Vec::operator << (float theta){
    	float tx=(float)cos(theta),ty=(float)sin(theta);
    	return Vec(tx,ty)^(*this);
    }
    
    Vec Vec::operator >> (float theta){
    	float tx=(float)cos(-theta),ty=(float)sin(theta);
    	return Vec(tx,ty)^(*this);
    }
    
    
    
    Vec Figure::GetAnchor(){ return Anchor; }
    
    void Figure::SetAnchor(Vec a){ Anchor=a; }
    
    
    
    Circle::Circle(Vec _Anchor,float _Red,float _Green,float _Blue,float _radius,int _Vertices){
    	Anchor=_Anchor;
    	R=_Red; G=_Green; B=_Blue; 
    	radius=_radius; 
        Vertices=_Vertices;
    }
    
    void Circle::Draw(){
    	float BaseX=Anchor.GetX(),BaseY=Anchor.GetY();
    	glBegin(GL_TRIANGLE_FAN);
    		glColor3f(R,G,B);
    		glVertex2f(BaseX,BaseY);
            for (int i = 0; i <= Vertices; i++)
            {
                glVertex2f(BaseX+radius*cosf(i*2.0*PI/Vertices),BaseY+radius*sinf(i*2.0*PI/Vertices));
            }	
    	glEnd();
    	
    }
    
    void Circle::Move(Vec Del){ Anchor=Anchor+Del; }
    
    void Circle::Rotate(float Theta,Vec Spin){
    	Theta*=PI/180.0;
    	Anchor=((Anchor-Spin)<<Theta)+Spin;
    }
    
    void Circle::Zoom(float K,Vec Spin){
    	Anchor=(Anchor-Spin)*K+Spin;
    	radius=radius*K;
    }
    
    Line::Line(Vec _Anchor,float _Red,float _Green,float _Blue,Vec _Del){
        Anchor=_Anchor;R=_Red;G=_Green;B=_Blue;
        Del=_Del;
    }
    
    
    
    void Line::Draw(){
        float BaseX=Anchor.GetX(),BaseY=Anchor.GetY();
        glBegin(GL_LINES);
            glColor3f(R,G,B);
            glVertex2f(BaseX,BaseY);
            glVertex2f(BaseX+Del.GetX(),BaseY+Del.GetY());
        glEnd(); 
        glBegin(GL_POINT);
            glColor3f(0.0,0.0,0.0);
            glVertex2f(BaseX,BaseY);
        glEnd(); 
    }
    
    void Line::Move(Vec Delta){
        Anchor=Anchor+Delta;
    }
    
    void Line::Rotate(float Theta,Vec Spin){
        Theta*=PI/180.0;
        Vec a_s=Anchor-Spin;
        Vec new_a_s=a_s<<Theta;
        Anchor=new_a_s+Spin;
        Del=Del<<Theta;
    }
    
    void Line::Zoom(float K,Vec Spin){
        Vec del=Anchor-Spin;
        del=del*K;
        Anchor=Spin+del;
        Del=Del*K;
    }
    
    
    
    Quad::Quad(Vec _Anchor,float _Red,float _Green,float _Blue,Vec _Del1,Vec _Del2,Vec _Del3, Vec _Del4){
        Anchor=_Anchor;
        R=_Red; G=_Green; B=_Blue; 
        Del1=_Del1; Del2=_Del2; Del3=_Del3; Del4=_Del4;
    }
    
    void Quad::Draw(){
        float BaseX=Anchor.GetX(),BaseY=Anchor.GetY();
        glBegin(GL_QUADS);
            glColor3f(R,G,B);
            glVertex3f(BaseX+Del1.GetX(),BaseY+Del1.GetY(),0.0f);
            glVertex3f(BaseX+Del2.GetX(),BaseY+Del2.GetY(),0.0f);
            glVertex3f(BaseX+Del3.GetX(),BaseY+Del3.GetY(),0.0f);
            glVertex3f(BaseX+Del4.GetX(),BaseY+Del4.GetY(),0.0f);
        glEnd(); 
    }
    
    void Quad::Move(Vec Del){ Anchor=Anchor+Del; }
    
    void Quad::Rotate(float Theta,Vec Spin){
        Theta*=PI/180.0;
        Anchor=((Anchor-Spin)<<Theta)+Spin;
        Del1=Del1<<Theta; Del2=Del2<<Theta; Del3=Del3<<Theta;Del4=Del4<<Theta;
    }
    
    void Quad::Zoom(float K,Vec Spin){
        Anchor=(Anchor-Spin)*K+Spin;
        Del1=Del1*K; Del2=Del2*K; Del3=Del3*K;Del4=Del4*K;
    }
    
    
    
    Trapezium::Trapezium(Vec _Anchor,float _Red,float _Green,float _Blue,Vec _Del1,Vec _Del2,Vec _Del3,Vec _Del4){
        Anchor=_Anchor;
        R=_Red;G=_Green;B=_Blue;
        Del1=_Del1;Del2=_Del2;Del3=_Del3;Del4=_Del4;
    }
    
    void Trapezium::Draw(){
        float BaseX=Anchor.GetX(),BaseY=Anchor.GetY();
        glBegin(GL_POLYGON);
            glColor3f(R,G,B);
            glVertex3f(BaseX+Del1.GetX(),BaseY+Del1.GetY(),0.0f);
            glVertex3f(BaseX+Del2.GetX(),BaseY+Del2.GetY(),0.0f);
            glVertex3f(BaseX+Del3.GetX(),BaseY+Del3.GetY(),0.0f);
            glVertex3f(BaseX+Del4.GetX(),BaseY+Del4.GetY(),0.0f);
        glEnd();
        glBegin(GL_POINTS);
            glColor3f(1.0,0.0,1.0);
            glVertex2f(BaseX,BaseY);
        glEnd();
    
    }
    
    void Trapezium::Move(Vec Del){ Anchor=Anchor+Del;}
    
    void Trapezium::Rotate(float Theta,Vec Spin){
        Theta*=PI/180.0;
        Vec a_s=Anchor-Spin;
        Vec new_a_s=a_s<<Theta;
        Anchor=new_a_s+Spin;
        Del1=(Del1<<Theta); Del2=(Del2<<Theta); Del3=(Del3<<Theta); Del4=(Del4<<Theta);
    }
    
    void Trapezium::Zoom(float K,Vec Spin){
        Anchor=(Anchor-Spin)*K+Spin;
        Del1=Del1*K;Del2=Del2*K;Del3=Del3*K;Del4=Del4*K;
    }
    
    
    
    Triangle::Triangle(Vec _Anchor,float _Red,float _Green,float _Blue,Vec _Del1,Vec _Del2,Vec _Del3){
        Anchor=_Anchor;
        R=_Red; G=_Green; B=_Blue; 
        Del1=_Del1; Del2=_Del2; Del3=_Del3;
    }
    
    void Triangle::Draw(){
        float BaseX=Anchor.GetX(),BaseY=Anchor.GetY();
        glBegin(GL_TRIANGLES);
            glColor3f(R,G,B);
            glVertex3f(BaseX+Del1.GetX(),BaseY+Del1.GetY(),0.0f);
            glVertex3f(BaseX+Del2.GetX(),BaseY+Del2.GetY(),0.0f);
            glVertex3f(BaseX+Del3.GetX(),BaseY+Del3.GetY(),0.0f);
        glEnd();
        glBegin(GL_POINTS);
            glColor3f(0.0,0.0,1.0);
            glVertex2f(BaseX,BaseY);
        glEnd(); 
        glBegin(GL_POINTS);
            glColor3f(1.0,0.0,0.0);
            glVertex2f(-0.2,-0.2); glVertex2f(-0.2,-0.1); glVertex2f(-0.2,0); glVertex2f(-0.2,0.1); glVertex2f(-0.2,0.2);
            glVertex2f(-0.1,-0.2); glVertex2f(-0.1,-0.1); glVertex2f(-0.1,0); glVertex2f(-0.1,0.1); glVertex2f(-0.1,0.2);
            glVertex2f(0,-0.2); glVertex2f(0,-0.1); glVertex2f(0,0); glVertex2f(0,0.1); glVertex2f(0,0.2);
            glVertex2f(0.1,-0.2); glVertex2f(0.1,-0.1); glVertex2f(0.1,0); glVertex2f(0.1,0.1); glVertex2f(0.1,0.2);
            glVertex2f(0.2,-0.2); glVertex2f(0.2,-0.1); glVertex2f(0.2,0); glVertex2f(0.2,0.1); glVertex2f(0.2,0.2);
        glEnd(); 
    }
    
    void Triangle::Move(Vec Del){ Anchor=Anchor+Del; }
    
    void Triangle::Rotate(float Theta,Vec Spin){
        Theta*=PI/180.0;
        Anchor=((Anchor-Spin)<<Theta)+Spin;
        Del1=Del1<<Theta; Del2=Del2<<Theta; Del3=Del3<<Theta;
    }
    
    void Triangle::Zoom(float K,Vec Spin){
        Anchor=(Anchor-Spin)*K+Spin;
        Del1=Del1*K; Del2=Del2*K; Del3=Del3*K;
    }
    
    
    Semicircle::Semicircle(Vec _Anchor,float _Red,float _Green,float _Blue,float _radius,int _Vertices,float _DelT){
        Anchor=_Anchor;
        R=_Red; G=_Green; B=_Blue; 
        radius=_radius; 
        Vertices=_Vertices;
        DelT=_DelT;
        
    }
    
    void Semicircle::Draw(){
        float BaseX=Anchor.GetX(),BaseY=Anchor.GetY();
        glBegin(GL_TRIANGLE_FAN);
            glColor3f(R,G,B);
            glVertex2f(BaseX,BaseY);
            for (int i = 0; i <= Vertices; i++)
            {
                glVertex2f(BaseX+radius*cosf((i*PI/Vertices)+DelT),BaseY+radius*sinf((i*PI/Vertices)+DelT));
            }   
        glEnd(); 
        
    }
    
    void Semicircle::Move(Vec Del){ Anchor=Anchor+Del;}
    
    void Semicircle::Rotate(float Theta,Vec Spin){
        Theta*=PI/180.0;
        Anchor=((Anchor-Spin)<<Theta)+Spin;
        DelT=DelT+Theta;
    }
    
    void Semicircle::Zoom(float K,Vec Spin){
        Anchor=(Anchor-Spin)*K+Spin;
        radius=radius*K;
    }
    
    
    
    Group::Group(float _PointX,float _PointY){
        SetNormal.clear(); SetDecorate.clear();
        Anchor=Vec(_PointX,_PointY);
        Track.push_back(Anchor); 
    }
    
    void Group::AddNormalFigure(initializer_list<Figure*> _FigList){
        for (FIGLSTITER it=_FigList.begin();it!=_FigList.end();it++) SetNormal.push_back((*it));
    }
    
    void Group::AddDecorateFigure(initializer_list<Decorating> _FigList){
        for (FIGDLSTITER it=_FigList.begin();it!=_FigList.end();it++) SetDecorate.push_back((*it));
    }
    
    void Group::AddTrack(initializer_list<Vec> _VecList){
        if (IsActing()){
            for (VECLSTITER it=_VecList.begin();it!=_VecList.end();it++) laterTrack.push_back((*it));
            return;
        }
        for (VECLSTITER it=_VecList.begin();it!=_VecList.end();it++) Track.push_back((*it));
    }
    
    void Group::ClearTrack(){ Track.clear(); }
    
    void Group::GetStart(bool _Final){
        if (_Final) OptLeft.ReadyLeft=1;
        if (IsActing()) return;
        NowTrack=Track.begin(); NowTrack++;
        OptMove.Switch=1; OptTurn.Switch=0;
        OptMove.Cnt=0;
        Vec _thisTmp=((*NowTrack)-Anchor);
        if (fabs(_thisTmp.GetY())>=fabs(_thisTmp.GetX())) OptMove.Cup=_thisTmp.GetY()/OptMove.CDel;
        else OptMove.Cup=_thisTmp.GetX()/OptMove.CDel;
        OptMove.Cup=fabs(OptMove.Cup);
        OptMove.Del=Vec(_thisTmp.GetX()/(float)OptMove.Cup,_thisTmp.GetY()/(float)OptMove.Cup);
    }
    
    void Group::GetLeave(){ OptLeft.Switch=1; }
    
    void Group::Draw(){
        for (FIGITER it=SetNormal.begin();it!=SetNormal.end();it++){
            (*it)->Draw();
        }
        for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
            (*it).Fig->Draw();
        }
        glFlush();
    }
    
    bool Group::IsActing(){ return OptMove.Switch|OptTurn.Switch|OptLeft.Switch; }
    
    bool Group::Act(){
        if (OptMove.Switch){
            Anchor=Anchor+OptMove.Del;
            for (FIGITER it=SetNormal.begin();it!=SetNormal.end();it++){
                (*it)->Move(OptMove.Del);
            }
            for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
                (*it).Fig->Move(OptMove.Del);
            }
            OptMove.Cnt++; 
            return 1;
        }
        if (OptTurn.Switch){
            for (FIGITER it=SetNormal.begin();it!=SetNormal.end();it++){
                (*it)->Rotate(OptTurn.Del,OptTurn.Spin);
            }
            for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
                (*it).Fig->Rotate(OptTurn.Del,OptTurn.Spin);
                (*it).Del=(*it).Del<<(OptTurn.Del*PI/180.0);
            }
            OptTurn.Theta+=fabs(OptTurn.Del);
            return 1;
        }
        if (OptLeft.Switch){
            DecorateLeave();
            return 1;
        }
        return 0;
    }
    
    bool Group::Control(){
        if (NowTrack==Track.end()){
            OptTurn.Switch=OptMove.Switch=0;
            ClearTrack();
            if (laterTrack.size()){
                Track=laterTrack; laterTrack.clear(); GetStart(0);
            }
            if (OptLeft.ReadyLeft) OptLeft.Switch=1;
            return 0;
        }
        if (OptTurn.Switch&&OptTurn.Theta>=OptTurn.Cup){
            OptTurn.Switch=0; OptMove.Switch=1; 
            OptMove.Cnt=0;
            Vec _thisTmp=((*NowTrack)-Anchor);
            while (fabs(_thisTmp.GetX())+fabs(_thisTmp.GetY())<=EPS){
                NowTrack++;
                _thisTmp=((*NowTrack)-Anchor);
            }
            if (fabs(_thisTmp.GetY())>=fabs(_thisTmp.GetX())) OptMove.Cup=_thisTmp.GetY()/OptMove.CDel;
            else OptMove.Cup=_thisTmp.GetX()/OptMove.CDel;
            OptMove.Cup=fabs(OptMove.Cup);
            OptMove.Del=Vec(_thisTmp.GetX()/(float)OptMove.Cup,_thisTmp.GetY()/(float)OptMove.Cup);
            return 1;
        }
        else if (OptMove.Switch&&OptMove.Cnt>=OptMove.Cup){
            OptMove.Switch=0; OptTurn.Switch=1; 
            float _formerDir=fabs(OptMove.Del.GetX())<=EPS?1e9:OptMove.Del.GetY()/OptMove.Del.GetX();
            OptTurn.Theta=0; OptTurn.Spin=Anchor;
            NowTrack++; if (NowTrack==Track.end()) return 0;
            float _laterDir=fabs(((*NowTrack)-Anchor).GetX())<=EPS?1e9:((*NowTrack)-Anchor).GetY()/((*NowTrack)-Anchor).GetX();
            float _thisTmp=(1+_laterDir*_formerDir);
            OptTurn.Cup=fabs(_thisTmp)<=EPS?90.0:atan((_laterDir-_formerDir)/(1+_laterDir*_formerDir))/PI*180.0;
            if (fabs(OptTurn.Cup)<=EPS){
                OptTurn.Cup=0;
                return Control();
            }
            OptTurn.Del=(OptTurn.Cup>=0?1:-1); OptTurn.Cup=fabs(OptTurn.Cup);
            return 1;
        }
        return 0;
    }
    
    bool Group::Update(){
        bool _thisFlag=0;
        _thisFlag|=Control(); DecorateControl();
        _thisFlag|=Act(); DecorateAct();
        return _thisFlag;
    }
    
    Group::~Group(){}
    
    
    
    Car::Car(float _PointX,float _PointY):Vehicle(),Group(_PointX,_PointY){
        Circle *Cir1=new Circle(Vec(-0.05,-0.04)+Anchor,1.0,0.0,0.0,0.03,100);
        Circle *Cir2=new Circle(Vec(0.05,-0.04)+Anchor,1.0,0.0,0.0,0.03,100);
        Quad *Qua1=new Quad(Anchor,0.0,1.0,0.0,Vec(0.1,0.05),Vec(0.1,-0.05),Vec(-0.1,-0.05),Vec(-0.1,0.05));
        Trapezium *Trap=new Trapezium(Vec(0.0,0.02)+Anchor,0.0,1.0,0.0,Vec(-sqrt(3)/20.0,-1.0/20.0),Vec(sqrt(3)/20.0,-1.0/20.0),Vec(1.0/20.0,sqrt(3)/20.0),Vec(-1.0/20.0,sqrt(3)/20.0));
        Quad *Qua2=new Quad(Vec(-0.07,0.08)+Anchor,0.0,0.0,1.0,Vec(0.01,0.005),Vec(0.01,-0.005),Vec(-0.01,-0.005),Vec(-0.01,0.005));
        Decorating QuaD2={Vec(0,0.005),20,0,1,Qua2};
        Quad *Qua3=new Quad(Vec(-0.085,0.07)+Anchor,0.0,0.0,1.0,Vec(0.01,0.005),Vec(0.01,-0.005),Vec(-0.01,-0.005),Vec(-0.01,0.005));
        Decorating QuaD3={Vec(0,0.004),25,0,1,Qua3};
        Quad *Qua4=new Quad(Vec(-0.10,0.08)+Anchor,0.0,0.0,1.0,Vec(0.01,0.005),Vec(0.01,-0.005),Vec(-0.01,-0.005),Vec(-0.01,0.005));
        Decorating QuaD4={Vec(0,0.006),15,0,1,Qua4};
        Quad *Qua5=new Quad(Vec(-0.115,0.07)+Anchor,0.0,0.0,1.0,Vec(0.01,0.005),Vec(0.01,-0.005),Vec(-0.01,-0.005),Vec(-0.01,0.005));
        Decorating QuaD5={Vec(0,0.003),30,0,1,Qua5};
        AddNormalFigure({Qua1,Trap,Cir1,Cir2});
        AddDecorateFigure({QuaD2,QuaD3,QuaD4,QuaD5});
    }
    
    Car *Car::GetInstance(){
        static Car *s=NULL;
        if (s==NULL) s=new Car(-1,-0.4);
        return s;
    }
    
    void Car::DeleteInstance(){
        Car *s=Car::GetInstance();
        if (s!=NULL) delete s;
        s=NULL;
    }
    
    int Car::GetType(){ return Type; }
    
    void Car::ParkIn(ArrivalTicket *T){ 
        if (ArrivalTime==-1){
            ArrivalTime=T->GetTime();
            ATicket=T;
        }
        else {
            Trash.push_back(T);
            ATicket=T;
        }
    }
    
    void Car::ChangeSlot(ChangeTicket *T){
        if (CTicket==NULL) CTicket=T;
        else {
            Trash.push_back(CTicket);
            CTicket=T;
        }
    }
    
    void Car::ParkOut(DepartTicket *T){ 
        if (DepartTime==-1){
            DepartTime=T->GetTime();
            DTicket=T;
        }
        else{
            Trash.push_back(DTicket);
            DTicket=T;
        }
    }
    
    void Car::DecorateAct(){
        for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
            it->Fig->Move(it->Del*it->Dir);
            it->Cnt++;
        }
    }
    
    void Car::DecorateControl(){
        for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
            if (it->Cnt>=it->Cup){
                it->Dir*=-1; it->Cnt=0;
            }
        }
    }
    
    void Car::DecorateLeave(){
        for (FIGITER it=SetNormal.begin();it!=SetNormal.end();it++){
            (*it)->Zoom(0.95,Anchor);
            (*it)->Rotate(5,Anchor);
        }
        for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
            (*it).Fig->Zoom(0.95,Anchor);
            (*it).Fig->Rotate(5,Anchor);
        }
    }
    
    Car::~Car(){ 
        delete ATicket; delete DTicket; if (CTicket!=NULL) delete CTicket;
        for (vector<Ticket*>::iterator it=Trash.begin();it!=Trash.end();it++){
            Ticket* tmp=(*it);
            delete tmp; 
        }
        for (FIGITER it=SetNormal.begin();it!=SetNormal.end();it++){
            Figure *_thisTmp=*it;
            delete _thisTmp;
        }
        for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
            Figure *_thisTmp=it->Fig;
            delete _thisTmp;
        }
    }
    
    
    
    Vehicle::Vehicle(){
        ArrivalTime=-1; DepartTime=-1;
        ATicket=NULL; DTicket=NULL; CTicket=NULL;
        Trash.clear();
    }
    
    int Vehicle::GetATime(){ return ArrivalTime; }
    
    int Vehicle::GetDTime(){ return DepartTime; }
    
    ArrivalTicket *Vehicle::GetATicket(){ return ATicket; }
    
    DepartTicket *Vehicle::GetDTicket(){ return DTicket; }
    
    ChangeTicket *Vehicle::GetCTicket(){ return CTicket; }
    
    Vehicle::~Vehicle(){}
    
    
    
    Ticket::Ticket(){ Time=0; }
    
    Ticket::Ticket(int T){ Time=T; }
    
    int Ticket::GetTime(){ return Time; }
    
    void Ticket::ScanType(int VT){ VecType=VT; }
    
    ArrivalTicket::ArrivalTicket(int T){ SlotNumber=-1; Time=T; }
    
    void ArrivalTicket::SetSlotNum(int SN){ SlotNumber=SN; }
    
    unsigned long ArrivalTicket::GetSlotNum(){ return (unsigned long)SlotNumber; }
    
    void ArrivalTicket::PrintTicket(){
        printf("CarType:%d ArrivalTime:%d SlotNumber:%d\n",VecType,Time,SlotNumber);
    }
    
    DepartTicket::DepartTicket(int T){ Price=-1; Time=T; }
    
    int DepartTicket::SetPrice(int AT){ return Price=(Time-AT)*10; }
    
    int DepartTicket::GetPrice(){ return Price; }
    
    void DepartTicket::PrintTicket(){
        printf("CarType:%d DuringTime:%d Price:%d\n",VecType,Price/10,Price);
    }
    
    ChangeTicket::ChangeTicket(int T){ SlotNumber1=SlotNumber2=-1; Time=T; }
    
    void ChangeTicket::SetSlotNum(int _SN1,int _SN2){ SlotNumber1=_SN1,SlotNumber2=_SN2; }
    
    int ChangeTicket::GetFirstNum(){ return SlotNumber1; }
    
    int ChangeTicket::GetSecondNum(){ return SlotNumber2; }
    
    void ChangeTicket::PrintTicket(){
        printf("CarType:%d Change Slot from %d to %d\n",VecType,SlotNumber1,SlotNumber2);
    }
    
    void TimeStep(int n){
        glutTimerFunc((unsigned int)n,TimeStep,n); 
        glutPostRedisplay();
    }
    
    void Display(){
        Group *x=Car::GetInstance();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        x->Update(); x->Draw();
    }
    
    void Start(){
        Car *x=Car::GetInstance();
        x->AddTrack({Vec(-0.8,-0.4),Vec(-0.8,0),Vec(0.5,0),Vec(0.5,0.3)});
        x->AddTrack({Vec(-0.4,0.3),Vec(-0.35,0.35),Vec(-0.3,0.4),Vec(-0.3,0.6)});
        x->GetStart(1);
    }
    
    int mymain(int argc,char *argv[]){
        srand((unsigned int)time(NULL));
        Start();
        glutInit(&argc,argv);
        glutInitWindowSize(1000,1000);
        glutInitWindowPosition(0,0);
        glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
        glutCreateWindow("Shape");
        glClearColor(1.0,1.0,1.0,0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glutDisplayFunc(Display);
        glutTimerFunc(25,TimeStep,25);
        glutMainLoop();
        Car::DeleteInstance();
        return 0;
    }
    
}

    #include <math.h>
    #ifdef __APPLE__
    #include <GLUT/glut.h>
    #elif _WIN32
    #include <GL/freeglut.h>
        #include <windows.h>
    #elif __linux__
        #include <GL/freeglut.h>
    #endif
namespace NJL{
    Shape::~Shape(){};
    Rectangle::Rectangle(Point pt1, Point pt2, float red, float green, float blue) {
        p1=pt1;p2=pt2;
        r=red;g=green;b=blue;
    }
    void Rectangle::draw() {
        glColor3f(r,g,b);glBegin(GL_QUADS);
        glVertex2d(p1.x,p1.y);glVertex2d(p2.x,p1.y);
        glVertex2d(p2.x,p2.y);glVertex2d(p1.x,p2.y);
        glEnd();
    }
    //Rectangle::~Rectangle(){};
    Triangle::Triangle(Point pt1, Point pt2, Point pt3, float red, float green, float blue) {
        p1=pt1;p2=pt2;p3=pt3;
        r=red;b=blue;g=green;
    }
    void Triangle::draw() {
        glColor3f(r,g,b);glBegin(GL_TRIANGLE_STRIP);
        glVertex2d(p1.x,p1.y);glVertex2d(p2.x,p2.y);
        glVertex2d(p3.x,p3.y);
        glEnd();
    }
    //Triangle::~Triangle(){};
    Trapezium::Trapezium(Point pt1, Point pt2, Point pt3, Point pt4, float red, float green, float blue) {
        p1=pt1;p2=pt2;p3=pt3;p4=pt4;
        r=red;g=green;b=blue;
    }
    void Trapezium::draw() {
        glColor3f(r,g,b);glBegin(GL_QUADS);
        glVertex2d(p1.x,p1.y);glVertex2d(p2.x,p2.y);
        glVertex2d(p3.x,p3.y);glVertex2d(p4.x,p4.y);
        glEnd();
    }
    //Trapezium::~Trapezium(){};
    Circle::Circle(Point pt1,double radi,float red, float green, float blue) {
        p1=pt1;radius=radi;r=red;g=green;b=blue;
    }
    void Circle::draw(){
        glColor3f(r,g,b);glBegin(GL_POLYGON);
        for(int i=0;i < 50;i++){
            glVertex2d(p1.x+radius*cos(i*2*PI/50),p1.y+radius*sin(i*2*PI/50));
        }
        glEnd();
    }
    //Circle::~Circle(){};
    car::car(Point ach) {
        anchor=ach;
        sh[0]=new Rectangle({(float)-5+anchor.x,(float)-3+anchor.y},
                            {(float)5+anchor.x,(float)-1+anchor.y},
                            (float)0.891,(float)0.6445,(float)0.3554);
        sh[1]=new Circle({(float)-3+anchor.x,(float)-3+anchor.y},(double)0.5,(float)0.891,(float)0.1,(float)0.1);
        sh[2]=new Circle({(float)3+anchor.x,(float)-3+anchor.y},(double)0.5,(float)0.891,(float)0.1,(float)0.1);
        sh[3]=new Trapezium({(float)3+anchor.x,(float)3+anchor.y},{(float)3+anchor.x,(float)-1+anchor.y},
                            {(float)-3+anchor.x,(float)-1+anchor.y},{(float)-1+anchor.x,(float)3+anchor.y},
                            (float)0.7617,(float)0.3177,(float)0.4727);
    }
    car::~car() {
        delete sh[0];
        delete sh[1];
        delete sh[2];
        delete sh[3];
    }
    
    void car::draw() {
        sh[0]->draw();
        sh[1]->draw();
        sh[2]->draw();
        sh[3]->draw();
    }
    void car::move(Point* anc) {
        anchor.x+=0.1;anc->x=anchor.x;
    }
    void TimeStep(int n) {
        glutTimerFunc((unsigned int)n, TimeStep, n);
        glutPostRedisplay();
    }
    void display() {
        Point static ach={0.0,0.0};
        car ca(ach);
        ca.move(&ach);
    /* clear window */
    /* draw scene */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        ca.draw();
        /* flush drawing routines to the window */
        glutSwapBuffers(); glFlush();
    }
    int mymain() {
    /* initialize GLUT, using any commandline parameters passed to the program */
        //glutInit();
    /* setup the size, position, and display mode for new windows */
        glutInitWindowSize(1000, 1000);
        glutInitWindowPosition(0, 0);
        glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    /* create and sset up a window */
        glutCreateWindow("hello, teapot!");
        glClearColor(1.0,1.0,1.0,0.0);
        gluOrtho2D(-30, 30, -30, 30);
        glPointSize((float)0.01);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glClear(GL_COLOR_BUFFER_BIT);
        glutDisplayFunc(display);
        glutTimerFunc(25, TimeStep, 25);
    /* tell GLUT to wait for events */
        glutMainLoop();
        return 0;
    }

}
