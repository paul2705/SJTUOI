/*--------------------
Author: Duan Lingbo
Date: 2021.12.01
function: Class Of Triangle
--------------------*/

#ifndef _TRIANGLE_H_
	#define _TRIANGLE_H_

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

	class Triangle: public Figure{
		private:
			Vec Del1,Del2,Del3;
		public:
			static Triangle* GetInstance(){
				static Triangle *s=NULL;
				if (s==NULL) s=new Triangle(Vec(0.0,0.0),0.0,1.0,0.0);
				return s;
			}
			static void DeleteInstance(){
				Triangle *s=Triangle::GetInstance();
				if (s!=NULL) delete s;
				s=NULL;
			}
			Triangle(Vec _Anchor=Vec(0,0),float _Red=0,float _Green=0,float _Blue=0,Vec _Del1=Vec(-0.01,-0.005),Vec _Del2=Vec(0.01,-0.005),Vec _Del3=Vec(0,0.01));
			void Draw();
			void Move(Vec Del);
			void Rotate(float Theta,Vec Spin);
			void Zoom(float K);
	};

#endif
