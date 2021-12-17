#ifndef _SHAPES_H_
	#define _SHAPES_H_

	#include<iostream>
	#include<cstdio>
	#include<cstring>
	#include<cmath>
	#include<algorithm>
	#include<vector>
	#include<initializer_list>
	#ifdef __APPLE__
		#define GL_SILENCE_DEPRECATION // 取消 Warning
		#include <GLUT/glut.h> 
	#elif __linux__
		#include <GL/freeglut.h> 
	#else
		#include <GL/freeglut.h> 
		#include <windows.h>
	#endif
	#include <math.h>
	#ifdef __APPLE__
	#include <GLUT/glut.h>
	#elif _WIN32
	#include <GL/freeglut.h>
		#include <windows.h>
	#elif __linux__
		#include <GL/freeglut.h>
	#endif


	#define PI 3.14159265358979323
	
	namespace ZJY{
	
		class Vec
		{
		private:
			float x, y;
		
		public:
			Vec(float _PointX = 0.0, float _PointY = 0.0);
			float getX() { return x; }
			float getY() { return y; }
			Vec get_normal_vector();
			Vec get_unit_vector();
			// Example Overloads + operator
			// returns the sum of 2 Vec
			Vec operator+(Vec v);
		
			// Overload - on 2 Vectors
			// return thier difference Vector
			Vec operator-(Vec v);
			// Overload * operator on a float k
			// return current Vector scaled by k
			Vec operator*(float k);
			// Overload * on 2 Vectors
			// return thier inner product (scaler product)
			float operator*(Vec v);
			// Overload << on an angle
			// return current vector rotated counter clockwise
			// by this angle
			Vec operator<<(float a);
			// Overload >> on an angle
			// return current vector rotated clockwise
			// by this angle
			Vec operator>>(float a);
			bool operator==(Vec v);
			bool operator!=(Vec v);
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
			
			virtual ~Group(){};
			int gettype();
		};
		class allobjects{
		private:
		    allobjects(/* args */) {}
		    ~allobjects() {}
		    std::vector<ColoredFig> data;
		
		public:
		    static allobjects *getall(/* args */);
		    void addFig(ColoredFig fg);
		    void move1(Vec dir,int ord);
		
		    void rotate1(Vec anchor, float angle,int ord);
		    void rotate1(float angle,int ord);
		    void zoom1(Vec anchor, float k,int ord);
		    void zoom1(float k,int ord);
		    void draw();
		    
		    static void clear();
		};
		
		void ZJYmain(int argc, char *argv[]);
	}
	
	namespace jtc{
		typedef double db;
		typedef struct _color{db r,g,b;}color;
		class point; class vec;
		class figure; class shape;
		class rec; class rttri; class circle; class halfcir; class tri; class pxsbx; class quad;
		class obj;
		class all;
		
		class point{
		    public:
		        point(db x,db y); point(); ~point();
		        db x(); db y();
		        point operator+ (vec v);
		        point operator- (vec v);
		        vec operator- (point p);
		    private:
		        db x0,y0;
		};
		class vec{
		    public:
		        vec(); vec(db x,db y); ~vec();
		        db x(); db y();
		        vec operator+ (vec v);
		        vec operator- (vec v);
		        point operator+ (point p);
		        vec operator* (db k);
		        db operator* (vec v);
		        vec operator<< (db angle); // 逆时针
		        vec operator>> (db angle); // 顺时针
		    private:
		        db x0,y0;
		};
		class figure{
		    public:
		        figure(); ~figure();
		        void setCenter(point newCenter); void setAngle(db angl); void setSize(db siz);
		        db getAngle(); point getCenter(); db getSize(); void move(vec vec); void rotate(db ang); void zoom(db k);
		        virtual void draw()=0;
		    protected:
		        db angle,size; // 规定angle逆时针为正, 范围0~2*PI
		        point center;
		};
		class shape:public figure{
		    public:
		        shape(); virtual ~shape(); int getType(); virtual void draw() override; // 不能 =0, 否则不能创建对象
		    protected: color c; int type;
		};
		class rec:public shape{
		    public:
		        rec(db width,db height,color co); rec(); ~rec() override;
		        void draw() override;
		    private: db halfWidth,halfHeight;
		};
		class rttri:public shape{
		    public:
		        rttri(db h,db b,color co); rttri(); ~rttri() override;
		        void draw() override;
		    private: db height,base;
		};
		class circle:public shape{
		    public:
		        circle(db radius,color co); circle(); ~circle() override;
		        void draw() override;
		    private: db r;
		};
		class halfcir:public shape{
		    public:
		        halfcir(db radius,color co); halfcir(); ~halfcir() override;
		        void draw() override;
		    private:
		        db r;
		};
		class tri:public shape{
		    public:
		        tri(); ~tri() override; tri(vec vec1,vec vec2,vec vec3,color co);
		        void draw() override;
		    private:
		        vec v1,v2,v3;
		};
		class pxsbx:public shape{ // 平行四边形
		    public:
		        pxsbx(); ~pxsbx() override; pxsbx(vec vec1,vec vec2,color co);
		        void draw() override;
		    private:
		        vec v1,v2;
		};
		class quad:public shape{
		    public:
		        quad(); ~quad() override; quad(vec vec1,vec vec2,vec vec3,vec vec4,color co);
		        void draw() override;
		    private:
		        vec v1,v2,v3,v4;
		};
		class obj:public figure{
		    public:
		        obj(); ~obj(); obj(point centerPoint,db ang,db siz);
		        void setStatus(int sta); int getStatus();
		        void draw() override;
		        void setShape(shape* sh,vec relaLoc,db relaAngle);
		    private:
		        shape* shapes[50]; vec relativeLoc[50]; db relativeAngle[50];
		        int status; int shapeNum;
		        void update();
		};
		class all{
		    public:
		        all(); ~all(); all(int value); // 这个代表有参数的构造函数，需根据实际情况修改
		        void next();
		    private:
		        obj objs[50];
		        void draw();
		        int t;
		};
		
		
		db rand01();
		color randColor();
		void glStart();
		void setColor(color c);
		void onePoint(point p);
		void drawLine(point p1,point p2);
		
	} // using namespace jtc
	
	
	namespace NJL{
		typedef struct _Point { double x,y; } Point;
		
		//class shape
		class Shape {
		public: virtual void draw() = 0; virtual ~Shape()=0;
		protected: float r, g, b;
		};
		class Rectangle : public Shape {
		public: Rectangle(Point pt1={-.5,-.5}, Point pt2={.5,.5},
		                  float red=0, float green=0, float blue=0);
		    void draw();
		    //~Rectangle();
		private: Point p1,p2;
		};
		
		class Triangle : public Shape {
		public: Triangle(Point pt1={-.5,-.5}, Point pt2={.5,-.5},
		                 Point pt3={0,.5}, float red=0, float green=0, float blue=0);
		    void draw();
		    //~Triangle();
		private: Point p1,p2,p3;
		};
		
		class Trapezium:public Shape{
		public:Trapezium(Point pt1={(float)0,(float)0},Point pt2={(float)-0.4,(float)0},
		                 Point pt3={(float)-0.3,(float)-0.1},Point pt4={(float)-0.2,(float)-0.1},
		                 float red=(float)0.1,float green=(float)0.300,float blue=(float)0.100);
		    void draw();
		    //~Trapezium();
		private:
		    Point p1,p2,p3,p4;
		};
		class Circle: public Shape{
		public:
		    Circle(Point pt1={(float)0,(float)0},double radius=0.1,
		           float red=(float)1,float green=(float)0, float blue=(float)0);
		    void draw();
		    //~Circle();
		private:Point p1; double radius;
		};
		class car{
		public:car(Point ach={0,0});
		    ~car();
		    void draw();
		    void move(Point* anc);
		private:
		    Shape* sh[4];Point anchor;
		};
		void TimeStep(int n);
		void display();
		int mymain();
	}

	namespace DLB{
		
		using namespace std;
		#define FIGITER vector<Figure*>::iterator
		#define VECITER vector<Vec>::iterator
		#define CAR 1
		#define UFO 2
		#define SPACECRAFT 3
		#define TELEPORTED 4
		#define VAN 5
	
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
	
		class Circle: public Figure{
			private:
				float radius; int Vertices;
			public:
				Circle(Vec _Anchor=Vec(0,0),float _Red=0,float _Green=0,float _Blue=0,float _radius=0.1,int _Vertices=100);
				void Draw();
				void Move(Vec Del);
				void Rotate(float Theta,Vec Spin); // Spin is center of rotate
				void Zoom(float K,Vec Spin);
		};
	
		class Line : public Figure{
	        private:
	            Vec Del;//the anchor for line is an end of the line
	        public:
	            Line(Vec _Anchor=Vec(0,0),float _Red=0,float _Green=0,float _Blue=0,Vec _Del=Vec(1.0,0.0));
	            void Draw();
	            void Move(Vec Delta);
	            void Rotate(float Theta,Vec Spin);
	            void Zoom(float K,Vec Spin);
	    };
	
	    class Quad: public Figure{
			private:
				Vec Del1,Del2,Del3,Del4;
			public:
				Quad(Vec _Anchor=Vec(0,0),float _Red=0,float _Green=0,float _Blue=0,Vec _Del1=Vec(0.1,0.1),Vec _Del2=Vec(0.1,-0.1),Vec _Del3=Vec(-0.1,-0.1),Vec _Del4=Vec(-0.1,0.1));
				void Draw();
				void Move(Vec Del);
				void Rotate(float Theta,Vec Spin);
				void Zoom(float K,Vec Spin);
		};
	
		class Trapezium: public Figure{
	        private:
	            Vec Del1,Del2,Del3,Del4;
	        public:
	            Trapezium(Vec _Anchor=Vec(0,0),float _Red=0,float _Green=0,float _Blue=0,Vec _Del1=Vec(-sqrt(3)/2.0,-1.0/2.0),Vec _Del2=Vec(sqrt(3)/2.0,-1.0/2.0),Vec _Del3=Vec(1.0/2.0,sqrt(3)/2.0),Vec _Del4=Vec(-1.0/2.0,sqrt(3)/2.0));
	            void Draw();
	            void Move(Vec Del);
	            void Rotate(float Theta,Vec Spin);
	            void Zoom(float K,Vec Spin);
	    };
	
	    class Triangle: public Figure{
			private:
				Vec Del1,Del2,Del3;
			public:
				Triangle(Vec _Anchor=Vec(0,0),float _Red=0,float _Green=0,float _Blue=0,Vec _Del1=Vec(-0.01,-0.005),Vec _Del2=Vec(0.01,-0.005),Vec _Del3=Vec(0,0.01));
				void Draw();
				void Move(Vec Del);
				void Rotate(float Theta,Vec Spin);
				void Zoom(float K,Vec Spin);
		};
	
		class Semicircle: public Figure{
			private:
				float radius;int Vertices;float DelT;
			public:
				Semicircle(Vec _Anchor=Vec(0,0),float _Red=0,float _Green=0,float _Blue=0,float _radius=0.1,int _Vertices=100,float _DelT=0);
				void Draw();
				void Move(Vec Del);
				void Rotate(float Theta,Vec Spin); // Spin is center of rotate
				void Zoom(float K,Vec spin);
		};
	
		typedef struct _Turning{
			float Del=1.0,Cup=90.0;
			float Theta=0; 
			Vec Spin=Vec(0,0);
			bool Switch=0;
		} Turning;
		typedef struct _Moving{
			const float CDel=0.01;
			Vec Del=Vec(CDel,0);
			int Cup=0,Cnt=0;
			bool Switch=0;
		} Moving;
		typedef struct _Leaving{
			Vec Del1=Vec(0.005,0);
			Vec Del2=Vec(0,0);
			Vec Del=Vec(0,-0.01);
			int Cup=20; int Cnt=0;
			double Dir=1;
			bool ReadyLeft=0;
			bool Switch=0;
		} Leaving;
		typedef struct _Decorating{
			Vec Del=Vec(0,0.005);
			int Cup=20; int Cnt=0;
			double Dir=1;
			Figure* Fig;
		} Decorating;
	
		class Group{
			protected:
				vector<Figure*> SetNormal;
				vector<Decorating> SetDecorate;
				vector<Vec> Track,laterTrack;
				VECITER NowTrack;
				Vec Anchor;
				Turning OptTurn;
				Moving OptMove;
				Leaving OptLeft;
				bool Act();
				bool Control();
				void ClearTrack();
			public:
				Group(float _PointX,float _PointY);
				void AddNormalFigure(initializer_list<Figure*> _FigList);
				void AddDecorateFigure(initializer_list<Decorating> _FigList);
				void AddTrack(initializer_list<Vec> _VecList);
				void GetStart(bool _Final);
				bool IsActing();
				void GetLeave();
				void Draw();
				virtual void DecorateAct()=0;
				virtual void DecorateControl()=0;
				virtual void DecorateLeave()=0;
				bool Update();
				virtual ~Group()=0;
		};
	
		class Ticket{
			protected:
				int Time;
				int VecType;
			public:
				Ticket();
				Ticket(int T);
				int GetTime();
				void ScanType(int VT);
	//			~Ticket();
		};
	
		class ArrivalTicket: public Ticket{
			private:
				int SlotNumber;
			public:
				ArrivalTicket(int T);
				void SetSlotNum(int SN);
				unsigned long GetSlotNum();
				void PrintTicket();
	//			~ArrivalTicket();
		};
	
		class DepartTicket: public Ticket{
			private:
				int Price;
			public:
				DepartTicket(int T);
				int SetPrice(int AT);
				int GetPrice();
				void PrintTicket();
	//			~DepartTicket();
		};
	
		class ChangeTicket: public Ticket{
			private:
				int SlotNumber1,SlotNumber2;
			public:
				ChangeTicket(int T);
				void SetSlotNum(int _SN1,int _SN2);
				int GetFirstNum();
				int GetSecondNum();
				void PrintTicket();
	//			~DepartTicket();
		};
	
		class Vehicle{
			protected:
				int ArrivalTime,DepartTime;
				ArrivalTicket *ATicket;
				DepartTicket *DTicket;
				ChangeTicket *CTicket;
				vector<Ticket*> Trash;
			public:
				Vehicle();
				virtual void ParkIn(ArrivalTicket *T)=0;
				virtual void ChangeSlot(ChangeTicket *T)=0;
				virtual void ParkOut(DepartTicket *T)=0;
				ArrivalTicket *GetATicket();
				DepartTicket *GetDTicket();
				ChangeTicket *GetCTicket();
				int GetATime();
				int GetDTime();
				virtual int GetType()=0;
				virtual ~Vehicle();
		};
	
		class Car: public Vehicle, public Group{
			private:
				const int Type=CAR;
			public:
				Car(float _PointX,float _PointY);
				static Car *GetInstance();
				static void DeleteInstance();
				void ParkIn(ArrivalTicket *T);
				void ChangeSlot(ChangeTicket *T);
				void ParkOut(DepartTicket *T);
				void DecorateAct();
				void DecorateControl();
				void DecorateLeave();
				int GetType();
				~Car();
		};
	
		//void TimeStep(int n);
		//void Display();
		//void Start();
		int mymain(int argc,char *argv[]);
	}
	
#endif
