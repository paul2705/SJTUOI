#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<ctime>
#include"Figure.h"
#include"Group.h"
#include"Sys.h"
#include"Car.h"
#ifdef __APPLE__
	#include <GLUT/glut.h> 
#elif __linux__
	#include <GL/freeglut.h> 
#else
	#include <GL/freeglut.h> 
	#include <windows.h>
#endif
using namespace std;

void TimeStep(int n){
	glutTimerFunc((unsigned int)n,TimeStep,n); 
	glutPostRedisplay();
}

void Display(){
	Group *x=Car::GetInstance();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	x->Update();
	x->Draw();
}

void Start(){
	Group *x=Car::GetInstance();
	x->AddTrack({Vec(-0.8,-0.4),Vec(-0.8,0),Vec(0,0),Vec(0.5,0.5)});
	x->AddTrack({Vec(-0.4,0.2),Vec(0.4,0.2),Vec(0.4,-0.4),Vec(0.2,0.8)});
	x->GetStart();
}

int main(int argc,char *argv[]){
	srand((unsigned int)time(NULL));
	Start();
	glutInit(&argc,argv);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(0,0);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutCreateWindow("Test");
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(Display);
	glutTimerFunc(25,TimeStep,25);
	glutMainLoop();
//    PauseScreen(1000000);
	Car::DeleteInstance();
	return 0;
}
