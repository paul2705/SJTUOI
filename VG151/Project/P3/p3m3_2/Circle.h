/*--------------------
Author: Chen Donghao
Date: 2021.12.03
function: Class Of Circle
--------------------*/

#ifndef _CIRCLE_H_
	#define _CIRCLE_H_
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
	class Circle: public Figure{
		private:
			float radius; int Vertices;
		public:
			static Circle* GetInstance(){
				static Circle *s=NULL;
				if (s==NULL) s=new Circle();
				return s;
			}
			static void DeleteInstance(){
				Circle *s=Circle::GetInstance();
				if (s!=NULL) delete s;
				s=NULL;
			}
			Circle(Vec _Anchor=Vec(0,0),float _Red=0,float _Green=0,float _Blue=0,float _radius=0.1,int _Vertices=100);
			void Draw();
			void Move(Vec Del);
			void Rotate(float Theta,Vec Spin); // Spin is center of rotate
			void Zoom(float K);
	};

#endif