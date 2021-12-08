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
	if (ArrivalTime==0){
		ArrivalTime=T->GetTime();
		ATicket=T;
	}
	else {
		Trash.push_back(T);
		ATicket=T;
	}
}

void Van::ChangeSlot(ChangeTicket *T){
	if (CTicket==NULL) CTicket=T;
	else {
		Trash.push_back(CTicket);
		CTicket=T;
	}
}

void Van::ParkOut(DepartTicket *T){ 
	if (DepartTime==0){
		DepartTime=T->GetTime();
		DTicket=T;
	}
	else{
		Trash.push_back(DTicket);
		DTicket=T;
	}
}

Van::~Van(){ 
	delete ATicket; delete DTicket; if (CTicket!=NULL) delete CTicket;
	for (vector<Ticket*>::iterator it=Trash.begin();it!=Trash.end();it++){
		Ticket* tmp=(*it);
		delete tmp; 
	}
}