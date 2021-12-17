#ifdef __APPLE__
	#include <GLUT/glut.h> 
#elif __linux__
	#include <GL/freeglut.h> 
#else
	#include <GL/freeglut.h> 
	#include <windows.h>
#endif
#ifndef FIGURES_H
#define FIGURES_H
#include <cmath>
#include <vector>
#define PI 3.14159265358979323846
enum vehtype
{
	_Car,
	_UFO,
	_Rocket,
	_Teleported
}; // 0 for Car, 1 for UFO ...
class Vec
{
private:
	float x, y;

public:
	Vec(float _x = 0.0, float _y = 0.0)
	{
		x = _x;
		y = _y;
	}
	float getX() { return x; }
	float getY() { return y; }
	Vec get_normal_vector()
	{
		float r = (float)sqrt(x * x + y * y);
		return Vec(-y / r, x / r);
	}
	// Example Overloads + operator
	// returns the sum of 2 Vec
	Vec operator+(Vec v)
	{
		return Vec(x + v.getX(), y + v.getY());
	}

	// Overload - on 2 Vectors
	// return thier difference Vector
	Vec operator-(Vec v)
	{
		return Vec(x - v.getX(), y - v.getY());
	}
	// Overload * operator on a float k
	// return current Vector scaled by k
	Vec operator*(float k)
	{
		return Vec(x * k, y * k);
	}
	// Overload * on 2 Vectors
	// return thier inner product (scaler product)
	float operator*(Vec v)
	{
		return x * v.getX() + y * v.getY();
	}
	// Overload << on an angle
	// return current vector rotated counter clockwise
	// by this angle
	Vec operator<<(float a)
	{
		return Vec(x * cos(a) - y * sin(a), y * cos(a) + x * sin(a));
	}
	// Overload >> on an angle
	// return current vector rotated clockwise
	// by this angle
	Vec operator>>(float a)
	{
		return Vec(x * cos(a) + y * sin(a), y * cos(a) - x * sin(a));
	}
};

class Figure
{
protected:
	Vec anchor;

public:
	Figure() : anchor(0, 0) {}

	Vec getAnchor() { return anchor; }
	void setAnchor(Vec a) { anchor = a; }
	virtual void draw() = 0;
	virtual void move(Vec dir) = 0;
	virtual void rotate(float angle) = 0;
	virtual void zoom(float k) = 0;

	virtual ~Figure() {}
};

class ColoredFig : public Figure
{
protected:
	std::vector<Vec> points;
	float r, g, b;

public:
	ColoredFig() {}
	void draw();			  // Draw
	void move(Vec dir);		  // Move
	void rotate(float angle); // Rotate
	void zoom(float k);		  // Zoom
	virtual ~ColoredFig() {}
};
class Line : public ColoredFig
{
public:
	Line(Vec pt1 = {0.0, 0.0}, Vec pt2 = {.1, .1}, float Linewidth = 0.01, float red = 0, float green = 0, float blue = 0);
	~Line() {}
};
class Circle : public ColoredFig
{
public:
	Circle(Vec pt1 = {0.0, 0.0}, float radius = 1.0, float red = 0, float green = 0, float blue = 0);
	~Circle() {}

private:
	Vec c;
	double R;
};

class Rect : public ColoredFig
{
public:
	Rect(Vec pt1 = {-.5, -.5}, Vec pt2 = {.5, .5},
		 float r = 0, float g = 0, float b = 0);
	~Rect() {}
};

class Teleporter : public ColoredFig
{
private:
	void paint(float *r, float *g, float *b);

public:
	Teleporter(Vec pt1 = {-.5, -.5}, Vec pt2 = {.5, .5});
	void repaint();
	~Teleporter() {}
};

class Triangle : public ColoredFig
{
public:
	Triangle(Vec pt1 = {-.5, -.5}, Vec pt2 = {.5, -.5},
			 Vec pt3 = {0, .5}, float r = 0, float g = 0, float b = 0);
	~Triangle() {}
};

class Parallelogram : public ColoredFig
{
public:
	Parallelogram(Vec pt1 = {-.5, -.5}, Vec pt2 = {.5, -.5},
				  Vec pt3 = {0.0, .5}, float r = 0, float g = 0, float b = 0);
	// pt1 and pt2 for the opposite Vec, pt3 for another Vec
	~Parallelogram() {}
};

