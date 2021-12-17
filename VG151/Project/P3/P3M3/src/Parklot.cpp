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
#define fabs(a) (a>=0?a:-a)
#define EPS 1e-5
#define DECITER vector<Decorating>::iterator
#define FIGITER vector<Figure*>::iterator

_Map::_Map(){
	edge=0;
	memset(nex,0,sizeof(nex)); memset(head,0,sizeof(head));
	while (!q.empty()) q.pop();
	memset(use,0,sizeof(use)); memset(active,0,sizeof(active));
}
void _Map::AddEdge(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}

void _Map::GetMap(){
	ifstream myin("Map.in");
	myin>>n>>m;
	for (int i=1;i<=n;i++){
		float x,y; myin>>x>>y;
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
	}
	return tmp;
}

Parklot::Parklot(int _Floor,int _FloorSize):Group(0,0){
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
	for (int i=0;i<5;i++){
		Line *Line1=new Line(Vec(-0.4+0.2*i,-0.4),0.0,0.0,0.0,Vec(0,0.3));
		Line *Line2=new Line(Vec(-0.4+0.2*i,-0.4),0.0,0.0,0.0,Vec(0.2,0));
		AddNormalFigure({Line1,Line2});
	}
	for (int i=0;i<5;i++){
		Line *Line1=new Line(Vec(-0.4+0.2*i,0.7),0.0,0.0,0.0,Vec(0,-0.3));
		Line *Line2=new Line(Vec(-0.4+0.2*i,0.7),0.0,0.0,0.0,Vec(0.2,0));
		AddNormalFigure({Line1,Line2});
	}
	Line* Line3=new Line(Vec(0.6,-0.4),0.0,0.0,0.0,Vec(0,0.3));
	Line* Line4=new Line(Vec(0.6,0.7),0.0,0.0,0.0,Vec(0,-0.3));
	AddNormalFigure({Line3,Line4});

	Line* L=new Line(Vec(-0.6,-0.2),0.0,0.0,0.0,Vec(-0.3,0));
	Decorating LD={Vec(0,0),180,0,-0.5,L};
	AddDecorateFigure({LD});
}

ArrivalTicket *Parklot::GenerateATicket(int Time,Item _thisItem){
	ArrivalTicket *tmp=new ArrivalTicket(Time);
	int SlotSerial=FindSlot();
	if (SlotSerial==-1){ delete tmp; return NULL; }
	tmp->SetSlotNum(SlotSerial); tmp->ScanType(_thisItem.thisVehicle->GetType());
	tmp->PrintTicket();
	return tmp;
}

ChangeTicket *Parklot::GenerateCTicket(int Time,Item _thisItem){
	ChangeTicket *tmp=new ChangeTicket(Time);
	int SlotSerial=FindSlot();
	if (SlotSerial==-1){ delete tmp; return NULL; }
	int _formerSlot=-1;
	if (_thisItem.thisVehicle->GetCTicket()!=NULL) _formerSlot=_thisItem.thisVehicle->GetCTicket()->GetSecondNum();
	else _formerSlot=_thisItem.thisVehicle->GetATicket()->GetSlotNum();
	tmp->SetSlotNum(_formerSlot,SlotSerial); 
	tmp->ScanType(_thisItem.thisVehicle->GetType());
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
	vector<Vec> tmpTrack=Map.FindTrack(1,Area[_thisItem.thisVehicle->GetATicket()->GetSlotNum()]->GetPoint());
	for (vector<Vec>::iterator it=tmpTrack.begin();it!=tmpTrack.end();it++){
		_thisItem.thisGroup->AddTrack({(*it)});
	}
	_thisItem.thisGroup->GetStart(0);
	Area[_thisItem.thisVehicle->GetATicket()->GetSlotNum()]->Fill(_thisItem);
	return 1;
}

