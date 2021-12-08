#ifndef _SYSTEM_H_
	#define _SYSTEM_H_

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

	#include"Group.h"

	#include"System.h"
	using namespace std;
	typedef struct _Item{
		Vehicle* thisVehicle;
		Group* thisGroup;
	} Item;

	class System{
		private:
			int Time;
			Parklot Park;
			queue<Item> WaitVehs;
			queue<Item> InVehs;
			queue<Item> OutVehs;
		public:
			System();
			void AskVehIn(int Time);
			void AskVehOut(int Time);
			int TimeFlow();
			bool IsEmpty();
			~System();
	};

#endif