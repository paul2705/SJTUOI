#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include"Parklot.h"
#include"Slot.h"
#include"Ticket.h"
#include"Van.h"
#include"Vehicle.h"
#include"System.h"
#include"Car.h"
#include"Group.h"
#include"Teleported.h"
#include"Spacecraft.h"
#include"UFO.h"
using namespace std;

System *System::GetInstance(){
	static System *s=NULL;
	if (s==NULL) s=new System;
	return s;
}

void System::DeleteInstance(){
	System *s=System::GetInstance();
	if (s!=NULL) delete s;
	s=NULL;
}

System::System(){
	Time=Border=0;
	Park=new Parklot(1,10);
	int NVeh=rand()%100+1;
	for (int i=1;i<=NVeh;i++){
		int tmpRand=rand()%3;
		if (tmpRand==0){
			Car *tmpItem=new Car(-1,-0.4);
			Vehicle* tmpVeh=tmpItem;
			Group* tmpGrp=tmpItem;
			WaitVehs.push({tmpVeh,tmpGrp});
		}
		else if (tmpRand==1){
			Spacecraft *tmpItem=new Spacecraft(-1,-0.4);
			Vehicle* tmpVeh=tmpItem;
			Group* tmpGrp=tmpItem;
			WaitVehs.push({tmpVeh,tmpGrp});
		}
		else if (tmpRand==2){
			Ufo *tmpItem=new Ufo(-1,-0.4);
			Vehicle* tmpVeh=tmpItem;
			Group* tmpGrp=tmpItem;
			WaitVehs.push({tmpVeh,tmpGrp});
		}
	}
}

void System::AskVehIn(int Time){
	if (WaitVehs.empty()) return;
	Item tmpItem=WaitVehs.front(); WaitVehs.pop();
	if (Park->InTakeVeh(Time,tmpItem)) InVehs.push(tmpItem);
	else OutVehs.push(tmpItem);
}

void System::AskVehChangeSlot(int Time){
	if (InVehs.empty()) return;
	Item tmpItem=InVehs.front(); InVehs.pop();
	Park->ChangeSlot(Time,tmpItem);
	InVehs.push(tmpItem);
}

void System::AskVehOut(int Time){
	if (InVehs.empty()) return;
	Item tmpItem=InVehs.front(); InVehs.pop();
	Park->OutTakeVeh(Time,tmpItem);
	OutVehs.push(tmpItem);
}

int System::TimeFlow(){ return Border+=rand()%1000; }

bool System::IsEmpty(){ return WaitVehs.empty()&&InVehs.empty(); }

void System::Control(){
	if (Time>=Border&&!IsEmpty()){
		int opt=rand()%10;
		if (opt<4)
			if (!WaitVehs.empty()) AskVehIn(TimeFlow()),Park->Draw(1);
			else AskVehOut(TimeFlow()),Park->Draw(0);
		else if (opt<7)
			if (!InVehs.empty()) AskVehOut(TimeFlow()),Park->Draw(0);
			else AskVehIn(TimeFlow()),Park->Draw(1);
		else if (!InVehs.empty()) AskVehChangeSlot(TimeFlow()),Park->Draw(0);
			else AskVehIn(TimeFlow()),Park->Draw(1);
	}
	Time++; Park->Draw(0);
}

System::~System(){
	while (!OutVehs.empty()){
		Item tmpItem=OutVehs.front(); OutVehs.pop();
		delete tmpItem.thisVehicle;
	}
	delete Park;
}