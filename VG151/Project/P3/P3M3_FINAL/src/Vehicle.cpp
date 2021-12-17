#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"Vehicle.h"
using namespace std;

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