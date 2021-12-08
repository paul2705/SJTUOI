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
	thisItem.thisVehicle=NULL;
	thisItem.thisGroup=NULL;
}
			
bool Slot::Fill(Item _thisItem){
	if (!IsEmpty()) return 0;
	thisItem=_thisItem;
	return 1;
}

Item Slot::Now(){ return thisItem; }

bool Slot::Pop(){
	if (!IsEmpty()) return 0;
	thisItem.thisVehicle=NULL;
	thisItem.thisGroup=NULL;
	return 1;
}

bool Slot::IsEmpty(){ return thisItem.thisVehicle==NULL; }

int Slot::SlotNumber(){ return SerialNumber; }
