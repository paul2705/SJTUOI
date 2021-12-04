#ifndef _PARKLOT_H_
	#define _PARKLOT_H_

	#include<iostream>
	#include<cstdio>
	#include<cstring>
	#include<algorithm>
	#include<vector>
	#include"Slot.h"
	#include"Ticket.h"
	using namespace std;

	class Parklot{
		private:
			int Floor;
			int FloorSize[11];
			vector<Slot*> Area;
		public:
			Parklot();
			ArrivalTicket *GenerateATicket(int Time,Vehicle *Veh);
			DepartTicket *GenerateDTicket(int Time,Vehicle *Veh);
			int FindSlot();
			void InTakeVeh(int Time,Vehicle *Veh);
			void OutTakeVeh(int Time,Vehicle *Veh);
			~Parklot();
	};

#endif
