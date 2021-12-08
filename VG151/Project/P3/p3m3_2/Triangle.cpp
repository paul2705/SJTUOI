/*--------------------
Author: Duan Lingbo
Date: 2021.12.01
function: Class Of Triangle
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
#include"Triangle.h"
#include"Figure.h"
using namespace std;

Triangle::Triangle(Vec _Anchor,float _Red,float _Green,float _Blue,Vec _Del1,Vec _Del2,Vec _Del3){
	Anchor=_Anchor;
	R=_Red; G=_Green; B=_Blue; 
	Del1=_Del1; Del2=_Del2; Del3=_Del3;
}

void Triangle::Draw(){
	float BaseX=Anchor.GetX(),BaseY=Anchor.GetY();
	glBegin(GL_TRIANGLES);
		glColor3f(R,G,B);
		glVertex3f(BaseX+Del1.GetX(),BaseY+Del1.GetY(),0.0f);
		glVertex3f(BaseX+Del2.GetX(),BaseY+Del2.GetY(),0.0f);
		glVertex3f(BaseX+Del3.GetX(),BaseY+Del3.GetY(),0.0f);
		//cout<<BaseX+Del1.GetX()<<" "<<BaseY+Del1.GetY()<<endl;
		//cout<<BaseX+Del2.GetX()<<" "<<BaseY+Del2.GetY()<<endl;
		//cout<<BaseX+Del3.GetX()<<" "<<BaseY+Del3.GetY()<<endl;
	glEnd();
	glBegin(GL_POINTS);
		glColor3f(0.0,0.0,1.0);
		glVertex2f(BaseX,BaseY);
	glEnd(); 
	glBegin(GL_POINTS);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(-0.2,-0.2); glVertex2f(-0.2,-0.1); glVertex2f(-0.2,0); glVertex2f(-0.2,0.1); glVertex2f(-0.2,0.2);
		glVertex2f(-0.1,-0.2); glVertex2f(-0.1,-0.1); glVertex2f(-0.1,0); glVertex2f(-0.1,0.1); glVertex2f(-0.1,0.2);
		glVertex2f(0,-0.2); glVertex2f(0,-0.1); glVertex2f(0,0); glVertex2f(0,0.1); glVertex2f(0,0.2);
		glVertex2f(0.1,-0.2); glVertex2f(0.1,-0.1); glVertex2f(0.1,0); glVertex2f(0.1,0.1); glVertex2f(0.1,0.2);
		glVertex2f(0.2,-0.2); glVertex2f(0.2,-0.1); glVertex2f(0.2,0); glVertex2f(0.2,0.1); glVertex2f(0.2,0.2);
	glEnd(); 
}

void Triangle::Move(Vec Del){ Anchor=Anchor+Del; }

void Triangle::Rotate(float Theta,Vec Spin){
	Theta*=PI/180.0;
	Anchor=((Anchor-Spin)<<Theta)+Spin;
	Del1=Del1<<Theta; Del2=Del2<<Theta; Del3=Del3<<Theta;
}

void Triangle::Zoom(float K,Vec Spin){
	Anchor=(Anchor-Spin)*K+Spin;
	Del1=Del1*K; Del2=Del2*K; Del3=Del3*K;
}
