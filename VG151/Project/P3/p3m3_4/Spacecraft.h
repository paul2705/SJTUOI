/*--------------------
Author: 
Date: 
function: 
--------------------*/

#ifndef _XXX_H_
	#define _XXX_H_

	#include<iostream>
	#include<cstdio>
	#include<cstring>
	#include<algorithm>
	#include<vector>
	#include"Vehicle.h"
	#include"Group.h"
	using namespace std;
	
	class Spacecraft: public Vehicle, public Group{
		private:
			const int Type=SPACECRAFT;
			float size;
			int time,flag;
		public:
			Spacecraft(float _X,float _Y);
			static Spacecraft *GetInstance(){
				static Spacecraft *s=NULL;
				if (s==NULL) s=new Spacecraft(-1,-0.4);
				return s;
			}
			static void DeleteInstance(){
				Spacecraft *s=Spacecraft::GetInstance();
				if (s!=NULL) delete s;
				s=NULL;
			}
			void ParkIn(ArrivalTicket *T);
			void ParkOut(DepartTicket *T);
			void DecorateAct();
			void DecorateControl();
			void DecorateLeave();
			int GetType();
			~Spacecraft();
	};

#endif	