class Trapezium : public ColoredFig
{
public:
	Trapezium(Vec pt1 = {-1, -.5}, Vec pt2 = {1, -.5},
			  Vec pt3 = {0.5, .5}, Vec pt4 = {-0.5, .5}, float r = 0, float g = 0, float b = 0);
	// pt1,2,3,4 goes counter-clockwise of the Vec of the trapezium
	~Trapezium() {}
};

class Group : public Figure
{
protected:
	Vec centre; // The centre of the figures, if you are sure that you do not need it, just delete it
	std::vector<ColoredFig> fg;
	std::vector<Teleporter> tp;
	int vehtype = -1;
	void setFigAnchor(); // Set the anchor for all the figures
	float ratio = 0;
	int direct = 1;

public:
	Group() {}
	void draw();			  // Draw out all its figures
	void move(Vec dir);		  // Move all its figures
	void rotate(float angle); // Rotate the group as a whole.
	void zoom(float k);		  // Zoom the group as a whole.
	void spemove();
	virtual ~Group(){};
	int gettype();
};
#endif
class Car : public Group
{
private:
	/* data */
public:
	Car(Vec cen = {0, 0}, float k = 1);
	~Car() {}
};

class UFO : public Group
{
private:
	/* data */
public:
	UFO(Vec cen = {0, 0}, float k = 1);
	~UFO() {}
};
class Rocket : public Group
{
private:
	/* data */

public:
	Rocket(Vec cen = {0, 0}, float k = 1);
	~Rocket() {}
};
class Teleported : public Group
{
private:
	/* data */
public:
	Teleported(Vec cen = {0, 0}, float k = 1);
	~Teleported(){};
};
#ifdef __APPLE__
	#include <GLUT/glut.h> 
#elif __linux__
	#include <GL/freeglut.h> 
#else
	#include <GL/freeglut.h> 
	#include <windows.h>
#endif
#include <ctime>
#include <cstdlib>
void ColoredFig::draw()
{
	glColor3f(r, g, b);
	if (points.size() <= 2)
		return;
	switch (points.size())
	{
	case 3:
		glBegin(GL_TRIANGLE_STRIP);
		break;
	case 4:
		glBegin(GL_QUADS);
		break;
	default:
		glBegin(GL_POLYGON);
		break;
	}
	std::vector<Vec>::iterator it;
	for (it = points.begin(); it != points.end(); it++)
	{
		glVertex2d(it->getX(), it->getY());
	}
	glEnd();
}
void ColoredFig::move(Vec dir)
{
	std::vector<Vec>::iterator it;
	for (it = points.begin(); it != points.end(); it++)
	{
		*it = *it + dir;
	}
}
void ColoredFig::rotate(float angle)
{
	std::vector<Vec>::iterator it;
	for (it = points.begin(); it != points.end(); it++)
	{
		Vec temp = *it - anchor;
		temp = temp << angle;
		*it = anchor + temp;
	}
}
void ColoredFig::zoom(float k)
{
	std::vector<Vec>::iterator it;
	for (it = points.begin(); it != points.end(); it++)
	{
		Vec temp = *it - anchor;
		temp = temp * k;
		*it = anchor + temp;
	}
}
Line::Line(Vec pt1, Vec pt2, float Linewidth, float red, float green, float blue)
{
	r = red;
	g = green;
	b = blue;
	Vec temp = pt1 - pt2;
	Vec nv = temp.get_normal_vector();
	nv = nv * (Linewidth / 2.0);
	Vec p1 = pt1 + nv;
	Vec p2 = pt2 + nv;
	Vec p3 = pt2 - nv;
	Vec p4 = pt1 - nv;
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
	points.push_back(p4);
	setAnchor((pt1 + pt2) * 0.5);
}
Circle::Circle(Vec pt1, float radius, float red, float green, float blue)
{
	c = pt1;
	R = radius;
	r = red;
	g = green;
	b = blue;
	int n = 1024;
	for (int i = 0; i < n; i++)
	{
		points.push_back({(float)(R * cos(2 * PI * i / n) + c.getX()), (float)(R * sin(2 * PI * i / n) + c.getY())});
	}
	setAnchor(c);
}
Rect::Rect(Vec pt1, Vec pt2,
		   float red, float green, float blue)
{
	r = red;
	g = green;
	b = blue;
	points.push_back({pt1.getX(), pt1.getY()});
	points.push_back({pt2.getX(), pt1.getY()});
	points.push_back({pt2.getX(), pt2.getY()});
	points.push_back({pt1.getX(), pt2.getY()});
	setAnchor((pt1 + pt2) * 0.5);
}
Teleporter::Teleporter(Vec pt1, Vec pt2)
{
	paint(&r, &g, &b);
	points.push_back({pt1.getX(), pt1.getY()});
	points.push_back({pt2.getX(), pt1.getY()});
	points.push_back({pt2.getX(), pt2.getY()});
	points.push_back({pt1.getX(), pt2.getY()});
	setAnchor((pt1 + pt2) * 0.5);
}
void Teleporter::paint(float *r, float *g, float *b)
{
	*r = (float)rand() / (float)RAND_MAX;
	*g = (float)rand() / (float)RAND_MAX;
	*b = (float)rand() / (float)RAND_MAX;
}
void Teleporter::repaint()
{
	paint(&this->r, &this->g, &this->b);
}
Triangle::Triangle(Vec pt1, Vec pt2, Vec pt3,
				   float red, float green, float blue)
{
	r = red;
	g = green;
	b = blue;
	points.push_back(pt1);
	points.push_back(pt2);
	points.push_back(pt3);
	setAnchor((pt1 + pt2 + pt3) * (1 / 3));
}

