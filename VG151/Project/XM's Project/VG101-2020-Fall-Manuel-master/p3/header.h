#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <vector>

using namespace std;
static const string digit="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
class Vehicle{
    protected:
        string type;
        int price;
        int seconds;
        string plate;
    public:
        string get_type();
        int get_price();
        int get_seconds();
        string get_plate();
        void virtual cry()=0;
        virtual ~Vehicle(){}
};

class van:public Vehicle{
    public:
        van();
        void cry();
        ~van(){}
};

class car:public Vehicle{
    public:
        car();
        void cry();
        ~car(){}
};

class motorbike:public Vehicle{
    public:
        motorbike();
        void cry();
        ~motorbike(){}
};

class bicycle:public Vehicle{
    public:
        bicycle();
        void cry();
        ~bicycle(){}
};

class Slot {
    private:
        bool empty;
        Vehicle* this_veh;
        time_t enter_time;
        time_t leave_time;
        string pos;
    public:
        Slot(char floor='Z',int seq=0);
        ~Slot();
        void leave();
        void enter(Vehicle* target);
        bool get_condition();
};

class P_area{
    private:
        vector<vector<Slot*>> head;
        vector<Vehicle*> queue;
    public:
        P_area();
        ~P_area();
        void enter(Vehicle* target);
        void leave();
        void show();
};
#endif
