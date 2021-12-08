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

#include"Semicircle.h"
#include"Figure.h"

using namespace std;



Semicircle::Semicircle(Vec _Anchor,float _Red,float _Green,float _Blue,float _radius,int _Vertices,float _DelT){
	Anchor=_Anchor;
	R=_Red; G=_Green; B=_Blue; 
	radius=_radius; 
    Vertices=_Vertices;
	DelT=_DelT;
    
}



void Semicircle::Draw(){
	float BaseX=Anchor.GetX(),BaseY=Anchor.GetY();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(R,G,B);
		glVertex2f(BaseX,BaseY);
        for (int i = 0; i <= Vertices; i++)
        {
            glVertex2f(BaseX+radius*cosf((i*PI/Vertices)+DelT),BaseY+radius*sinf((i*PI/Vertices)+DelT));
        }	
	glEnd(); 
	
}



void Semicircle::Move(Vec Del){ Anchor=Anchor+Del;}

void Semicircle::Rotate(float Theta,Vec Spin){
    Theta*=PI/180.0;
	Anchor=((Anchor-Spin)<<Theta)+Spin;
    DelT=DelT+Theta;
}

void Semicircle::Zoom(float K,Vec Spin){
	Anchor=(Anchor-Spin)*K+Spin;
	radius=radius*K;
}