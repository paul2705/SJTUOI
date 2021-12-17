#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<ctime>
#include"Figure.h"
#include"Circle.h"
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
	Circle *Cir0=new Circle(Vec(-1,-0.4),1.0,0.0,0.0,0.01,100); Cir0->Draw();
	Circle *Cir1=new Circle(Vec(-0.8,-0.4),1.0,0.0,0.0,0.01,100); Cir1->Draw();
	Circle *Cir2=new Circle(Vec(-0.8,0),1.0,0.0,0.0,0.01,100); Cir2->Draw();
	Circle *Cir3=new Circle(Vec(0.5,0),1.0,0.0,0.0,0.01,100); Cir3->Draw();
	Circle *Cir4=new Circle(Vec(0.5,0.3),1.0,0.0,0.0,0.01,100); Cir4->Draw();

	Circle *Cir6=new Circle(Vec(-0.35,0.35),1.0,0.0,0.0,0.01,100); Cir6->Draw();
	Circle *Cir7=new Circle(Vec(-0.3,0.4),1.0,0.0,0.0,0.01,100); Cir7->Draw();
	Circle *Cir8=new Circle(Vec(-0.3,0.6),1.0,0.0,0.0,0.01,100); Cir8->Draw();

	Circle *Cir9=new Circle(Vec(-0.7,0),1.0,0.0,0.0,0.01,100); Cir9->Draw();
	Circle *Cir10=new Circle(Vec(-0.6,0),1.0,0.0,0.0,0.01,100); Cir10->Draw();
	Circle *Cir11=new Circle(Vec(-0.5,0),1.0,0.0,0.0,0.01,100); Cir11->Draw();
	Circle *Cir12=new Circle(Vec(-0.4,0),1.0,0.0,0.0,0.01,100); Cir12->Draw();
	Circle *Cir13=new Circle(Vec(-0.3,0),1.0,0.0,0.0,0.01,100); Cir13->Draw();
	Circle *Cir14=new Circle(Vec(-0.2,0),1.0,0.0,0.0,0.01,100); Cir14->Draw();
	Circle *Cir15=new Circle(Vec(-0.1,0),1.0,0.0,0.0,0.01,100); Cir15->Draw();
	Circle *Cir16=new Circle(Vec(0,0),1.0,0.0,0.0,0.01,100); Cir16->Draw();
	Circle *Cir17=new Circle(Vec(0.1,0),1.0,0.0,0.0,0.01,100); Cir17->Draw();
	Circle *Cir18=new Circle(Vec(0.2,0),1.0,0.0,0.0,0.01,100); Cir18->Draw();
	Circle *Cir19=new Circle(Vec(0.3,0),1.0,0.0,0.0,0.01,100); Cir19->Draw();
	Circle *Cir20=new Circle(Vec(0.4,0),1.0,0.0,0.0,0.01,100); Cir20->Draw();

	Circle *Cir21=new Circle(Vec(-0.7,0.3),1.0,0.0,0.0,0.01,100); Cir21->Draw();
	Circle *Cir22=new Circle(Vec(-0.6,0.3),1.0,0.0,0.0,0.01,100); Cir22->Draw();
	Circle *Cir23=new Circle(Vec(-0.5,0.3),1.0,0.0,0.0,0.01,100); Cir23->Draw();
	Circle *Cir24=new Circle(Vec(-0.4,0.3),1.0,0.0,0.0,0.01,100); Cir24->Draw();
	Circle *Cir25=new Circle(Vec(-0.3,0.3),1.0,0.0,0.0,0.01,100); Cir25->Draw();
	Circle *Cir26=new Circle(Vec(-0.2,0.3),1.0,0.0,0.0,0.01,100); Cir26->Draw();
	Circle *Cir27=new Circle(Vec(-0.1,0.3),1.0,0.0,0.0,0.01,100); Cir27->Draw();
	Circle *Cir28=new Circle(Vec(0,0.3),1.0,0.0,0.0,0.01,100); Cir28->Draw();
	Circle *Cir29=new Circle(Vec(0.1,0.3),1.0,0.0,0.0,0.01,100); Cir29->Draw();
	Circle *Cir30=new Circle(Vec(0.2,0.3),1.0,0.0,0.0,0.01,100); Cir30->Draw();
	Circle *Cir31=new Circle(Vec(0.3,0.3),1.0,0.0,0.0,0.01,100); Cir31->Draw();
	Circle *Cir32=new Circle(Vec(0.4,0.3),1.0,0.0,0.0,0.01,100); Cir32->Draw();

	Circle *Cir33=new Circle(Vec(0.5,0.2),1.0,0.0,0.0,0.01,100); Cir33->Draw();
	Circle *Cir34=new Circle(Vec(0.5,0.1),1.0,0.0,0.0,0.01,100); Cir34->Draw();

	Circle *Cir37=new Circle(Vec(-0.15,0.35),1.0,0.0,0.0,0.01,100); Cir37->Draw();
	Circle *Cir38=new Circle(Vec(-0.1,0.4),1.0,0.0,0.0,0.01,100); Cir38->Draw();
	Circle *Cir39=new Circle(Vec(-0.1,0.6),1.0,0.0,0.0,0.01,100); Cir39->Draw();

	Circle *Cir40=new Circle(Vec(0,0.3),1.0,0.0,0.0,0.01,100); Cir40->Draw();
	Circle *Cir41=new Circle(Vec(0.05,0.35),1.0,0.0,0.0,0.01,100); Cir41->Draw();
	Circle *Cir42=new Circle(Vec(0.1,0.4),1.0,0.0,0.0,0.01,100); Cir42->Draw();
	Circle *Cir43=new Circle(Vec(0.1,0.6),1.0,0.0,0.0,0.01,100); Cir43->Draw();

	Circle *Cir44=new Circle(Vec(0.2,0.3),1.0,0.0,0.0,0.01,100); Cir44->Draw();
	Circle *Cir45=new Circle(Vec(0.25,0.35),1.0,0.0,0.0,0.01,100); Cir45->Draw();
	Circle *Cir46=new Circle(Vec(0.3,0.4),1.0,0.0,0.0,0.01,100); Cir46->Draw();
	Circle *Cir47=new Circle(Vec(0.3,0.6),1.0,0.0,0.0,0.01,100); Cir47->Draw();

	Circle *Cir48=new Circle(Vec(0.4,0.3),1.0,0.0,0.0,0.01,100); Cir48->Draw();
	Circle *Cir49=new Circle(Vec(0.45,0.35),1.0,0.0,0.0,0.01,100); Cir49->Draw();
	Circle *Cir50=new Circle(Vec(0.5,0.4),1.0,0.0,0.0,0.01,100); Cir50->Draw();
	Circle *Cir51=new Circle(Vec(0.5,0.6),1.0,0.0,0.0,0.01,100); Cir51->Draw();

	Circle *Cir52=new Circle(Vec(0.6,-0),1.0,0.0,0.0,0.01,100); Cir52->Draw();
	Circle *Cir53=new Circle(Vec(0.55,-0.05),1.0,0.0,0.0,0.01,100); Cir53->Draw();
	Circle *Cir54=new Circle(Vec(0.5,-0.1),1.0,0.0,0.0,0.01,100); Cir54->Draw();
	Circle *Cir55=new Circle(Vec(0.5,-0.3),1.0,0.0,0.0,0.01,100); Cir55->Draw();

	Circle *Cir56=new Circle(Vec(0.4,-0),1.0,0.0,0.0,0.01,100); Cir56->Draw();
	Circle *Cir57=new Circle(Vec(0.35,-0.05),1.0,0.0,0.0,0.01,100); Cir57->Draw();
	Circle *Cir58=new Circle(Vec(0.3,-0.1),1.0,0.0,0.0,0.01,100); Cir58->Draw();
	Circle *Cir59=new Circle(Vec(0.3,-0.3),1.0,0.0,0.0,0.01,100); Cir59->Draw();

	Circle *Cir60=new Circle(Vec(0.2,-0),1.0,0.0,0.0,0.01,100); Cir60->Draw();
	Circle *Cir61=new Circle(Vec(0.15,-0.05),1.0,0.0,0.0,0.01,100); Cir61->Draw();
	Circle *Cir62=new Circle(Vec(0.1,-0.1),1.0,0.0,0.0,0.01,100); Cir62->Draw();
	Circle *Cir63=new Circle(Vec(0.1,-0.3),1.0,0.0,0.0,0.01,100); Cir63->Draw();

	Circle *Cir64=new Circle(Vec(0,-0),1.0,0.0,0.0,0.01,100); Cir64->Draw();
	Circle *Cir65=new Circle(Vec(-0.05,-0.05),1.0,0.0,0.0,0.01,100); Cir65->Draw();
	Circle *Cir66=new Circle(Vec(-0.1,-0.1),1.0,0.0,0.0,0.01,100); Cir66->Draw();
	Circle *Cir67=new Circle(Vec(-0.1,-0.3),1.0,0.0,0.0,0.01,100); Cir67->Draw();

	Circle *Cir68=new Circle(Vec(-0.2,-0),1.0,0.0,0.0,0.01,100); Cir68->Draw();
	Circle *Cir69=new Circle(Vec(-0.25,-0.05),1.0,0.0,0.0,0.01,100); Cir69->Draw();
	Circle *Cir70=new Circle(Vec(-0.3,-0.1),1.0,0.0,0.0,0.01,100); Cir70->Draw();
	Circle *Cir71=new Circle(Vec(-0.3,-0.3),1.0,0.0,0.0,0.01,100); Cir71->Draw();

	Circle *Cir72=new Circle(Vec(-0.8,0.3),1.0,0.0,0.0,0.01,100); Cir72->Draw();
	Circle *Cir73=new Circle(Vec(-0.8,0.6),1.0,0.0,0.0,0.01,100); Cir73->Draw();
	Circle *Cir74=new Circle(Vec(-0.9,0.6),1.0,0.0,0.0,0.01,100); Cir74->Draw();
	glFlush();
}

int main(int argc,char *argv[]){
	srand((unsigned int)time(NULL));
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
	return 0;
}
