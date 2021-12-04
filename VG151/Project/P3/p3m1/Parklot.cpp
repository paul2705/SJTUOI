#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include"Parklot.h"
#include"Slot.h"
#include"Ticket.h"
using namespace std;

Parklot::Parklot(){
	Floor=rand()%10+1;
	int cnt=0;
	for (int i=1;i<=Floor;i++){
		FloorSize[i]=rand()%50+1;
		for (int j=1;j<=FloorSize[i];j++){
			Slot *tmp=new Slot(i,j,cnt++);
			Area.push_back(tmp);
		}
	}
}

ArrivalTicket *Parklot::GenerateATicket(int Time,Vehicle *Vec){
	ArrivalTicket *tmp=new ArrivalTicket(Time);
	tmp->SetSlotNum(FindSlot()); tmp->ScanType(Vec->GetType());
	tmp->PrintTicket();
	return tmp;
}

DepartTicket *Parklot::GenerateDTicket(int Time,Vehicle *Vec){
	DepartTicket *tmp=new DepartTicket(Time);
	tmp->SetPrice(Vec->GetATime()); tmp->ScanType(Vec->GetType());
	tmp->PrintTicket();
	return tmp;
}

int Parklot::FindSlot(){
	for (vector<Slot*>::iterator it=Area.begin();it!=Area.end();it++){
		if ((*it)->IsEmpty()) return (*it)->SlotNumber();
	}
	return -1;
}

void Parklot::InTakeVeh(int Time,Vehicle *Veh){
	Veh->ParkIn(GenerateATicket(Time,Veh));
	Area[Veh->GetATicket()->GetSlotNum()]->Fill(Veh);
}

void Parklot::OutTakeVeh(int Time,Vehicle *Veh){
	Veh->ParkOut(GenerateDTicket(Time,Veh));
	Area[Veh->GetATicket()->GetSlotNum()]->Pop();
}

Parklot::~Parklot(){
	for (vector<Slot*>::iterator it=Area.begin();it!=Area.end();it++){
		delete (*it);
	}
}
