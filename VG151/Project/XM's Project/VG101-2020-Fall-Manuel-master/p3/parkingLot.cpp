#include "parkingLot.h"
#include <iostream>
using namespace std;

sizes::sizes(){
    int num;
    cout<<"input an even slots number larger than 10:";
    cin>>num;
    slot_num = num;
    unit = 2.0f/((float)num/2.0f+3.0f);
    turning_1 = Vec(-1.0f+1.5f*unit,-1.0f+3.5f*unit);
    turning_2 = Vec(-1.0f+(1.5f+(float)num/2.0f)*unit,-1.0f+5.25f*unit);
    road_1 = Vec(-1.0f+0.75f*unit,-1.0f+3.5f*unit);
    road_2_L = Vec(-1.0f+1.5f*unit,-1.0f+4.25f*unit);
    road_2_R = Vec(-1.0f+((float)num/2.0f+1.5f)*unit,-1.0f+4.25f*unit);
    road_3 = Vec(-1.0f+((float)num/2.0f+1.5f)*unit,-1.0f+6.25f*unit);
}

Slot::Slot(Vec t_anchor){
    sizes* s=sizes::getInstance();
    float unit = s->get_unit();
    anchor = t_anchor;
    float width = unit,length = 1.5f*unit;
    if(t_anchor.getY()<(s->get_turning_2()).getY()){
        Line* line1 = new Line(anchor,{-width/2,length/2},{-width/2,-length/2},1,1);
        Line* line2 = new Line(anchor,{-width/2,-length/2},{width/2,-length/2},1,1);
        Line* line3 = new Line(anchor,{width/2,-length/2},{width/2,length/2},3,1);
        look.push_back(line1);
        look.push_back(line2);
        look.push_back(line3);
    }
    else{
        Line* line1 = new Line(anchor,{-width/2,-length/2},{-width/2,length/2},1,1);
        Line* line2 = new Line(anchor,{-width/2,length/2},{width/2,length/2},1,1);
        Line* line3 = new Line(anchor,{width/2,length/2},{width/2,-length/2},3,1);
        look.push_back(line1);
        look.push_back(line2);
        look.push_back(line3);
    }
    if (rand()%6==0){
        sides = 500;
        Polygon* changing_poly=new Polygon(anchor,unit*0.4f,360,5,0);
        changing_poly->paint();
        look.push_back(changing_poly);
    }
    else{
        sides = 0;
    }
    empty=true;
}

bool Slot::get_condition(){
    if (sides==0){
        return empty;
    }
    else {
        return false;
    }
}

void Slot::draw(){
    static int flag=0;
    if (sides){
        if (flag==0&&sides<1000){
            sides++;
        }
        else if(sides>500){
            flag=1;
            sides--;
        }
        else{
            flag=0;
        }
        ((Polygon*)look.back())->change_size(sides/100);
        if (sides%100==0){
            look.back()->paint();
        }
    }
    for (auto i:look){
        i->draw();
    }
}

