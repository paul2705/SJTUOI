#ifndef GLUT_PARKINGLOT_H
#define GLUT_PARKINGLOT_H
#include "vehicle.h"
#include <vector>
#include <iostream>
using namespace std;

class sizes{
    private:
        sizes();
        ~sizes(){}
        int slot_num;
        float unit;
        Vec turning_1;
        Vec turning_2;
        Vec road_1;
        Vec road_2_L;
        Vec road_2_R;
        Vec road_3;
    public:
        static sizes* getInstance(){
            static sizes* s=NULL;
            if (s==NULL) s=new sizes();
            return s;
        }
        static void deleteInstance(){
            sizes* s=sizes::getInstance();
            if (s!=NULL) delete s;
            s=NULL;
        }
        Vec get_turning_1() {return turning_1;}
        Vec get_turning_2() {return turning_2;}
        Vec get_road_1() {return road_1;}
        Vec get_road_2_L() {return road_2_L;}
        Vec get_road_2_R() {return road_2_R;}
        Vec get_road_3() {return road_3;}
        float get_unit() {return unit;}
        int get_slot_num() {return slot_num;}
};

class Slot{
    private:
        Vec anchor;
        bool empty;
        int sides; //0 stands for common slot;
        vector<Shape*> look;
    public:
        Slot(Vec t_anchor);
        ~Slot(){for (auto &i:look){delete i;}};
        void draw(); //draw and change the color if the slot is reserved;
        void enter() {empty = false;}
        bool get_condition();
        Vec get_anchor() {return anchor;}
};

class ParkingLot {
    protected:
        int degree;//degree of the gate
        vector<Slot*> slots; 
        vector<Veh*> vehicles;
        vector<Shape*> outline;
        ParkingLot();
        ~ParkingLot();
    public:
        static ParkingLot* getInstance(){
            static ParkingLot *s = NULL;
            if (s==NULL) {
                s = new ParkingLot();
            }
            return s;
        }
        static void deleteInstance(){
            ParkingLot *s = ParkingLot::getInstance();
            if (s!=NULL){delete s;}
            s = NULL;
        }
        void moveDoor(); //judge whether a car should enter, then move the gate in 'outline'
        void draw(); //draw:outline and vehicles
        void moveVeh(); //judge which veh should move, and call the move function of that car;
};

#endif //GLUT_PARKINGLOT_H
