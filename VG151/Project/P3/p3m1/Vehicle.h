#ifndef _VEHICLE_H_
	#define _VEHICLE_H_

	#include<iostream>
	#include<cstdio>
	#include<cstring>
	#include<algorithm>
	#include<vector>
	#include"Ticket.h"
	#define VAN 1
	#define CAR 2
	#define MOTORBIKE 3
	#define BICYCLE 4
	using namespace std;
	

	class Vehicle{
		protected:
			int ArrivalTime,DepartTime;
			ArrivalTicket *ATicket;
			DepartTicket *DTicket;
		public:
			Vehicle();
			virtual void ParkIn(ArrivalTicket *T)=0;
			virtual void ParkOut(DepartTicket *T)=0;
			ArrivalTicket *GetATicket();
			DepartTicket *GetDTicket();
			int GetATime();
			int GetDTime();
			virtual int GetType()=0;
			virtual ~Vehicle();
	};

#endif
