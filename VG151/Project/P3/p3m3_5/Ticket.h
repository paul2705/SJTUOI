#ifndef _TICKET_H_
	#define _TICKET_H_

	#include<iostream>
	#include<cstdio>
	#include<cstring>
	#include<algorithm>
	using namespace std;
	
	class Ticket{
		protected:
			int Time;
			int VecType;
		public:
			Ticket();
			Ticket(int T);
			int GetTime();
			void ScanType(int VT);
//			~Ticket();
	};

	class ArrivalTicket: public Ticket{
		private:
			int SlotNumber;
		public:
			ArrivalTicket(int T);
			void SetSlotNum(int SN);
			unsigned long GetSlotNum();
			void PrintTicket();
//			~ArrivalTicket();
	};

	class DepartTicket: public Ticket{
		private:
			int Price;
		public:
			DepartTicket(int T);
			int SetPrice(int AT);
			int GetPrice();
			void PrintTicket();
//			~DepartTicket();
	};

	class ChangeTicket: public Ticket{
		private:
			int SlotNumber1,SlotNumber2;
		public:
			ChangeTicket(int T);
			void SetSlotNum(int _SN1,int _SN2);
			int GetFirstNum();
			int GetSecondNum();
			void PrintTicket();
//			~DepartTicket();
	};

#endif
