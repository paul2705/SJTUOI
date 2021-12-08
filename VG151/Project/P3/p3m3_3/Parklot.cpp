#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include"Parklot.h"
#include"Slot.h"
#include"Ticket.h"
#include"Van.h"
#include"Vehicle.h"
#include"System.h"
#include"Car.h"
#include"Group.h"
#ifdef __APPLE__
	#include <GLUT/glut.h> 
#elif __linux__
	#include <GL/freeglut.h> 
#else
	#include <GL/freeglut.h> 
	#include <windows.h>
#endif
using namespace std;

void _Map::AddEdge(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}

void _Map::GetMap(){
	ifstream myin("Map.in");
	myin>>n>>m;
	for (int i=1;i<=n;i++){
		float x,y; myin>>x>>y;
		cout<<x<<" "<<y<<endl;
		ListPoint[i]=Vec(x,y);
	}
	for (int i=1;i<=m;i++){
		int u,v,w; myin>>u>>v>>w;
		AddEdge(u,v,w); AddEdge(v,u,w);
	}
	for (int i=1;i<=n;i++) active[i]=0;
	for (int i=n+1;i<=200;i++) active[i]=1;
	myin.close();
}

vector<Vec> _Map::FindTrack(int s,int t){
	for (int i=1;i<=200;i++) use[i]=active[i];
	for (int i=1;i<=200;i++) pre[i]=0;
	q.push(s); use[s]=1;
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (!use[v]){
				q.push(v); pre[v]=u; use[v]=1;
			}
		}
	}
	cout<<"------------TRACK---"<<s<<"<>"<<t<<"----------"<<endl;
	vector<Vec> rtmp; rtmp.clear();
	while (pre[t]){
		rtmp.push_back(ListPoint[t]);
		t=pre[t];
	}
	rtmp.push_back(ListPoint[s]);
	vector<Vec> tmp; tmp.clear();
	for (vector<Vec>::reverse_iterator it=rtmp.rbegin();it!=rtmp.rend();it++){
		tmp.push_back((*it));
		cout<<(*it).GetX()<<" "<<(*it).GetY()<<endl;
	}
	return tmp;
}

Parklot::Parklot(int _Floor,int _FloorSize){
	Floor=_Floor; Map.GetMap();
	int cnt=0;
	for (int i=1;i<=Floor;i++){
		if (_FloorSize) FloorSize[i]=_FloorSize;
		else FloorSize[i]=rand()%50+1;
		for (int j=1;j<=FloorSize[i];j++){
			Slot *tmp=new Slot(i,j,cnt++);
			Area.push_back(tmp);
		}
	}
}

ArrivalTicket *Parklot::GenerateATicket(int Time,Item _thisItem){
	ArrivalTicket *tmp=new ArrivalTicket(Time);
	int SlotSerial=FindSlot();
	if (SlotSerial==-1){ delete tmp; return NULL; }
	tmp->SetSlotNum(SlotSerial); tmp->ScanType(_thisItem.thisVehicle->GetType());
	tmp->PrintTicket();
	return tmp;
}

DepartTicket *Parklot::GenerateDTicket(int Time,Item _thisItem){
	DepartTicket *tmp=new DepartTicket(Time);
	tmp->SetPrice(_thisItem.thisVehicle->GetATime()); tmp->ScanType(_thisItem.thisVehicle->GetType());
	tmp->PrintTicket();
	return tmp;
}

int Parklot::FindSlot(){
	for (vector<Slot*>::iterator it=Area.begin();it!=Area.end();it++){
		if ((*it)->IsEmpty()) return (*it)->SlotNumber();
	}
	return -1;
}

bool Parklot::InTakeVeh(int Time,Item _thisItem){
	ArrivalTicket *tmp=GenerateATicket(Time,_thisItem);
	if (tmp==NULL) return 0;
	_thisItem.thisVehicle->ParkIn(tmp);
	vector<Vec> tmpTrack=Map.FindTrack(1,8);
	for (vector<Vec>::iterator it=tmpTrack.begin();it!=tmpTrack.end();it++){
		_thisItem.thisGroup->AddTrack({(*it)});
	}
	_thisItem.thisGroup->GetStart(0);
	Area[_thisItem.thisVehicle->GetATicket()->GetSlotNum()]->Fill(_thisItem);
	return 1;
}

bool Parklot::OutTakeVeh(int Time,Item _thisItem){
	DepartTicket *tmp=GenerateDTicket(Time,_thisItem);
	if (tmp==NULL) return 0;
	_thisItem.thisVehicle->ParkOut(tmp);
	vector<Vec> tmpTrack=Map.FindTrack(8,1);
	for (vector<Vec>::iterator it=tmpTrack.begin();it!=tmpTrack.end();it++){
		_thisItem.thisGroup->AddTrack({(*it)});
	}
	_thisItem.thisGroup->GetStart(1);
	Area[_thisItem.thisVehicle->GetATicket()->GetSlotNum()]->Pop();
	return 1;
}

void Parklot::Draw(){
	//cout<<__func__<<endl;
	for (vector<Slot*>::iterator it=Area.begin();it!=Area.end();it++){
		if (!(*it)->IsEmpty()) (*it)->Now().thisGroup->Update();
	}
	for (vector<Slot*>::iterator it=Area.begin();it!=Area.end();it++){
		if (!(*it)->IsEmpty()) (*it)->Now().thisGroup->Draw();
	}
	glFlush();
}

Parklot::~Parklot(){
	for (vector<Slot*>::iterator it=Area.begin();it!=Area.end();it++){
		delete (*it);
	}
}
