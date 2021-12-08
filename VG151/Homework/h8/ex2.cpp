#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<ctime>
#ifdef __APPLE__
	#include <GLUT/glut.h> 
#elif _WIN32
	#include <GL/freeglut.h> 
	#include <windows.h>
#elif __linux__
	#include <GL/freeglut.h> 
#endif
#define PI acos(-1)
using namespace std;
class Vec{
		private:
			float x,y;
		public:
			Vec(float X=0,float Y=0);
			float GetX();
			float GetY();
			Vec operator + (Vec &a);
			Vec operator - (Vec &a);
			Vec operator * (float k); // zoom the vector
			Vec operator / (float k);
			float operator * (Vec &a); // inner product 
			Vec operator ^ (Vec &a); // outer product
			Vec operator << (float theta); // rotated counter clockwise
			Vec operator >> (float theta); // rotated clockwise
	};

	class Figure{
		protected:
			Vec Anchor;
			float R,G,B;
		public:
			Figure():Anchor(0,0){};
			Vec GetAnchor();
			void SetAnchor(Vec a);
			virtual void Draw()=0;
			virtual void Move(Vec Delta)=0;
			virtual void Rotate(float Theta,Vec Spin)=0;
			virtual void Zoom(float K,Vec Spin)=0;
			virtual ~Figure(){};
	};
Vec::Vec(float X,float Y){ x=X; y=Y; }

float Vec::GetX(){ return x; }

float Vec::GetY(){ return y; }

Vec Vec::operator + (Vec &a){ return Vec(x+a.GetX(),y+a.GetY()); }

Vec Vec::operator - (Vec &a){ return Vec(x-a.GetX(),y-a.GetY()); }

Vec Vec::operator * (float k){ return Vec(x*k,y*k); }

Vec Vec::operator / (float k){ return Vec(x/k,y/k); }

float Vec::operator * (Vec &a){ return x*a.GetX()+y*a.GetY(); }

Vec Vec::operator ^ (Vec &a){ return Vec(x*a.GetX()-y*a.GetY(),y*a.GetX()+x*a.GetY()); }

Vec Vec::operator << (float theta){
	float tx=(float)cos(theta),ty=(float)sin(theta);
	return Vec(tx,ty)^(*this);
}

Vec Vec::operator >> (float theta){
	float tx=(float)cos(-theta),ty=(float)sin(theta);
	return Vec(tx,ty)^(*this);
}

Vec Figure::GetAnchor(){ return Anchor; }

void Figure::SetAnchor(Vec a){ Anchor=a; }

class Triangle: public Figure{
	private:
		Vec Del1,Del2,Del3;
	public:
		static Triangle* GetInstance(){
			static Triangle *s=NULL;
			if (s==NULL) s=new Triangle(Vec((float)0.0,(float)0.0),(float)0.0,(float)1.0,(float)0.0);
			return s;
		}
		static void DeleteInstance(){
			Triangle *s=Triangle::GetInstance();
			if (s!=NULL) delete s;
			s=NULL;
		}
		Triangle(Vec _Anchor=Vec(0,0),float _Red=0,float _Green=0,float _Blue=0,Vec _Del1=Vec((float)-0.01,(float)-0.005),Vec _Del2=Vec((float)0.01,(float)-0.005),Vec _Del3=Vec((float)0,(float)0.01));
		void Draw();
		void Move(Vec Del);
		void Rotate(float Theta,Vec Spin);
		void Zoom(float K,Vec Spin);
	};

Triangle::Triangle(Vec _Anchor,float _Red,float _Green,float _Blue,Vec _Del1,Vec _Del2,Vec _Del3){
	Anchor=_Anchor;
	R=_Red; G=_Green; B=_Blue; 
	Del1=_Del1; Del2=_Del2; Del3=_Del3;
}

void Triangle::Draw(){
	float BaseX=Anchor.GetX(),BaseY=Anchor.GetY();
	glBegin(GL_TRIANGLES);
		glColor3f(R,G,B);
		glVertex3f(BaseX+Del1.GetX(),BaseY+Del1.GetY(),(float)0.0f);
		glVertex3f(BaseX+Del2.GetX(),BaseY+Del2.GetY(),(float)0.0f);
		glVertex3f(BaseX+Del3.GetX(),BaseY+Del3.GetY(),(float)0.0f);
	glEnd(); glFlush();
}

void Triangle::Move(Vec Del){ Anchor=Anchor+Del; }

void Triangle::Rotate(float Theta,Vec Spin){
	Theta*=PI/(float)180.0;
	Anchor=((Anchor-Spin)<<Theta)+Spin;
	Del1=Del1<<Theta; Del2=Del2<<Theta; Del3=Del3<<Theta;
}

void Triangle::Zoom(float K,Vec Spin){
	Anchor=(Anchor-Spin)*K+Spin;
	Del1=Del1*K; Del2=Del2*K; Del3=Del3*K;
}


void TimeStep(int n){
	glutTimerFunc((unsigned int)n,TimeStep,n); 
	glutPostRedisplay();
}

void Display(){
	Triangle *x=Triangle::GetInstance();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	int opt=rand()%3;
	cout<<opt<<endl;
	switch (opt){
		case 0: x->Move(Vec((float)0.01,(float)0)); break;
		case 1: x->Rotate(rand()%180,Vec((float)0.3,(float)0.1)); break;
		case 2: x->Zoom(rand()/float(RAND_MAX)/10+(float)0.95,Vec((float)0,(float)0)); break;
	}
	x->Draw();
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
//    PauseScreen(1000000);
	Triangle::DeleteInstance();
	return 0;
}
