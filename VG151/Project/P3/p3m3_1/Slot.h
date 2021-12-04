#ifndef _SLOT_H_
	#define _SLOT_H_

	#include<iostream>
	#include<cstdio>
	#include<cstring>
	#include<algorithm>
	#include<vector>
	#include"Vehicle.h"
	using namespace std;

	class Slot{
		private:
			int _Floor,_Number;
			int SerialNumber;
			Vehicle *Veh;
		public:
			Slot(int F,int N,int SN);
			bool Fill(Vehicle *Veh);
			Vehicle *Now();
			bool Pop();
			bool IsEmpty();
			int SlotNumber();
//			~Slot();
	};

#endif
