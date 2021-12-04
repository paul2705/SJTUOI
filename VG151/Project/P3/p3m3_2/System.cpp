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
using namespace std;

System::System(){
	Time=0;
	int NVeh=rand()%100+1;
	for (int i=1;i<=NVeh;i++){
		Vehicle *tmpVeh=new Car(-1,-0.4);
		WaitVehs.push(tmpVeh);
	}
}

void System::AskVehIn(int Time){
	if (WaitVehs.empty()) return;
	Vehicle *tmpVeh=WaitVehs.front(); WaitVehs.pop();
	Park.InTakeVeh(Time,tmpVeh);
	InVehs.push(tmpVeh);
}

void System::AskVehOut(int Time){
	if (InVehs.empty()) return;
	Vehicle *tmpVeh=InVehs.front(); InVehs.pop();
	Park.OutTakeVeh(Time,tmpVeh);
	OutVehs.push(tmpVeh);
}

int System::TimeFlow(){ return Time+=rand()%100; }

bool System::IsEmpty(){ return WaitVehs.empty()&&InVehs.empty(); }

System::~System(){
	while (!OutVehs.empty()){
		Vehicle *tmpVeh=OutVehs.front(); OutVehs.pop();
		delete tmpVeh;
	}
}