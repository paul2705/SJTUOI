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
			static Car *GetInstance(){
				static Car *s=NULL;
				if (s==NULL) s=new Car(-1,-0.4);
				return s;
			}
			static void DeleteInstance(){
				Car *s=Car::GetInstance();
				if (s!=NULL) delete s;
				s=NULL;
			}
			void ParkIn(ArrivalTicket *T);
			void ParkOut(DepartTicket *T);
			void DecorateAct();
			void DecorateControl();
			int GetType();
			~Car();
	};

#endif	
