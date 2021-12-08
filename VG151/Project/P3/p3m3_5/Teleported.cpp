#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include"Teleported.h"
#include"Vehicle.h"
#include "Line.h"
using namespace std;
#define DECITER vector<Decorating>::iterator
#define FIGITER vector<Figure*>::iterator

Teleported::Teleported(float _X,float _Y):Vehicle(),Group(_X,_Y){
    Quad *Qua1=new Quad(Anchor,1.0,0.0,0.0,Vec(0.05,0.1),Vec(0.05,-0.15),Vec(-0.05,-0.15),Vec(-0.05,0.1));
    Line *Line1=new Line(Vec(0,0.05)+Anchor,0.0,0.0,1.0,Vec(-0.05,0.05));
    Decorating LinE1={Vec(0,0.005),10,0,-1,Line1};
    Line *Line2=new Line(Vec(0,0.05)+Anchor,0.0,0.0,1.0,Vec(0.05,0.05));
    Decorating LinE2={Vec(0,0.005),10,0,-1,Line2};
    Line *Line3=new Line(Anchor,0.0,0.0,1.0,Vec(-0.05,0.05));
    Decorating LinE3={Vec(0,0.005),10,0,-1,Line3};
    Line *Line4=new Line(Anchor,0.0,0.0,1.0,Vec(0.05,0.05));
    Decorating LinE4={Vec(0,0.005),10,0,-1,Line4};
    Line *Line5=new Line(Vec(0,-0.05)+Anchor,0.0,0.0,1.0,Vec(-0.05,0.05));
    Decorating LinE5={Vec(0,0.005),10,0,-1,Line5};
    Line *Line6=new Line(Vec(0,-0.05)+Anchor,0.0,0.0,1.0,Vec(0.05,0.05));
    Decorating LinE6={Vec(0,0.005),10,0,-1,Line6};
    Line *Line7=new Line(Vec(0,-0.1)+Anchor,0.0,0.0,1.0,Vec(-0.05,0.05));
    Decorating LinE7={Vec(0,0.005),10,0,-1,Line7};
    Line *Line8=new Line(Vec(0,-0.1)+Anchor,0.0,0.0,1.0,Vec(0.05,0.05));
    Decorating LinE8={Vec(0,0.005),10,0,-1,Line8};
    AddNormalFigure({Qua1});
    AddDecorateFigure({LinE1,LinE2,LinE3,LinE4,LinE5,LinE6,LinE7,LinE8});
}

int Teleported::GetType(){return Type;}

void Teleported::ParkIn(ArrivalTicket *T){ 
    if (ArrivalTime==0){
        ArrivalTime=T->GetTime();
        ATicket=T;
    }
    else {
        Trash.push_back(T);
        ATicket=T;
    }
}

void Teleported::ChangeSlot(ChangeTicket *T){
    if (CTicket==NULL) CTicket=T;
    else {
        Trash.push_back(CTicket);
        CTicket=T;
    }
}

void Teleported::ParkOut(DepartTicket *T){ 
    if (DepartTime==0){
        DepartTime=T->GetTime();
        DTicket=T;
    }
    else{
        Trash.push_back(DTicket);
        DTicket=T;
    }
}

void Teleported::DecorateLeave(){
    for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
        it->Fig->Zoom(0.95,Anchor);
        it->Fig->Rotate(5,Anchor);

    }
    for (FIGITER it=SetNormal.begin();it!=SetNormal.end();it++){
        (*it)->Zoom(0.95,Anchor);
        (*it)->Rotate(5,Anchor);
    }
}

void Teleported::DecorateAct(){
    for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
        it->Fig->Move(it->Del*it->Dir);
        it->Cnt++;
    }
}

void Teleported::DecorateControl(){
    for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
        if (it->Cnt>=it->Cup){
            it->Dir*=-1; it->Cnt=0;
        }
    }
}

Teleported::~Teleported(){ 
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