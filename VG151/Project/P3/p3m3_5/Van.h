#ifndef _VAN_H_
	#define _VAN_H_

	#include<iostream>
	#include<cstdio>
	#include<cstring>
	#include<algorithm>
	#include<vector>
	#include"Vehicle.h"
	using namespace std;
	
	class Van: public Vehicle{
		private:
			const int Type=VAN;
		public:
			void ParkIn(ArrivalTicket *T);
			void ChangeSlot(ChangeTicket *T);
			void ParkOut(DepartTicket *T);
			int GetType();
			~Van();
	};

#endif	
