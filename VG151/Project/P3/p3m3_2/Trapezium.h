/*--------------------
Author: Ruan Kunlin
Date: 2021.12.02
function: Class Of Trapezium
--------------------*/

#ifndef _TRAPEZIUM_H_
	#define _TRAPEZIUM_H_

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

    class Trapezium: public Figure{
        private:
            Vec Del1,Del2,Del3,Del4;
        public:
            static Trapezium* GetInstance(){
                static Trapezium *s=NULL;
                if (s==NULL) s=new Trapezium(Vec(0.0,0.0),1.0,0.0,1.0);
                return s;
            }
            static void DeleteInstance(){
                Trapezium* s=Trapezium::GetInstance();
                if (s!=NULL) delete s;
                s=NULL;
            }
            Trapezium(Vec _Anchor=Vec(0,0),float _R=0,float _G=0,float _B=0,Vec _Del1=Vec(-sqrt(3)/2.0,-1.0/2.0),Vec _Del2=Vec(sqrt(3)/2.0,-1.0/2.0),Vec _Del3=Vec(1.0/2.0,sqrt(3)/2.0),Vec _Del4=Vec(-1.0/2.0,sqrt(3)/2.0));
            void Draw();
            void Move(Vec Del);
            void Rotate(float Theta,Vec Spin);
            void Zoom(float K);
    };

#endif