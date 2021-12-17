#include"Shapes.h"
#include"Van.h"
#ifdef __APPLE__
        #define GL_SILENCE_DEPRECATION 
        #include <GLUT/glut.h> 
    #elif __linux__
        #include <GL/freeglut.h> 
    #else
        #include <GL/freeglut.h> 
        #include <windows.h>
    #endif
using namespace DLB;
void TimeStep(int n){
    glutTimerFunc((unsigned int)n,TimeStep,n); 
    glutPostRedisplay();
}

void Display(){
    Group *x=Van::GetInstance();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    x->Update(); x->Draw();
}

void Start(){
    Van *x=Van::GetInstance();
    x->AddTrack({Vec(0,0.7)});
    x->GetStart(0);
    x->GetStart(1);
}

int main(int argc,char *argv[]){
    srand((unsigned int)time(NULL));
    Start();
    glutInit(&argc,argv);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Shape");
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(Display);
    glutTimerFunc(25,TimeStep,25);
    glutMainLoop();
    Van::DeleteInstance();
    return 0;
}