Parallelogram::Parallelogram(Vec pt1, Vec pt2, Vec pt3, float red, float green, float blue)
{
	r = red;
	g = green;
	b = blue;
	points.push_back(pt1);
	points.push_back(pt3);
	points.push_back(pt2);
	points.push_back({pt1.getX() + pt2.getX() - pt3.getX(), pt1.getY() + pt2.getY() - pt3.getY()});
	setAnchor((pt1 + pt2) * 0.5);
}

Trapezium::Trapezium(Vec pt1, Vec pt2, Vec pt3, Vec pt4, float red, float green, float blue)
{
	r = red;
	g = green;
	b = blue;
	points.push_back(pt1);
	points.push_back(pt2);
	points.push_back(pt3);
	points.push_back(pt4);
	setAnchor((pt1 + pt2 + pt3 + pt4) * 0.25);
}

void Group::draw()
{
	spemove();
	std::vector<ColoredFig>::iterator it;
	for (it = fg.begin(); it != fg.end(); it++)
	{
		it->draw();
	}
	std::vector<Teleporter>::iterator it2;
	for (it2 = tp.begin(); it2 != tp.end(); it2++)
	{
		it2->draw();
	}
}

void Group::move(Vec dir)
{
	std::vector<ColoredFig>::iterator it;
	for (it = fg.begin(); it != fg.end(); it++)
	{
		it->move(dir);
	}
}

void Group::rotate(float angle)
{
	setFigAnchor(); // Ensure that all the figures rotate based on the same anchor i.g. the anchor of the Group
	std::vector<ColoredFig>::iterator it;
	for (it = fg.begin(); it != fg.end(); it++)
	{
		it->rotate(angle);
	}
}

void Group::zoom(float k)
{
	setFigAnchor(); // Ensure that all the figures zoom based on the same anchor i.g. the anchor of the Group
	std::vector<ColoredFig>::iterator it;
	for (it = fg.begin(); it != fg.end(); it++)
	{
		it->zoom(k);
	}
}

void Group::setFigAnchor()
{
	std::vector<ColoredFig>::iterator it;
	for (it = fg.begin(); it != fg.end(); it++)
	{
		it->setAnchor(anchor);
	}
}
int Group::gettype()
{
	return vehtype;
}

