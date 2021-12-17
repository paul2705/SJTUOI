#ifndef _SEMICIRCLE_H_
	#define _SEMICIRCLE_H_
	#include<iostream>
	#include<cstdio>
	#include<cstring>
	#include<cmath>
	#include<algorithm>
   
#ifdef __APPLE__
	#include <GLUT/glut.h> 
#elif __linux__
	#include <GL/freeglut.h> 
#else
	#include <GL/freeglut.h> 
	#include <windows.h>
#endif
	
	#include"Figure.h"
	using namespace std;
	#define PI acos(-1)
	class Semicircle: public Figure{
		private:
			float radius;int Vertices;float DelT;
		public:
			Semicircle(Vec _Anchor=Vec(0,0),float _Red=0,float _Green=0,float _Blue=0,float _radius=0.1,int _Vertices=100,float _DelT=0);
			void Draw();
			void Move(Vec Del);
			void Rotate(float Theta,Vec Spin); // Spin is center of rotate
			void Zoom(float K,Vec spin);
	};

#endif