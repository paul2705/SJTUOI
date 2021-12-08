#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include"UFO.h"
#include"Vehicle.h"
using namespace std;
#define DECITER vector<Decorating>::iterator
Ufo::Ufo(float X,float _Y):Vehicle(),Group(X,_Y){
	
	Semicircle *Semicir1 =new Semicircle(Vec(0.0,0.0)+Anchor,110.0/255,231.0/255,183.0/255,0.1,100,0.0);
	Trapezium *Trap1=new Trapezium(Vec(0.05,-0.02)+Anchor,2.0,1.5,0.0,Vec(-sqrt(3)/40.0,-1.0/40.0),Vec(sqrt(3)/40.0,-1.0/40.0),Vec(1.0/100.0,sqrt(3)/100.0),Vec(-1.0/100.0,sqrt(3)/100.0));
	Trapezium *Trap2=new Trapezium(Vec(-0.05,-0.02)+Anchor,2.0,1.5,0.0,Vec(-sqrt(3)/40.0,-1.0/40.0),Vec(sqrt(3)/40.0,-1.0/40.0),Vec(1.0/100.0,sqrt(3)/100.0),Vec(-1.0/100.0,sqrt(3)/100.0));
	Circle *Cir1=new Circle(Vec(-0.07,0.03)+Anchor,0.0,2.0,1.0,0.02,100);
	Circle *Cir2=new Circle(Vec(0.0,0.03)+Anchor,0.0,2.0,1.0,0.02,100);
	Circle *Cir3=new Circle(Vec(0.07,0.03)+Anchor,0.0,2.0,1.0,0.02,100);
	AddNormalFigure({Trap1,Trap2,Semicir1,Cir1,Cir2,Cir3});
	
}

int Ufo::GetType(){ return Type; }

void Ufo::ParkIn(ArrivalTicket *T){ 
	if (ArrivalTime==0){
		ArrivalTime=T->GetTime();
		ATicket=T;
	}
	else {
		Trash.push_back(T);
		ATicket=T;
	}
}

void Ufo::ChangeSlot(ChangeTicket *T){
	if (CTicket==NULL) CTicket=T;
	else {
		Trash.push_back(CTicket);
		CTicket=T;
	}
}

void Ufo::ParkOut(DepartTicket *T){ 
	if (DepartTime==0){
		DepartTime=T->GetTime();
		DTicket=T;
	}
	else{
		Trash.push_back(DTicket);
		DTicket=T;
	}
}

void Ufo::DecorateAct(){
	/*for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
		it->Fig->Move(it->Del*it->Dir);
		it->Cnt++;
	}*/
}

void Ufo::DecorateControl(){
	/*for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
		if (it->Cnt>=it->Cup){
			it->Dir*=-1; it->Cnt=0;
		}
	}*/
}

void Ufo::DecorateLeave(){
	for (FIGITER it=SetNormal.begin();it!=SetNormal.end();it++){
		(*it)->Zoom(0.95,Anchor);
		(*it)->Rotate(5,Anchor);
	}
	for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
		(*it).Fig->Zoom(0.95,Anchor);
		(*it).Fig->Rotate(5,Anchor);
	}
}

Ufo::~Ufo(){ 
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