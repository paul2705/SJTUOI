#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<initializer_list>
#include"Figure.h"
#include"Triangle.h"
#include"Trapezium.h"
#include"Quad.h"
#include"Circle.h"
#include"Line.h"
#include"Semicircle.h"
#include"Group.h"
#ifdef __APPLE__
	#include <GLUT/glut.h> 
#elif __linux__
	#include <GL/freeglut.h> 
#else
	#include <GL/freeglut.h> 
	#include <windows.h>
#endif
#define PI acos(-1)
#define fabs(a) (a>=0?a:-a)
#define Aabs(a) (a>=0?a:270+a)
#define EPS 1e-5
#define FIGITER vector<Figure*>::iterator
#define DECITER vector<Decorating>::iterator
#define VECITER vector<Vec>::iterator
#define VECLSTITER initializer_list<Vec>::iterator
#define FIGLSTITER initializer_list<Figure*>::iterator
#define FIGDLSTITER initializer_list<Decorating>::iterator
using namespace std;

Group::Group(float _X,float _Y){
	SetNormal.clear(); SetDecorate.clear();
	Anchor=Vec(_X,_Y);
	Track.push_back(Anchor); 
}

void Group::AddNormalFigure(initializer_list<Figure*> _FigList){
	for (FIGLSTITER it=_FigList.begin();it!=_FigList.end();it++) SetNormal.push_back((*it));
}

void Group::AddDecorateFigure(initializer_list<Decorating> _FigList){
	for (FIGDLSTITER it=_FigList.begin();it!=_FigList.end();it++) SetDecorate.push_back((*it));
}

void Group::AddTrack(initializer_list<Vec> _VecList){
	if (IsActing()){
		for (VECLSTITER it=_VecList.begin();it!=_VecList.end();it++) laterTrack.push_back((*it));
		return;
	}
	for (VECLSTITER it=_VecList.begin();it!=_VecList.end();it++) Track.push_back((*it));
}

void Group::ClearTrack(){ Track.clear(); }

void Group::GetStart(bool _Final){
	if (_Final) OptLeft.ReadyLeft=1;
	if (IsActing()) return;
	NowTrack=Track.begin(); NowTrack++;
	OptMove.Switch=1; OptTurn.Switch=0;
	OptMove.Cnt=0;
	Vec _thisTmp=((*NowTrack)-Anchor);
	if (fabs(_thisTmp.GetY())>=fabs(_thisTmp.GetX())) OptMove.Cup=_thisTmp.GetY()/OptMove.CDel;
	else OptMove.Cup=_thisTmp.GetX()/OptMove.CDel;
	OptMove.Cup=fabs(OptMove.Cup);
	OptMove.Del=Vec(_thisTmp.GetX()/(float)OptMove.Cup,_thisTmp.GetY()/(float)OptMove.Cup);
}

void Group::GetLeave(){ OptLeft.Switch=1; }

void Group::Draw(){
	for (FIGITER it=SetNormal.begin();it!=SetNormal.end();it++){
		(*it)->Draw();
	}
	for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
		(*it).Fig->Draw();
	}
}

bool Group::IsActing(){ return OptMove.Switch|OptTurn.Switch|OptLeft.Switch; }

bool Group::Act(){
	if (OptMove.Switch){
		Anchor=Anchor+OptMove.Del;
		for (FIGITER it=SetNormal.begin();it!=SetNormal.end();it++){
			(*it)->Move(OptMove.Del);
		}
		for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
			(*it).Fig->Move(OptMove.Del);
		}
		OptMove.Cnt++; 
		return 1;
	}
	if (OptTurn.Switch){
		for (FIGITER it=SetNormal.begin();it!=SetNormal.end();it++){
			(*it)->Rotate(OptTurn.Del,OptTurn.Spin);
		}
		for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
			(*it).Fig->Rotate(OptTurn.Del,OptTurn.Spin);
			(*it).Del=(*it).Del<<(OptTurn.Del*PI/180.0);
		}
		OptTurn.Theta+=fabs(OptTurn.Del);
		return 1;
	}
	if (OptLeft.Switch){
		DecorateLeave();
		return 1;
	}
	return 0;
}

bool Group::Control(){
	if (NowTrack==Track.end()){
		OptTurn.Switch=OptMove.Switch=0;
		ClearTrack();
		if (laterTrack.size()){
			Track=laterTrack; laterTrack.clear(); GetStart(0);
		}
		if (OptLeft.ReadyLeft) OptLeft.Switch=1;
		return 0;
	}
	if (OptTurn.Switch&&OptTurn.Theta>=OptTurn.Cup){
		OptTurn.Switch=0; OptMove.Switch=1; 
		OptMove.Cnt=0;
		Vec _thisTmp=((*NowTrack)-Anchor);
		while (fabs(_thisTmp.GetX())+fabs(_thisTmp.GetY())<=EPS){
			NowTrack++;
			_thisTmp=((*NowTrack)-Anchor);
		}
		if (fabs(_thisTmp.GetY())>=fabs(_thisTmp.GetX())) OptMove.Cup=_thisTmp.GetY()/OptMove.CDel;
		else OptMove.Cup=_thisTmp.GetX()/OptMove.CDel;
		OptMove.Cup=fabs(OptMove.Cup);
		OptMove.Del=Vec(_thisTmp.GetX()/(float)OptMove.Cup,_thisTmp.GetY()/(float)OptMove.Cup);
		return 1;
	}
	else if (OptMove.Switch&&OptMove.Cnt>=OptMove.Cup){
		OptMove.Switch=0; OptTurn.Switch=1; 
		float _formerDir=fabs(OptMove.Del.GetX())<=EPS?1e9:OptMove.Del.GetY()/OptMove.Del.GetX();
		OptTurn.Theta=0; OptTurn.Spin=Anchor;
		NowTrack++; if (NowTrack==Track.end()) return 0;
		float _laterDir=fabs(((*NowTrack)-Anchor).GetX())<=EPS?1e9:((*NowTrack)-Anchor).GetY()/((*NowTrack)-Anchor).GetX();
		float _thisTmp=(1+_laterDir*_formerDir);
		OptTurn.Cup=fabs(_thisTmp)<=EPS?90.0:atan((_laterDir-_formerDir)/(1+_laterDir*_formerDir))/PI*180.0;
		if (fabs(OptTurn.Cup)<=EPS){
			OptTurn.Cup=0;
			return Control();
		}
		OptTurn.Del=(OptTurn.Cup>=0?1:-1); OptTurn.Cup=fabs(OptTurn.Cup);
		return 1;
	}
	return 0;
}

bool Group::Update(){
	bool _thisFlag=0;
	_thisFlag|=Control(); DecorateControl();
	_thisFlag|=Act(); DecorateAct();
	return _thisFlag;
}

Group::~Group(){}