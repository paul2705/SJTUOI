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
#include"Trapezium.h"
#include"Figure.h"
using namespace std;

Trapezium::Trapezium(Vec _Anchor,float _R,float _G,float _B,Vec _Del1,Vec _Del2,Vec _Del3,Vec _Del4){
    Anchor=_Anchor;
    R=_R;G=_G;B=_B;
    Del1=_Del1;Del2=_Del2;Del3=_Del3;Del4=_Del4;
}

void Trapezium::Draw(){
    float BaseX=Anchor.GetX(),BaseY=Anchor.GetY();
    glBegin(GL_POLYGON);
        glColor3f(R,G,B);
        glVertex3f(BaseX+Del1.GetX(),BaseY+Del1.GetY(),0.0f);
		glVertex3f(BaseX+Del2.GetX(),BaseY+Del2.GetY(),0.0f);
		glVertex3f(BaseX+Del3.GetX(),BaseY+Del3.GetY(),0.0f);
        glVertex3f(BaseX+Del4.GetX(),BaseY+Del4.GetY(),0.0f);
        cout<<BaseX+Del1.GetX()<<" "<<BaseY+Del1.GetY()<<endl;
		cout<<BaseX+Del2.GetX()<<" "<<BaseY+Del2.GetY()<<endl;
		cout<<BaseX+Del3.GetX()<<" "<<BaseY+Del3.GetY()<<endl;
        cout<<BaseX+Del4.GetX()<<" "<<BaseY+Del4.GetY()<<endl;
    glEnd();glFlush();
    glBegin(GL_POINTS);
        glColor3f(1.0,0.0,1.0);
        glVertex2f(BaseX,BaseY);
    glEnd();glFlush();

}

void Trapezium::Move(Vec Del){ Anchor=Anchor+Del;}
void Trapezium::Rotate(float Theta,Vec Spin){
    Theta*=PI/180.0;
    Vec a_s=Anchor-Spin;
    Vec new_a_s=a_s<<Theta;
    Anchor=new_a_s+Spin;
    Del1=(Del1<<Theta)+Spin;Del2=(Del2<<Theta)+Spin;Del3=(Del3<<Theta)+Spin;Del4=(Del4<<Theta)+Spin;
}

void Trapezium::Zoom(float K){
    cout<<K<<endl;
    Del1=Del1*K;Del2=Del2*K;Del3=Del3*K;Del4=Del4*K;
}