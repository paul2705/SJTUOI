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

Spacecraft::Spacecraft(float _X, float _Y) : Vehicle(), Group(_X, _Y)
{
	Triangle *tr1 = new Triangle(Anchor, 0.1, 0.5, 0.7, Vec(-0.1, 0.25), Vec(0, 0.25), Vec(-0.05, 0.3));
	tr1->Rotate(-90.0,Anchor);
	Quad *quad = new Quad(Anchor, 0.1, 0.1, 0.4, Vec(-0.1, -0.1), Vec(0, -0.1), Vec(0, 0.25), Vec(-0.1, 0.25));
	quad->Rotate(-90.0,Anchor);
	Quad *side1 = new Quad(Anchor, 0.2, 0.1, 0.3, Vec(-0.1, -0.1), Vec(-0.1, 0.05), Vec(-0.115, 0.05), Vec(-0.115, -0.1));
	side1->Rotate(-90.0,Anchor);
	Quad *side2 = new Quad(Anchor, 0.2, 0.1, 0.3, Vec(0, -0.1), Vec(0, 0.05), Vec(0.015, 0.05), Vec(0.015, -0.1));
	side2->Rotate(-90.0,Anchor);
	AddNormalFigure({tr1, quad, side1, side2});
}

int Spacecraft::GetType() { return Type; }

void Spacecraft::ParkIn(ArrivalTicket *T)
{
	ArrivalTime = T->GetTime();
	ATicket = T;
}

void Spacecraft::ParkOut(DepartTicket *T)
{
	DepartTime = T->GetTime();
	DTicket = T;
}

void Spacecraft::DecorateAct()
{
	// Move your own decoration
}

void Spacecraft::DecorateControl()
{
	// Control your own decoration
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
	delete ATicket;
	delete DTicket;
	for (FIGITER it=SetNormal.begin();it!=SetNormal.end();it++){
		Figure *_thisTmp=*it;
		delete _thisTmp;
	}
	for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
		Figure *_thisTmp=it->Fig;
		delete _thisTmp;
	}
}
