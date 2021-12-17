/*--------------------
Author: Chen Donghao
Date: 2021.12.03
function: Class Of Circle
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
#include"Circle.h"
#include"Figure.h"

using namespace std;

Circle::Circle(Vec _Anchor,float _Red,float _Green,float _Blue,float _radius,int _Vertices){
	Anchor=_Anchor;
	R=_Red; G=_Green; B=_Blue; 
	radius=_radius; 
    Vertices=_Vertices;
}

void Circle::Draw(){
	float BaseX=Anchor.GetX(),BaseY=Anchor.GetY();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(R,G,B);
		glVertex2f(BaseX,BaseY);
        for (int i = 0; i <= Vertices; i++)
        {
            glVertex2f(BaseX+radius*cosf(i*2.0*PI/Vertices),BaseY+radius*sinf(i*2.0*PI/Vertices));
        }	
	glEnd();
	
}

void Circle::Move(Vec Del){ Anchor=Anchor+Del; }

void Circle::Rotate(float Theta,Vec Spin){
	Theta*=PI/180.0;
	Anchor=((Anchor-Spin)<<Theta)+Spin;
}

void Circle::Zoom(float K,Vec Spin){
	Anchor=(Anchor-Spin)*K+Spin;
	radius=radius*K;
}