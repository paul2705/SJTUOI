#ifndef _FIGURE_H_
	#define _FIGURE_H_

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
	using namespace std;

	class Vec{
		private:
			float x,y;
		public:
			Vec(float X=0,float Y=0);
			float GetX();
			float GetY();
			Vec operator + (Vec &a);
			Vec operator - (Vec &a);
			Vec operator * (float k); // zoom the vector
			float operator * (Vec &a); // inner product 
			Vec operator ^ (Vec &a); // outer product
			Vec operator << (float theta); // rotated counter clockwise
			Vec operator >> (float theta); // rotated clockwise
	};

	class Figure{
		protected:
			Vec Anchor;
			float R,G,B;
		public:
			Figure():Anchor(0,0){};
			Vec GetAnchor();
			void SetAnchor(Vec a);
			virtual void Draw()=0;
			virtual void Move(Vec Delta)=0;
			virtual void Rotate(float Theta,Vec Spin)=0;
			virtual void Zoom(float K)=0;
			virtual ~Figure(){};
	};

#endif