bool Parklot::ChangeSlot(int Time,Item _thisItem){
	ChangeTicket *tmp=GenerateCTicket(Time,_thisItem);
	if (tmp==NULL) return 0;
	Area[tmp->GetFirstNum()]->Pop(0);
	_thisItem.thisVehicle->ChangeSlot(tmp);
	vector<Vec> tmpTrack=Map.FindTrack(Area[tmp->GetFirstNum()]->GetPoint(),Area[tmp->GetSecondNum()]->GetPoint());
	for (vector<Vec>::iterator it=tmpTrack.begin();it!=tmpTrack.end();it++){
		_thisItem.thisGroup->AddTrack({(*it)});
	}
	_thisItem.thisGroup->GetStart(0);
	Area[tmp->GetSecondNum()]->Fill(_thisItem);
	return 1;
}

bool Parklot::OutTakeVeh(int Time,Item _thisItem){
	DepartTicket *tmp=GenerateDTicket(Time,_thisItem);
	if (tmp==NULL) return 0;
	_thisItem.thisVehicle->ParkOut(tmp);
	int _formerSlot=-1;
	if (_thisItem.thisVehicle->GetCTicket()!=NULL) _formerSlot=_thisItem.thisVehicle->GetCTicket()->GetSecondNum();
	else _formerSlot=_thisItem.thisVehicle->GetATicket()->GetSlotNum();
	vector<Vec> tmpTrack=Map.FindTrack(Area[_formerSlot]->GetPoint(),74);
	for (vector<Vec>::iterator it=tmpTrack.begin();it!=tmpTrack.end();it++){
		_thisItem.thisGroup->AddTrack({(*it)});
	}
	_thisItem.thisGroup->GetStart(1);
	Area[_formerSlot]->Pop(1);
	return 1;
}

void Parklot::Draw(bool _Change){
	static Teleported* t=NULL;
	if (t==NULL){
		t=new Teleported(-0.8,-0.15);
		t->Rotate(180,Vec(-0.8,-0.15));
	}
	t->Draw();
	if (_Change){
		for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
			if (it->Dir==0.5) it->Cnt=(it->Cup)-(it->Cnt);
			it->Dir=-0.5;
		}
	}
	Group::Update(); 
	Group::Draw();
	for (vector<Slot*>::iterator it=Area.begin();it!=Area.end();it++){
		if (!(*it)->IsEmpty()) (*it)->Now().thisGroup->Update();
		vector<Item> tmp=(*it)->GetLeaving();
		for (vector<Item>::iterator itI=tmp.begin();itI!=tmp.end();itI++){
			itI->thisGroup->Update();
		}
	}
	for (vector<Slot*>::iterator it=Area.begin();it!=Area.end();it++){
		if (!(*it)->IsEmpty()) (*it)->Now().thisGroup->Draw();
		vector<Item> tmp=(*it)->GetLeaving();
		for (vector<Item>::iterator itI=tmp.begin();itI!=tmp.end();itI++){
			itI->thisGroup->Draw();
		}
	}
	glFlush();
}

void Parklot::DecorateAct(){
	for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
		if (fabs(it->Dir)<=EPS) continue;
		it->Fig->Rotate(it->Dir,it->Fig->GetAnchor());
		it->Cnt++;
	}
}

void Parklot::DecorateControl(){
	for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
		if (it->Cnt>=it->Cup){
			it->Dir*=-1; it->Cnt=0;
			if (it->Dir==-0.5) it->Dir=0;
		}
	}
}

void Parklot::DecorateLeave(){

}

Parklot::~Parklot(){
	for (vector<Slot*>::iterator it=Area.begin();it!=Area.end();it++){
		delete (*it);
	}
	for (FIGITER it=SetNormal.begin();it!=SetNormal.end();it++){
		Figure *_thisTmp=*it;
		delete _thisTmp;
	}
	for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
		Figure *_thisTmp=it->Fig;
		delete _thisTmp;
	}
}