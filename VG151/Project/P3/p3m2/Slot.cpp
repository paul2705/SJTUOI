#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"Slot.h"
#include"Vehicle.h"
using namespace std;

Slot::Slot(int F,int N,int SN){
	_Floor=F; _Number=N; 
	SerialNumber=SN;
	Veh=NULL;
}
			
bool Slot::Fill(Vehicle *_Veh){
	if (_Veh==NULL) return 0;
	Veh=_Veh;
	return 1;
}

Vehicle *Slot::Now(){ return Veh; }

bool Slot::Pop(){
	if (Veh==NULL) return 0;
	Veh=NULL; 
	return 1;
}

bool Slot::IsEmpty(){ return Veh==NULL; }

int Slot::SlotNumber(){ return SerialNumber; }
