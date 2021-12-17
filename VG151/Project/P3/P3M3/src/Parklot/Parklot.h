#ifndef _PARKLOT_H_
	#define _PARKLOT_H_

	#include<iostream>
	#include<cstdio>
	#include<cstring>
	#include<algorithm>
	#include<vector>
	#include<queue>
	#include"Slot.h"
	#include"Ticket.h"
	#include"Van.h"
	#include"Vehicle.h"
	#include"Car.h"
	#include"Group.h"
	#include"Figure.h"
	#include "Teleported.h"
	using namespace std;

	class _Map{
		private:
			Vec ListPoint[205];
			int n,m;
			int edge=0,head[205],nex[205],tail[205],w[205];
			int use[205],active[205],pre[205];
			queue<int> q;
			void AddEdge(int u,int v,int W);
		public:
			_Map();
			void GetMap();
			vector<Vec> FindTrack(int s,int t);
	};

	class Parklot{
		private:
			int Floor;
			int FloorSize[11];
			vector<Slot*> Area;
			_Map Map;
		public:
			Parklot(int _Floor,int _FloorSize=0);
			ArrivalTicket *GenerateATicket(int Time,Item _thisItem);
			ChangeTicket *GenerateCTicket(int Time,Item _thisItem);
			DepartTicket *GenerateDTicket(int Time,Item _thisItem);
			int FindSlot();
			bool InTakeVeh(int Time,Item _thisItem);
			bool ChangeSlot(int Time,Item _thisItem);
			bool OutTakeVeh(int Time,Item _thisItem);
			void Draw();

			void Drawslots();
			void DrawDoor();
			void DrawTele();
			
			~Parklot();
	};

#endif
