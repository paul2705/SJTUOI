/*--------------------
Author: Dong Beiyu
Date: 2021.12.02
function: Class Of Quad
--------------------*/

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
#include"Quad.h"
#include"Figure.h"
using namespace std;

Quad::Quad(Vec _Anchor,float _Red,float _Green,float _Blue,Vec _Del1,Vec _Del2,Vec _Del3, Vec _Del4){
	Anchor=_Anchor;
	R=_Red; G=_Green; B=_Blue; 
	Del1=_Del1; Del2=_Del2; Del3=_Del3; Del4=_Del4;
}

void Quad::Draw(){
	float BaseX=Anchor.GetX(),BaseY=Anchor.GetY();
	glBegin(GL_QUADS);
		glColor3f(R,G,B);
		glVertex3f(BaseX+Del1.GetX(),BaseY+Del1.GetY(),0.0f);
		glVertex3f(BaseX+Del2.GetX(),BaseY+Del2.GetY(),0.0f);
		glVertex3f(BaseX+Del3.GetX(),BaseY+Del3.GetY(),0.0f);
		glVertex3f(BaseX+Del4.GetX(),BaseY+Del4.GetY(),0.0f);
	glEnd(); 
}

void Quad::Move(Vec Del){ Anchor=Anchor+Del; }

void Quad::Rotate(float Theta,Vec Spin){
	Theta*=PI/180.0;
	Anchor=((Anchor-Spin)<<Theta)+Spin;
	Del1=Del1<<Theta; Del2=Del2<<Theta; Del3=Del3<<Theta;Del4=Del4<<Theta;
}

void Quad::Zoom(float K,Vec Spin){
	Anchor=(Anchor-Spin)*K+Spin;
	Del1=Del1*K; Del2=Del2*K; Del3=Del3*K;Del4=Del4*K;
}
