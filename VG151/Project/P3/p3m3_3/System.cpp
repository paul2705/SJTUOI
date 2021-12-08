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
using namespace std;

System::System(){
	Time=Border=0;
	Park=new Parklot(1);
	int NVeh=rand()%100+1;
	for (int i=1;i<=NVeh;i++){
		int tmpRand=rand()%3;
		if (tmpRand==0){
			Teleported *tmpItem=new Teleported(-1,-0.4);
			Vehicle* tmpVeh=tmpItem;
			Group* tmpGrp=tmpItem;
			WaitVehs.push({tmpVeh,tmpGrp});
		}
		else if (tmpRand==1){
			Car *tmpItem=new Car(-1,-0.4);
			Vehicle* tmpVeh=tmpItem;
			Group* tmpGrp=tmpItem;
			WaitVehs.push({tmpVeh,tmpGrp});
		}
		else if (tmpRand==2){
			Spacecraft *tmpItem=new Spacecraft(-1,-0.4);
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

void System::AskVehOut(int Time){
	if (InVehs.empty()) return;
	Item tmpItem=InVehs.front(); InVehs.pop();
	Park->OutTakeVeh(Time,tmpItem);
	OutVehs.push(tmpItem);
}

int System::TimeFlow(){ return Border+=rand()%100; }

bool System::IsEmpty(){ return WaitVehs.empty()&&InVehs.empty(); }

void System::Control(){
	if (Time>=Border&&!IsEmpty()){
		int opt=rand()%5;
		if (opt<3)
			if (!WaitVehs.empty()) AskVehIn(TimeFlow());
			else AskVehOut(TimeFlow());
		else if (!InVehs.empty()) AskVehOut(TimeFlow());
			else AskVehIn(TimeFlow());
	}
	Time++;
	Park->Draw();
}

System::~System(){
	while (!OutVehs.empty()){
		Item tmpItem=OutVehs.front(); OutVehs.pop();
		delete tmpItem.thisVehicle;
	}
	delete Park;
}