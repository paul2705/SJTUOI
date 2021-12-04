#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
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

Vec::Vec(float X,float Y){ x=X; y=Y; }

float Vec::GetX(){ return x; }

float Vec::GetY(){ return y; }

Vec Vec::operator + (Vec &a){ return Vec(x+a.GetX(),y+a.GetY()); }

Vec Vec::operator - (Vec &a){ return Vec(x-a.GetX(),y-a.GetY()); }

Vec Vec::operator * (float k){ return Vec(x*k,y*k); }

float Vec::operator * (Vec &a){ return x*a.GetX()+y*a.GetY(); }

Vec Vec::operator ^ (Vec &a){ return Vec(x*a.GetX()-y*a.GetY(),y*a.GetX()+x*a.GetY()); }

Vec Vec::operator << (float theta){
	float tx=(float)cos(theta),ty=(float)sin(theta);
	return Vec(tx,ty)^(*this);
}

Vec Vec::operator >> (float theta){
	float tx=(float)cos(-theta),ty=(float)sin(theta);
	return Vec(tx,ty)^(*this);
}

Vec Figure::GetAnchor(){ return Anchor; }

void Figure::SetAnchor(Vec a){ Anchor=a; }
