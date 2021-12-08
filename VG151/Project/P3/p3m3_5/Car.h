#ifndef _CAR_H_
	#define _CAR_H_

	#include<iostream>
	#include<cstdio>
	#include<cstring>
	#include<algorithm>
	#include<vector>
	#include"Vehicle.h"
	#include"Group.h"
	using namespace std;
	
	class Car: public Vehicle, public Group{
		private:
			const int Type=CAR;
		public:
			Car(float _X,float _Y);
			void ParkIn(ArrivalTicket *T);
			void ChangeSlot(ChangeTicket *T);
			void ParkOut(DepartTicket *T);
			void DecorateAct();
			void DecorateControl();
			void DecorateLeave();
			int GetType();
			~Car();
	};

#endif	
