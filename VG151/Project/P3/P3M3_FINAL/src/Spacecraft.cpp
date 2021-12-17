/*--------------------
Author: 
Date: 
function: 
--------------------*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include "Spacecraft.h"
#include "Vehicle.h"
using namespace std;
#define DECITER vector<Decorating>::iterator

Spacecraft::Spacecraft(float _PointX, float _PointY) : Vehicle(), Group(_PointX, _PointY)
{
	size=flag=time=0;
	Triangle *tr1 = new Triangle(Vec(0.17, -0.05) + Anchor, 0.1, 0.5, 0.7, Vec(-0.35, 0), Vec(-0.35, 0.1), Vec(-0.4, 0.05));
	Quad *quad = new Quad(Vec(0.17, -0.05) + Anchor, 196.0 / 255, 226.0 / 255, 216.0 / 255, Vec(0, 0), Vec(0, 0.1), Vec(-0.35, 0.1), Vec(-0.35, 0));
	Quad *side1 = new Quad(Vec(0.17, -0.05) + Anchor, 96.0 / 255, 143.0 / 255, 159.0 / 255, Vec(0, 0), Vec(-0.15, 0), Vec(-0.15, -0.015), Vec(-0, -0.015));
	Quad *side2 = new Quad(Vec(0.17, -0.05) + Anchor, 96.0 / 255, 143.0 / 255, 159.0 / 255, Vec(0, 0.1), Vec(-0.15, 0.1), Vec(-0.15, 0.115), Vec(0, 0.115));
	Triangle *tr2 = new Triangle(Vec(0.17, -0.05) + Anchor, 0.5, 0.5, 0.5, Vec(-0.45, 0.05), Vec(-0.39, 0.055), Vec(-0.39, 0.045));
	Triangle *tra = new Triangle(Vec(0.17, -0.05) + Anchor, 0.1, 0.5, 0.7, Vec(-0.15, 0), Vec(-0.15, -0.015), Vec(-0.15 - (0.015) / 2, (-0.015) / 2));
	Triangle *trb = new Triangle(Vec(0.17, -0.05) + Anchor, 0.1, 0.5, 0.7, Vec(-0.15, 0.1), Vec(-0.15, 0.115), Vec(-0.15 - (0.015) / 2, (0.1 + 0.115) / 2));
	Triangle *trside1 = new Triangle(Vec(0.17, -0.05) + Anchor, 0.5, 0.5, 0.5, Vec(-0.2, -0.015 / 2), Vec(-0.15, -0.02 / 2), Vec(-0.15, -0.01 / 2));
	Triangle *trside2 = new Triangle(Vec(0.17, -0.05) + Anchor, 0.5, 0.5, 0.5, Vec(-0.2, (0.1 + 0.015 / 2)), Vec(-0.15, (0.1 + 0.02 / 2)), Vec(-0.15, (0.1 + 0.01 / 2)));
	AddNormalFigure({quad, side1, side2, tr2, trside1, trside2, tra, trb, tr1});
}

int Spacecraft::GetType() { return Type; }

void Spacecraft::ParkIn(ArrivalTicket *T){ 
	if (ArrivalTime==0){
		ArrivalTime=T->GetTime();
		ATicket=T;
	}
	else {
		Trash.push_back(T);
		ATicket=T;
	}
}

void Spacecraft::ChangeSlot(ChangeTicket *T){
	if (CTicket==NULL) CTicket=T;
	else {
		Trash.push_back(CTicket);
		CTicket=T;
	}
}

void Spacecraft::ParkOut(DepartTicket *T){ 
	if (DepartTime==0){
		DepartTime=T->GetTime();
		DTicket=T;
	}
	else{
		Trash.push_back(DTicket);
		DTicket=T;
	}
}

void Spacecraft::DecorateAct()
{
	for (FIGITER it = SetNormal.begin(); it != SetNormal.end(); it++)
	{
		(*it)->Zoom(size, Anchor);
		//(*it)->Rotate(5,Anchor);
	}
}

void Spacecraft::DecorateControl()
{
	if (size == 0)
	{
		size = 1.01;
	}
	if (flag == 0)
	{
		flag = 1;
	}
	if (flag == 1)
	{
		size = 1.01;
		if (time > 10)
		{
			flag = 2;
		}
		time += 1;
	}
	else
	{
		size = 1 / 1.01;
		if (time < -10)
		{
			flag = 1;
		}
		time -= 1;
	}
}

void Spacecraft::DecorateLeave()
{
	for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
        it->Fig->Zoom(0.95,Anchor);
        it->Fig->Rotate(5,Anchor);

    }
    for (FIGITER it=SetNormal.begin();it!=SetNormal.end();it++){
        (*it)->Zoom(0.95,Anchor);
        (*it)->Rotate(5,Anchor);
    }
}

Spacecraft::~Spacecraft()
{
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
