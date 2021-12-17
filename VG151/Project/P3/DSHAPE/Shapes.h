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
		#include <GLUT/glut.h> 
	#elif __linux__
		#include <GL/freeglut.h> 
	#else
		#include <GL/freeglut.h> 
		#include <windows.h>
	#endif
	using namespace std;
	#define PI acos(-1)
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
			Group(float _X,float _Y);
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
			Car(float _X,float _Y);
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


#endif
