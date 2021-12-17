/*--------------------
Author: Chen Dong Hao
Date: 2021.12.05
function: Class Of UFO
--------------------*/

#ifndef _UFO_H_
	#define _UFO_H_
	#include<iostream>
	#include<cstdio>
	#include<cstring>
	#include<algorithm>
	#include<vector>
	#include"Vehicle.h"
	#include"Group.h"
	using namespace std;
	
	class Ufo: public Vehicle, public Group{
		private:
			const int Type=UFO;
		public:
			Ufo(float X,float _PointY);
			void ParkIn(ArrivalTicket *T);
			void ChangeSlot(ChangeTicket *T);
			void ParkOut(DepartTicket *T);
			void DecorateAct();
			void DecorateControl();
			void DecorateLeave();
			int GetType();
			~Ufo();
	};

#endif	