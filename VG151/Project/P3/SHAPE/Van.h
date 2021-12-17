#ifndef _VAN_H_
	#define _VAN_H_

	#include<iostream>
	#include<cstdio>
	#include<cstring>
	#include<cmath>
	#include<algorithm>
	#include<vector>
	#include<initializer_list>
	#ifdef __APPLE__
		#define GL_SILENCE_DEPRECATION 
		#include <GLUT/glut.h> 
	#elif __linux__
		#include <GL/freeglut.h> 
	#else
		#include <GL/freeglut.h> 
		#include <windows.h>
	#endif
	
	#include"Shapes.h"
	using namespace DLB;
	#define FIGITER vector<Figure*>::iterator
	#define VECITER vector<Vec>::iterator
	#define CAR 1
	#define UFO 2
	#define SPACECRAFT 3
	#define TELEPORTED 4
	#define VAN 5

	class Van: public Vehicle, public Group{
		private:
			const int Type=VAN;
		public:
			Van(float _PointX,float _PointY);
			static Van *GetInstance();
			static void DeleteInstance();
			void ParkIn(ArrivalTicket *T);
			void ChangeSlot(ChangeTicket *T);
			void ParkOut(DepartTicket *T);
			void DecorateAct();
			void DecorateControl();
			void DecorateLeave();
			int GetType();
			~Van();
	};

#endif