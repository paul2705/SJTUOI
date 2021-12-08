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
			System();
			static System *GetInstance(){
				static System *s=NULL;
				if (s==NULL) s=new System;
				return s;
			}
			static void DeleteInstance(){
				System *s=System::GetInstance();
				if (s!=NULL) delete s;
				s=NULL;
			}
			void AskVehIn(int Time);
			void AskVehOut(int Time);
			int TimeFlow();
			bool IsEmpty();
			void Control();
			~System();
	};

#endif