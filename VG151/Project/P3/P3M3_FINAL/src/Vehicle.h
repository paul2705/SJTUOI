#ifndef _VEHICLE_H_
	#define _VEHICLE_H_

	#include<iostream>
	#include<cstdio>
	#include<cstring>
	#include<algorithm>
	#include<vector>
	#include"Ticket.h"
	#define CAR 1
	#define UFO 2
	#define SPACECRAFT 3
	#define TELEPORTED 4
	#define VAN 5
	using namespace std;
	

	class Vehicle{
		protected:
			int ArrivalTime,DepartTime;
			ArrivalTicket *ATicket;
			DepartTicket *DTicket;
			ChangeTicket *CTicket;
			vector<Ticket*> Trash;
		public:
			Vehicle();
			virtual void ParkIn(ArrivalTicket *T)=0;
			virtual void ChangeSlot(ChangeTicket *T)=0;
			virtual void ParkOut(DepartTicket *T)=0;
			ArrivalTicket *GetATicket();
			DepartTicket *GetDTicket();
			ChangeTicket *GetCTicket();
			int GetATime();
			int GetDTime();
			virtual int GetType()=0;
			virtual ~Vehicle();
	};

#endif
