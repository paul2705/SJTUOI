#include "coloredFig.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif
using namespace std;

void Shape::paint(){
    r = (float)rand()/(const float)RAND_MAX;
    g = (float)rand()/(const float)RAND_MAX;
    b = (float)rand()/(const float)RAND_MAX;
} // Generate random color

Triangle::Triangle(Vec temp_cen,Vec pt1, Vec pt2, Vec pt3, float red, float green, float blue) {
    cen = temp_cen;
    p1 = cen + pt1;p2 = cen + pt2;p3 = cen + pt3;
    r = red; g = green; b = blue;
}

void Triangle::draw() {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_STRIP);
    float p1X = p1.getX(); float p1Y = p1.getY();
    float p2X = p2.getX(); float p2Y = p2.getY();
    float p3X = p3.getX(); float p3Y = p3.getY();
    glVertex2f(p1X, p1Y); glVertex2f(p2X, p2Y); glVertex2f(p3X, p3Y);
    glEnd();
}

void Triangle::move(Vec d_vec){
    p1 = p1 + d_vec;
    p2 = p2 + d_vec;
    p3 = p3 + d_vec;
    cen = cen + d_vec;
}

void Triangle::rotate(float angle,Vec rot_cen){
    p1 = ((p1-rot_cen) >> (angle*PI/180)) + rot_cen;
    p2 = ((p2-rot_cen) >> (angle*PI/180)) + rot_cen;
    p3 = ((p3-rot_cen) >> (angle*PI/180)) + rot_cen;
    cen = ((cen-rot_cen) >> (angle*PI/180)) + rot_cen;
}

void Triangle::zoom(float scale){
    p1 = (p1-cen)*scale+cen;
    p2 = (p2-cen)*scale+cen;
    p3 = (p3-cen)*scale+cen;
}

Quads::Quads(Vec temp_cen,Vec pt1, Vec pt2, Vec pt3, Vec pt4, float red, float green, float blue) {
    cen = temp_cen;
    p1 = cen + pt1; p2 = cen + pt2; p3 = cen + pt3; p4 = cen + pt4;
    r = red; g = green; b = blue;
}

void Quads::draw() {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    float p1X = p1.getX(); float p1Y = p1.getY();
    float p2X = p2.getX(); float p2Y = p2.getY();
    float p3X = p3.getX(); float p3Y = p3.getY();
    float p4X = p4.getX(); float p4Y = p4.getY();
    glVertex2f(p1X, p1Y); glVertex2f(p2X, p2Y);
    glVertex2f(p3X, p3Y); glVertex2f(p4X, p4Y);
    glEnd();
}

void Quads::move(Vec d_vec){
    p1 = p1 + d_vec;
    p2 = p2 + d_vec;
    p3 = p3 + d_vec;
    p4 = p4 + d_vec;
    cen = cen + d_vec;
}

void Quads::rotate(float angle,Vec rot_cen){
    p1 = ((p1-rot_cen) >> (angle*PI/180)) + rot_cen;
    p2 = ((p2-rot_cen) >> (angle*PI/180)) + rot_cen;
    p3 = ((p3-rot_cen) >> (angle*PI/180)) + rot_cen;
    p4 = ((p4-rot_cen) >> (angle*PI/180)) + rot_cen;
    cen = ((cen-rot_cen) >> (angle*PI/180)) + rot_cen;
}

void Quads::zoom(float scale){
    p1 = (p1-cen)*scale+cen;
    p2 = (p2-cen)*scale+cen;
    p3 = (p3-cen)*scale+cen;
    p4 = (p4-cen)*scale+cen;
}

Polygon::Polygon(Vec temp_cen,float temp_radius,float temp_rad,int temp_sides,float temp_start,float red, float green, float blue) {
    cen = temp_cen;
    rad = temp_rad;
    radius = temp_radius;
    sides = temp_sides;
    start_angle = temp_start;
    r = red;b = blue;g = green;
}

void Polygon::draw() {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    float p1X=cen.getX();float p1Y=cen.getY();
    for (int i = 0; i < sides; i++) {
        float dx = radius*cos(start_angle*PI/180+(float)i*(rad*PI/180)/(float)sides);
        float dy = radius*sin(start_angle*PI/180+(float)i*(rad*PI/180)/(float)sides);
        glVertex2f(p1X+dx,p1Y+dy);
    }
    glEnd();
}

void Polygon::rotate(float angle,Vec rot_cen){
    cen = ((cen-rot_cen)>>(angle*PI/180)) + rot_cen;
    start_angle = start_angle - angle;
}

void Polygon::change_size(int size){
    sides=size;
}

Line::Line(Vec temp_cen,Vec tp1, Vec tp2,int temp_type,int temp_width, float red, float green, float blue) {
    cen = temp_cen;
    p1 = cen + tp1; p2 = cen + tp2;
    type = temp_type; width = temp_width;
    r = red; g = green; b = blue;
}

void Line::move(Vec d_vec){
    cen = cen + d_vec;
    p1 = p1 + d_vec;
    p2 = p2 + d_vec;
}

void Line::rotate(float angle,Vec rot_cen){
    cen = ((cen-rot_cen) >> (angle*PI/180)) + rot_cen;
    p1 = ((p1-rot_cen) >> (angle*PI/180)) + rot_cen;
    p2 = ((p2-rot_cen) >> (angle*PI/180)) + rot_cen;
}

void Line::zoom(float scale){
    p1 = (p1-cen) * scale + cen;
    p2 = (p2-cen) * scale + cen;
}

void Line::draw() {
    glColor3f(r, g, b);
    glEnable(GL_LINE_STIPPLE);
    switch (type) {
        case 0:
            glLineStipple(0, 0xFFFF); break;
        case 1:
            glLineStipple(2, 0x0F0F); break;
        case 2:
            glLineStipple(1, 0x33FF); break;
        default:
            break;
    }
    switch (width) {
        case 1:
            glLineWidth(1); break;
        case 2:
            glLineWidth(2); break;
        case 4:
            glLineWidth(4); break;
        default:
            glLineWidth(2);
    }
    glBegin(GL_LINES);
    float x1 = p1.getX(), y1 = p1.getY(), x2 = p2.getX(), y2 = p2.getY();
    glVertex2f(x1, y1); glVertex2f(x2, y2);
    glEnd();
}
