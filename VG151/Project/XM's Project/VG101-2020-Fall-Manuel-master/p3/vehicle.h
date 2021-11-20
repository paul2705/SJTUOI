#ifndef VEHICLE_H
#define VEHICLE_H
#include "coloredFig.h"
#include <vector>

using namespace std;

class Veh {
    protected:
        Vec anchor;
        Vec dest; 
        Vec dest_rot_cen;
        int dest_con; //0 stands for the down_row, 1 stands for the up_row, 2 stands for the right_down slot;
        int condition; //0 stands for waiting, 1 stands for entering, 2 stands for parking, 3 stands for staying still
        float direction;
        vector<Shape*> look;
        void move(Vec d_vec);
        void rotate(float angle,Vec rot_cen);
    public:
        virtual ~Veh()=0;
        Vec pos(){return anchor;}
        int judge(){return condition;}
        void set_condition();
        void set_dest(Vec t_dest);
        void calculate();
        void draw();
        void virtual changing(){}
};

class Car: public Veh {
    public:
        Car(Vec t_anchor);
        void changing();
        ~Car(){for (auto &i:look){delete i;}}
    private:
        int flag_pos;
};

class UFO: public Veh{
    public:
        UFO(Vec t_anchor);
        void changing();
        ~UFO(){for (auto &i:look){delete i;}}
};

class Rocket: public Veh{
    public:
        Rocket(Vec t_anchor);
        void changing();
        ~Rocket(){for (auto &i:look){delete i;}}
    private:
        int engine_pos;
};

#endif
