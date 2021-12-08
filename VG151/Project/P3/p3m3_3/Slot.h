#ifndef _SLOT_H_
	#define _SLOT_H_

	#include<iostream>
	#include<cstdio>
	#include<cstring>
	#include<algorithm>
	#include<vector>
	#include"Vehicle.h"
	#include"Group.h"
	using namespace std;
	typedef struct _Item{
		Vehicle* thisVehicle;
		Group* thisGroup;
	} Item;

	class Slot{
		private:
			int _Floor,_Number;
			int SerialNumber;
			Item thisItem;
		public:
			Slot(int F,int N,int SN);
			bool Fill(Item _thisItem);
			Item Now();
			bool Pop();
			bool IsEmpty();
			int SlotNumber();
//			~Slot();
	};

#endif