ParkingLot::ParkingLot() {
    sizes* s = sizes::getInstance();
    float unit = s->get_unit();
    int size = s->get_slot_num();
    degree = 0; float width = unit; //initialize the slots
    Vec temp_cen = {-1.0f+2.0f*unit,-1.0f+2.75f*unit}; Vec temp_d = {width,0};
    for (int i = 1; i <= size/2; i++){
        Slot* new_slot = new Slot(temp_cen);
        slots.push_back(new_slot);
        temp_cen = temp_cen + temp_d;
    } //construct the low slots
    temp_cen = {-1.0f+(float)(1+size/2)*unit,-1.0f+7.75f*unit}; temp_d = {-width,0};
    for (int i = 1; i <= size/2; i++){
        Slot* new_slot=new Slot(temp_cen);
        slots.push_back(new_slot);
        temp_cen=temp_cen+temp_d;
    } //construct the high slots
    for (int i=1; i <= size; i++){
        switch(rand()%3){
            case 0:{
                Car* new_car = new Car({-1.0f+0.75f*unit,-1.0f+0.75f*unit});
                vehicles.push_back(new_car); break;
            }
            case 1:{
                UFO* new_ufo = new UFO({-1.0f+0.75f*unit,-1.0f+0.75f*unit});
                vehicles.push_back(new_ufo); break;
            }
            case 2:{
                Rocket* new_rocket = new Rocket({-1.0f+0.75f*unit,-1.0f+0.75f*unit});
                vehicles.push_back(new_rocket); break;
            }
        } //initialize the vehicles
    } //draw the outline of the parking_lot, and put the gate line at the last place
    Line* Left = new Line({-1,-1},{0,1.5f*unit},{0,8.5f*unit},0,2,0,0,0);outline.push_back(Left);
    Line* Up = new Line({-1,-1},{0,8.5f*unit},{(float)(3+size/2)*unit,8.5f*unit},0,2,0,0,0);outline.push_back(Up);
    Line* Right = new Line({-1,-1},{(float)(3+size/2)*unit,8.5f*unit},{(float)(3+size/2)*unit,2*unit},0,2,0,0,0);outline.push_back(Right);
    Line* Down = new Line({-1,-1},{(float)(3+size/2)*unit,2.0f*unit},{1.5f*unit,2.0f*unit},0,2,0,0,0);outline.push_back(Down);
    Line* Middle = new Line({-1,-1},{1.5f*unit,5.25f*unit},{(1.5f+(float)size/2)*unit,5.25f*unit},0,3,0,0,0);outline.push_back(Middle);
    Line* Gate_1 = new Line({-1,-1},{1.5f*unit,1.5f*unit},{1.5f*unit,2.0f*unit},0,2,0,0,0);outline.push_back(Gate_1);
    Line* Gate = new Line({-1,-1},{0.2f*unit,1.5f*unit},{1.5f*unit,1.5f*unit},0,2,1,0,0);outline.push_back(Gate);
}

void ParkingLot::draw(){
    for (auto i:outline){
        i->draw();
    }
    for (auto i:vehicles){
        if (i->judge()!=0){
            i->draw();
        }
    }
    for (auto i:vehicles){
        if (i->judge()==0){
            i->draw();
            break;
        }
    }
    for (auto i:slots){
        i->draw();
    }
}

void ParkingLot::moveVeh(){
    for(auto &i:vehicles){
        i->changing();
    }
    for (auto &i:vehicles){
        if (i->judge()==1||i->judge()==2){
            i->calculate();
            return;
        }
    }
    for (auto &i:vehicles){
        if (i->judge()==0&&degree==90){
            for (auto &j:slots){
                if (j->get_condition()){
                    i->set_dest(j->get_anchor());
                    j->enter();
                    break;
                }
            }
            break;
        }
    }
}

void ParkingLot::moveDoor(){
    sizes* s=sizes::getInstance();
    float unit=s->get_unit();
    static int flag=1;//0 for closing, 1 for closed, 2 for opening, 3 for open
    if (flag==0){
        if (degree>0){
            outline.back()->rotate(-1,{-1.0f+1.5f*unit,-1.0f+1.5f*unit});
            degree--;
        }
        else {
            flag=1;
        }
    }
    else if(flag==2){
        if(degree<90){
            outline.back()->rotate(1,{-1.0f+1.5f*unit,-1.0f+1.5f*unit});
            degree++;
        }
        else {
            flag=3;
        }
    }
    else if(flag==1){
        for (auto i:vehicles){
            if (i->judge()==1||i->judge()==2){
                return;
            }
        }
        for (auto i:slots){
            if (i->get_condition()){
                flag=2;
                break;
            }
        }
    }
    else {
        for (auto i:vehicles){
            if ((i->judge())==1&&(i->pos()).getY()>-1+3*unit){
                flag=0;
                break;
            }
        }
    }
}

ParkingLot::~ParkingLot(){
    for (auto &i:vehicles){
        delete i;
    }
    for (auto &i:slots){
        delete i;
    }
    for (auto &i:outline){
        delete i;
    }
}
