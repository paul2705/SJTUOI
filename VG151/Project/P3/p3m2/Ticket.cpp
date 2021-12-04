#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"Ticket.h"
using namespace std;

Ticket::Ticket(){ Time=0; }

Ticket::Ticket(int T){ Time=T; }

int Ticket::GetTime(){ return Time; }

void Ticket::ScanType(int VT){ VecType=VT; }

ArrivalTicket::ArrivalTicket(int T){ SlotNumber=-1; Time=T; }

void ArrivalTicket::SetSlotNum(int SN){ SlotNumber=SN; }

unsigned long ArrivalTicket::GetSlotNum(){ return (unsigned long)SlotNumber; }

void ArrivalTicket::PrintTicket(){
	printf("CarType:%d ArrivalTime:%d SlotNumber:%d\n",VecType,Time,SlotNumber);
}

DepartTicket::DepartTicket(int T){ Price=-1; Time=T; }

int DepartTicket::SetPrice(int AT){ return Price=(Time-AT)*10; }

int DepartTicket::GetPrice(){ return Price; }

void DepartTicket::PrintTicket(){
	printf("CarType:%d DuringTime:%d Price:%d\n",VecType,Price/10,Price);
}
