#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif
#include "vehicle.h"
#include "parkingLot.h"
void TimeStep(int n) {
    glutTimerFunc((unsigned int)n, TimeStep, n); glutPostRedisplay();
}

void glDraw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ParkingLot* Yinjian_Parkinglot = ParkingLot::getInstance();
    Yinjian_Parkinglot->draw();
    Yinjian_Parkinglot->moveDoor();
    Yinjian_Parkinglot->moveVeh();
    glutSwapBuffers(); glFlush();
}

int main (int argc, char *argv[]) {
    sizes* s=sizes::getInstance();
    if (s->get_slot_num()){}
    srand((unsigned)time(nullptr));
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 1000);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Move a car");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(glDraw);
    glutTimerFunc(25, TimeStep, 25); // Default 25
    glutMainLoop();
    sizes::deleteInstance();
    ParkingLot::deleteInstance();
}
