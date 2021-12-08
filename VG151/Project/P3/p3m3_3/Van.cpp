#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include"Van.h"
#include"Vehicle.h"
using namespace std;

int Van::GetType(){ return Type; }

void Van::ParkIn(ArrivalTicket *T){ 
	ArrivalTime=T->GetTime();
	ATicket=T;
}

void Van::ParkOut(DepartTicket *T){ 
	DepartTime=T->GetTime();
	DTicket=T;
}

Van::~Van(){ delete ATicket; delete DTicket; }