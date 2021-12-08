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
#include"Line.h"
#include"Figure.h"
using namespace std;

Line::Line(Vec _Anchor,float _R,float _G,float _Blue,Vec _Del){
    Anchor=_Anchor;R=_R;G=_G;B=_Blue;
    Del=_Del;
}

void Line::Draw(){
    float BaseX=Anchor.GetX(),BaseY=Anchor.GetY();
    glBegin(GL_LINES);
        glColor3f(R,G,B);
        glVertex2f(BaseX,BaseY);
        glVertex2f(BaseX+Del.GetX(),BaseY+Del.GetY());
    glEnd(); 
    glBegin(GL_POINT);
        glColor3f(0.0,0.0,0.0);
        glVertex2f(BaseX,BaseY);
    glEnd(); 
}

void Line::Move(Vec Delta){
    Anchor=Anchor+Delta;
}

void Line::Rotate(float Theta,Vec Spin){
    Theta*=PI/180.0;
    Vec a_s=Anchor-Spin;
    Vec new_a_s=a_s<<Theta;
    Anchor=new_a_s+Spin;
    Del=Del<<Theta;
}

void Line::Zoom(float K,Vec Spin){
    Vec del=Anchor-Spin;
    del=del*K;
    Anchor=Spin+del;
    Del=Del*K;
}
