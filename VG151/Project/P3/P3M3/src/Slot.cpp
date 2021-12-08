#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"Slot.h"
#include"Vehicle.h"
using namespace std;

Slot::Slot(int F,int N,int SN){
	_Floor=F; _Number=N; Leaving.clear();
	SerialNumber=SN;
	if (SN==0) SerialPoint=8;
	else SerialPoint=39+(SN-1)*4;
	thisItem.thisVehicle=NULL;
	thisItem.thisGroup=NULL;
}

int Slot::GetPoint(){ return SerialPoint; }

vector<Item> Slot::GetLeaving(){ return Leaving; }
			
bool Slot::Fill(Item _thisItem){
	if (!IsEmpty()) return 0;
	thisItem=_thisItem;
	return 1;
}

Item Slot::Now(){ return thisItem; }

bool Slot::Pop(int _Flag){
	if (IsEmpty()) return 0;
	if (_Flag) Leaving.push_back(thisItem);
	thisItem.thisVehicle=NULL;
	thisItem.thisGroup=NULL;
	return 1;
}

bool Slot::IsEmpty(){ return thisItem.thisVehicle==NULL; }

int Slot::SlotNumber(){ return SerialNumber; }
