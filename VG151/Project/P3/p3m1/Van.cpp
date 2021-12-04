#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include"Van.h"
#include"Vehicle.h"
using namespace std;

Van::Van(){
	ArrivalTime=-1; DepartTime=-1;
	ATicket=NULL; DTicket=NULL;
}

void Van::ParkIn(ArrivalTicket *T){ 
	ArrivalTime=T->GetTime();
	ATicket=T;
}

void Van::ParkOut(DepartTicket *T){ 
	DepartTime=T->GetTime();
	DTicket=T;
}

int Van::GetType(){ return Type; }

Van::~Van(){ delete ATicket; delete DTicket; }