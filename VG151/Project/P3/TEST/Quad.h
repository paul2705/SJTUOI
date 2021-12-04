#ifndef _Quad_H_
	#define _Quad_H_

	#include<iostream>
	#include<cstdio>
	#include<cstring>
	#include<cmath>
	#include<algorithm>
	#ifdef __APPLE__
		#include <GLUT/glut.h> 
	#elif _WIN32
		#include <GL/freeglut.h> 
		#include <windows.h>
	#elif __linux__
		#include <GL/freeglut.h> 
	#endif
	#include"Figure.h"
	using namespace std;
	#define PI acos(-1)

	class Quad: public Figure{
		private:
			Vec Del1,Del2,Del3,Del4;
		public:
			static Quad* GetInstance(){
				static Quad *s=NULL;
				if (s==NULL) s=new Quad(Vec(0.0,0.0),0.0,1.0,1.0);
				return s;
			}
			static void DeleteInstance(){
				Quad *s=Quad::GetInstance();
				if (s!=NULL) delete s;
				s=NULL;
			}
			Quad(Vec _Anchor=Vec(0,0),float _Red=0,float _Green=0,float _Blue=0,Vec _Del1=Vec(0.1,0.1),Vec _Del2=Vec(0.1,-0.1),Vec _Del3=Vec(-0.1,-0.1),Vec _Del4=Vec(-0.1,0.1));
			void Draw();
			void Move(Vec Del);
			void Rotate(float Theta,Vec Spin);
			void Zoom(float K);
	};

#endif