void Group::spemove()
{
	std::vector<Teleporter>::iterator it2;
	switch (vehtype)
	{
	case _Car:
		break;

	case _UFO:
		rotate(0.05);
		break;
	case _Rocket:
		zoom(1 + direct * 0.005);
		ratio += direct * 0.005;
		if ((ratio >= 0.2) || (ratio <= -0.15))
			direct = -direct;
		break;
	case _Teleported:
		for (it2 = tp.begin(); it2 != tp.end(); it2++)
		{
			it2->repaint();
		}
	default:
		break;
	}
}
Car::Car(Vec cen, float k)
{
	anchor = cen;
	vehtype = 0;
	Rect rectn(cen + Vec{-0.3, -0.3} * k, cen + Vec{0.3, 0} * k, 1);
	fg.push_back(rectn);
	Circle wheel1(cen + Vec{-0.15, -0.27} * k, 0.1 * k);
	fg.push_back(wheel1);
	Circle wheel2(cen + Vec{0.15, -0.27} * k, 0.1 * k);
	fg.push_back(wheel2);
	Trapezium tra(cen + Vec{-0.2, 0} * k, cen + Vec{-0.1, 0.2} * k, cen + Vec{0.1, 0.2} * k, cen + Vec{0.2, 0} * k, 0, 0, 1);
	fg.push_back(tra);
}

UFO::UFO(Vec cen, float k)
{
	anchor = cen;
	vehtype = 1;
	Circle body(cen, 0.2 * k, 1, 0, 0);
	fg.push_back(body);
	Rect rectn(cen + Vec{-0.3, -0.1} * k, cen + Vec{0.3, 0} * k, 0, 0, 1);
	fg.push_back(rectn);
	Circle window1(cen + Vec{-0.1, 0.05} * k, 0.035 * k, 0, 1);
	fg.push_back(window1);
	Circle window2(cen + Vec{0.1, 0.05} * k, 0.035 * k, 0, 1);
	fg.push_back(window2);
	Circle window3(cen + Vec{0, 0.075} * k, 0.035 * k, 0, 1);
	fg.push_back(window3);
}
Rocket::Rocket(Vec cen, float k)
{
	anchor = cen;
	vehtype = 2;
	Rect body(cen + Vec{-0.1, -0.25} * k, cen + Vec{0.1, 0.25} * k, 0, 0, 1);
	fg.push_back(body);
	Triangle wing1(cen + Vec{-0.2, -0.2} * k, cen + Vec{-0.1, -0.2} * k, cen + Vec{-0.1, 0} * k, 1, 0, 0);
	fg.push_back(wing1);
	Triangle wing2(cen + Vec{0.2, -0.2} * k, cen + Vec{0.1, -0.2} * k, cen + Vec{0.1, 0} * k, 1, 0, 0);
	fg.push_back(wing2);
	Triangle head1(cen + Vec{0, 0.4} * k, cen + Vec{-0.1, 0.25} * k, cen + Vec{0.1, 0.25} * k, 1, 0, 0);
	fg.push_back(head1);
}

Teleported::Teleported(Vec cen, float k)
{
	anchor = cen;
	vehtype = 3;
	Teleporter body(cen + Vec{-0.2, -0.4} * k, cen + Vec{0.2, 0.4} * k);
	tp.push_back(body);
}

int step0;
std::vector<Group*> allobjects;

void TimeStep(int n)
{
	glutTimerFunc((unsigned int)n, TimeStep, n);
	
	
	for (auto i:allobjects){
		
		i->spemove();
	}
	glutPostRedisplay();
}
void glDraw()
{
	
	//Car r(Vec{-0.5,0});
	//r.rotate(3);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//r.draw();
	
	for (auto i:allobjects){
		i->draw();
	}
	glutSwapBuffers();
	glFlush();
}

void ex2(){
    

}


int main(int argc, char *argv[])
{
   Car c(Vec{0.5,0.5},0.75);
	Rocket a(Vec{-0.5,0},0.75);
	UFO b(Vec{0.5,0},0.75);
	allobjects.push_back(&a);
	allobjects.push_back(&b);
	allobjects.push_back(&c);
	/* initialize GLUT, using any commandline parameters passed to the program */
	glutInit(&argc, argv);
	/* setup the size, position, and display mode for new windows */
	// glutInitWindowSize(1000, 1000);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	/* create and set up a window */
	glutCreateWindow("Test");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(glDraw);
	glutTimerFunc(1, TimeStep, 1);
	/* tell GLUT to wait for events */
	glutMainLoop();
	return 0;
}

