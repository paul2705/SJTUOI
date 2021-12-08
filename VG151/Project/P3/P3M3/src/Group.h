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
	#include"Line.h"
	#include"Circle.h"
	#include"Semicircle.h"
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
	typedef struct _Leaving{
		bool ReadyLeft=0;
		bool Switch=0;
	} Leaving;
	typedef struct _Decorating{
		Vec Del=Vec(0,0.005);
		int Cup=20; int Cnt=0;
		int Dir=1;
		Figure* Fig;
	} Decorating;

	class Group{
		protected:
			vector<Figure*> SetNormal;
			vector<Decorating> SetDecorate;
			vector<Vec> Track,laterTrack;
			VECITER NowTrack;
			Vec Anchor;
			Turning OptTurn;
			Moving OptMove;
			Leaving OptLeft;
			bool Act();
			bool Control();
			void ClearTrack();
		public:
			Group(float _X,float _Y);
			void AddNormalFigure(initializer_list<Figure*> _FigList);
			void AddDecorateFigure(initializer_list<Decorating> _FigList);
			void AddTrack(initializer_list<Vec> _VecList);
			void GetStart(bool _Final);
			bool IsActing();
			void GetLeave();
			void Draw();
			virtual void DecorateAct()=0;
			virtual void DecorateControl()=0;
			virtual void DecorateLeave()=0;
			bool Update();
			virtual ~Group()=0;
	};

#endif