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
#include"Group.h"
#ifdef __APPLE__
	#include <GLUT/glut.h> 
#elif _WIN32
	#include <GL/freeglut.h> 
	#include <windows.h>
#elif __linux__
	#include <GL/freeglut.h> 
#endif
#define PI acos(-1)
#define fabs(a) (a>=0?a:-a)
#define Aabs(a) (a>=0?a:270+a)
#define EPS 1e-9
#define FIGITER vector<Figure*>::iterator
#define VECITER vector<Vec>::iterator
#define VECLSTITER initializer_list<Vec>::iterator
#define FIGLSTITER initializer_list<Figure*>::iterator
using namespace std;

Group::Group(float _X,float _Y){
	Set.clear(); Anchor=Vec(_X,_Y);
	Track.push_back(Vec(_X,_Y)); 
}

void Group::AddFigure(initializer_list<Figure*> _FigList){
	for (FIGLSTITER it=_FigList.begin();it!=_FigList.end();it++) Set.push_back((*it));
}

void Group::AddTrack(initializer_list<Vec> _VecList){
	for (VECLSTITER it=_VecList.begin();it!=_VecList.end();it++) Track.push_back((*it));
}

void Group::GetStart(){
	NowTrack=Track.begin(); NowTrack++;
	OptMove.Switch=1; OptTurn.Switch=0;
	OptMove.Cnt=0;
	Vec _thisTmp=((*NowTrack)-Anchor);
	if (fabs(_thisTmp.GetY())>=fabs(_thisTmp.GetX())) OptMove.Cup=_thisTmp.GetY()/OptMove.CDel;
	else OptMove.Cup=_thisTmp.GetX()/OptMove.CDel;
	OptMove.Cup=fabs(OptMove.Cup);
	OptMove.Del=_thisTmp/(float)OptMove.Cup;
}

void Group::Draw(){
	for (FIGITER it=Set.begin();it!=Set.end();it++){
		(*it)->Draw();
	}
	glFlush();
}

void Group::Act(){
	if (OptMove.Switch){
		Anchor=Anchor+OptMove.Del;
		for (FIGITER it=Set.begin();it!=Set.end();it++){
			(*it)->Move(OptMove.Del);
		}
		OptMove.Cnt++; 
	}
	if (OptTurn.Switch){
		for (FIGITER it=Set.begin();it!=Set.end();it++){
			(*it)->Rotate(OptTurn.Del,OptTurn.Spin);
		}
		OptTurn.Theta+=fabs(OptTurn.Del);
	}
}

bool Group::Control(){
	if (NowTrack==Track.end()){
		OptTurn.Switch=OptMove.Switch=0;
		return 0;
	}
	if (OptTurn.Switch&&OptTurn.Theta>=OptTurn.Cup){
		OptTurn.Switch=0; OptMove.Switch=1; 
		OptMove.Cnt=0;
		Vec _thisTmp=((*NowTrack)-Anchor);
		if (fabs(_thisTmp.GetY())>=fabs(_thisTmp.GetX())) OptMove.Cup=_thisTmp.GetY()/OptMove.CDel;
		else OptMove.Cup=_thisTmp.GetX()/OptMove.CDel;
		OptMove.Cup=fabs(OptMove.Cup);
		OptMove.Del=_thisTmp/(float)OptMove.Cup;
	}
	else if (OptMove.Switch&&OptMove.Cnt>=OptMove.Cup){
		OptMove.Switch=0; OptTurn.Switch=1; 
		float _formerDir=fabs(OptMove.Del.GetX())<=EPS?1e9:OptMove.Del.GetY()/OptMove.Del.GetX();
		OptTurn.Theta=0; OptTurn.Spin=Anchor;
		NowTrack++;
		float _laterDir=fabs(((*NowTrack)-Anchor).GetX())<=EPS?1e9:((*NowTrack)-Anchor).GetY()/((*NowTrack)-Anchor).GetX();
		float _thisTmp=(1+_laterDir*_formerDir);
		OptTurn.Cup=fabs(_thisTmp)<=EPS?90.0:atan((_laterDir-_formerDir)/(1+_laterDir*_formerDir))/PI*180.0;
		OptTurn.Del=(OptTurn.Cup>=0?1:-1); OptTurn.Cup=fabs(OptTurn.Cup);
	}
	return 1;
}

void Group::Update(){
	Control(); 
	Act();
}
