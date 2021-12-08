#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include"Car.h"
#include"Vehicle.h"
using namespace std;
#define DECITER vector<Decorating>::iterator
#define FIGITER vector<Figure*>::iterator

Car::Car(float _X,float _Y):Vehicle(),Group(_X,_Y){
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

int Car::GetType(){ return Type; }

void Car::ParkIn(ArrivalTicket *T){ 
	ArrivalTime=T->GetTime();
	ATicket=T;
}

void Car::ParkOut(DepartTicket *T){ 
	DepartTime=T->GetTime();
	DTicket=T;
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
	delete ATicket; delete DTicket;
	for (FIGITER it=SetNormal.begin();it!=SetNormal.end();it++){
		Figure *_thisTmp=*it;
		delete _thisTmp;
	}
	for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
		Figure *_thisTmp=it->Fig;
		delete _thisTmp;
	}
}
