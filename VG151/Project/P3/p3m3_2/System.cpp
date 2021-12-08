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
using namespace std;

System::System(){
	Time=0;
	int NVeh=rand()%100+1;
	for (int i=1;i<=NVeh;i++){
		Car* tmpItem=new Car(-1,-0.4);
		Vehicle* tmpVeh=tmpItem;
		Group* tmpGrp=tmpItem;
		WaitVehs.push({tmpVeh,tmpGrp});
	}
}

void System::AskVehIn(int Time){
	if (WaitVehs.empty()) return;
	Item tmpItem=WaitVehs.front(); WaitVehs.pop();
	Park.InTakeVeh(Time,tmpItem.thisVehicle);
	InVehs.push(tmpItem);
}

void System::AskVehOut(int Time){
	if (InVehs.empty()) return;
	Item tmpItem=InVehs.front(); InVehs.pop();
	Park.OutTakeVeh(Time,tmpItem.thisVehicle);
	OutVehs.push(tmpItem);
}

int System::TimeFlow(){ return Time+=rand()%100; }

bool System::IsEmpty(){ return WaitVehs.empty()&&InVehs.empty(); }

System::~System(){
	while (!OutVehs.empty()){
		Item tmpItem=OutVehs.front(); OutVehs.pop();
		delete tmpItem.thisVehicle;
	}
}