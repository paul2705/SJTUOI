#ifndef _GROUP_H_
	#define _GROUP_H_

	#include<iostream>
	#include<cstdio>
	#include<cstring>
	#include<algorithm>
	#include<vector>
	#include<initializer_list>
	#include"Figure.h"
	#include"Triangle.h"
	#include"Trapezium.h"
	#include"Quad.h"
	using namespace std;
	#define FIGITER vector<Figure*>::iterator
	#define VECITER vector<Vec>::iterator
	typedef struct _Turning{
		float Del=1.0,Cup=90.0;
		float Theta=0; 
		Vec Spin=Vec(0,0);
		bool Switch=0;
	} Turning;
	typedef struct _Moving{
		const float CDel=0.01;
		Vec Del=Vec(CDel,0);
		int Cup=0,Cnt=0;
		bool Switch=0;
	} Moving;

	class Group{
		private:
			vector<Figure*> Set;
			vector<Vec> Track; 
			VECITER NowTrack;
			Vec Anchor;
			Turning OptTurn;
			Moving OptMove;
			void Act();
			bool Control();
		public:
			Group(float _X,float _Y);
			static Group *GetInstance(){
				static Group *s=NULL;
				if (s==NULL){
					s=new Group(-1,-0.4);
					Triangle *Tri1=new Triangle(Vec(-0.05,-0.02)+s->Anchor,1.0,0.0,0.0,Vec(-0.04,-0.02),Vec(0.04,-0.02),Vec(0,0.04));
					Triangle *Tri2=new Triangle(Vec(0.05,-0.02)+s->Anchor,1.0,0.0,0.0,Vec(-0.04,-0.02),Vec(0.04,-0.02),Vec(0,0.04));
					Quad *Qua=new Quad(s->Anchor,0.0,1.0,0.0,Vec(0.1,0.05),Vec(0.1,-0.05),Vec(-0.1,-0.05),Vec(-0.1,0.05));
					Trapezium *Trap=new Trapezium(Vec(0.0,0.02)+s->Anchor,0.0,1.0,0.0,Vec(-sqrt(3)/20.0,-1.0/20.0),Vec(sqrt(3)/20.0,-1.0/20.0),Vec(1.0/20.0,sqrt(3)/20.0),Vec(-1.0/20.0,sqrt(3)/20.0));
					s->AddFigure({Qua,Trap,Tri1,Tri2});
					s->AddTrack({Vec(-0.8,-0.4),Vec(-0.8,0),Vec(0,0),Vec(0.5,0.5)});
					s->AddTrack({Vec(-0.4,0.2),Vec(0.4,0.2),Vec(0.4,-0.4),Vec(0.2,0.8)});
					s->GetStart();
				}
				return s;
			}
			static void DeleteInstance(){
				Group *s=Group::GetInstance();
				if (s!=NULL) delete s;
				s=NULL;
			}
			void AddFigure(initializer_list<Figure*> _FigList);
			void AddTrack(initializer_list<Vec> _VecList);
			void GetStart();
			void Draw();
			void Update();
	};

#endif