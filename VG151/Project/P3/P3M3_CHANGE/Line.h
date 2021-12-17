#ifndef _LINE_H_
    #define _LINE_H_

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

    class Line : public Figure{
        private:
            Vec Del;//the anchor for line is an end of the line
        public:
            Line(Vec _Anchor=Vec(0,0),float _R=0,float _G=0,float _Blue=0,Vec _Del=Vec(1.0,0.0));
            void Draw();
            void Move(Vec Delta);
            void Rotate(float Theta,Vec Spin);
            void Zoom(float K,Vec Spin);
    };
    
#endif