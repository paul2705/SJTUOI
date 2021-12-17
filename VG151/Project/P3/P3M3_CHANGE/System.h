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

	class System{
		private:
			int Time,Border;
			Parklot *Park;
			queue<Item> WaitVehs;
			queue<Item> InVehs;
			queue<Item> OutVehs;
		public:
			System(int tmp);
			static System *GetInstance();
			static void DeleteInstance();
			void AskVehIn(int Time);
			void AskVehChangeSlot(int Time);
			void AskVehOut(int Time);
			int TimeFlow();
			bool IsEmpty();
			void Control();
			~System();
	};

#endif