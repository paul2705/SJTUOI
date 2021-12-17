#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#ifdef __APPLE__
	#include <GLUT/glut.h> 
#elif __linux__
	#include <GL/freeglut.h> 
#else
	#include <GL/freeglut.h> 
	#include <windows.h>
#endif
#include"Shapes.h"
using namespace std;
#define PI acos(-1)
#define fabs(a) (a>=0?a:-a)
#define Aabs(a) (a>=0?a:270+a)
#define EPS 1e-5
#define FIGITER vector<Figure*>::iterator
#define DECITER vector<Decorating>::iterator
#define VECITER vector<Vec>::iterator
#define VECLSTITER initializer_list<Vec>::iterator
#define FIGLSTITER initializer_list<Figure*>::iterator
#define FIGDLSTITER initializer_list<Decorating>::iterator

DVec::DVec(float X,float Y){ x=X; y=Y; }

float DVec::GetX(){ return x; }

float DVec::GetY(){ return y; }

DVec DVec::operator + (Vec &a){ return Vec(x+a.GetX(),y+a.GetY()); }

DVec DVec::operator - (Vec &a){ return Vec(x-a.GetX(),y-a.GetY()); }

DVec DVec::operator * (float k){ return Vec(x*k,y*k); }

DVec DVec::operator / (float k){ return Vec(x/k,y/k); }

float DVec::operator * (Vec &a){ return x*a.GetX()+y*a.GetY(); }

DVec DVec::operator ^ (Vec &a){ return Vec(x*a.GetX()-y*a.GetY(),y*a.GetX()+x*a.GetY()); }

DVec DVec::operator << (float theta){
	float tx=(float)cos(theta),ty=(float)sin(theta);
	return Vec(tx,ty)^(*this);
}

DVec DVec::operator >> (float theta){
	float tx=(float)cos(-theta),ty=(float)sin(theta);
	return Vec(tx,ty)^(*this);
}



DVec DFigure::GetAnchor(){ return Anchor; }

void DFigure::SetAnchor(DVec a){ Anchor=a; }



DCircle::DCircle(DVec _Anchor,float _Red,float _Green,float _Blue,float _radius,int _Vertices){
	Anchor=_Anchor;
	R=_Red; G=_Green; B=_Blue; 
	radius=_radius; 
    Vertices=_Vertices;
}

void DCircle::Draw(){
	float BaseX=Anchor.GetX(),BaseY=Anchor.GetY();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(R,G,B);
		glVertex2f(BaseX,BaseY);
        for (int i = 0; i <= Vertices; i++)
        {
            glVertex2f(BaseX+radius*cosf(i*2.0*PI/Vertices),BaseY+radius*sinf(i*2.0*PI/Vertices));
        }	
	glEnd();
	
}

void Circle::Move(Vec Del){ Anchor=Anchor+Del; }

void Circle::Rotate(float Theta,Vec Spin){
	Theta*=PI/180.0;
	Anchor=((Anchor-Spin)<<Theta)+Spin;
}

void Circle::Zoom(float K,Vec Spin){
	Anchor=(Anchor-Spin)*K+Spin;
	radius=radius*K;
}

Line::Line(Vec _Anchor,float _Red,float _Green,float _Blue,Vec _Del){
    Anchor=_Anchor;R=_Red;G=_Green;B=_Blue;
    Del=_Del;
}



void Line::Draw(){
    float BaseX=Anchor.GetX(),BaseY=Anchor.GetY();
    glBegin(GL_LINES);
        glColor3f(R,G,B);
        glVertex2f(BaseX,BaseY);
        glVertex2f(BaseX+Del.GetX(),BaseY+Del.GetY());
    glEnd(); 
    glBegin(GL_POINT);
        glColor3f(0.0,0.0,0.0);
        glVertex2f(BaseX,BaseY);
    glEnd(); 
}

void Line::Move(Vec Delta){
    Anchor=Anchor+Delta;
}

void Line::Rotate(float Theta,Vec Spin){
    Theta*=PI/180.0;
    Vec a_s=Anchor-Spin;
    Vec new_a_s=a_s<<Theta;
    Anchor=new_a_s+Spin;
    Del=Del<<Theta;
}

void Line::Zoom(float K,Vec Spin){
    Vec del=Anchor-Spin;
    del=del*K;
    Anchor=Spin+del;
    Del=Del*K;
}



Quad::Quad(Vec _Anchor,float _Red,float _Green,float _Blue,Vec _Del1,Vec _Del2,Vec _Del3, Vec _Del4){
    Anchor=_Anchor;
    R=_Red; G=_Green; B=_Blue; 
    Del1=_Del1; Del2=_Del2; Del3=_Del3; Del4=_Del4;
}

void Quad::Draw(){
    float BaseX=Anchor.GetX(),BaseY=Anchor.GetY();
    glBegin(GL_QUADS);
        glColor3f(R,G,B);
        glVertex3f(BaseX+Del1.GetX(),BaseY+Del1.GetY(),0.0f);
        glVertex3f(BaseX+Del2.GetX(),BaseY+Del2.GetY(),0.0f);
        glVertex3f(BaseX+Del3.GetX(),BaseY+Del3.GetY(),0.0f);
        glVertex3f(BaseX+Del4.GetX(),BaseY+Del4.GetY(),0.0f);
    glEnd(); 
}

void Quad::Move(Vec Del){ Anchor=Anchor+Del; }

void Quad::Rotate(float Theta,Vec Spin){
    Theta*=PI/180.0;
    Anchor=((Anchor-Spin)<<Theta)+Spin;
    Del1=Del1<<Theta; Del2=Del2<<Theta; Del3=Del3<<Theta;Del4=Del4<<Theta;
}

void Quad::Zoom(float K,Vec Spin){
    Anchor=(Anchor-Spin)*K+Spin;
    Del1=Del1*K; Del2=Del2*K; Del3=Del3*K;Del4=Del4*K;
}



Trapezium::Trapezium(Vec _Anchor,float _Red,float _Green,float _Blue,Vec _Del1,Vec _Del2,Vec _Del3,Vec _Del4){
    Anchor=_Anchor;
    R=_Red;G=_Green;B=_Blue;
    Del1=_Del1;Del2=_Del2;Del3=_Del3;Del4=_Del4;
}

void Trapezium::Draw(){
    float BaseX=Anchor.GetX(),BaseY=Anchor.GetY();
    glBegin(GL_POLYGON);
        glColor3f(R,G,B);
        glVertex3f(BaseX+Del1.GetX(),BaseY+Del1.GetY(),0.0f);
        glVertex3f(BaseX+Del2.GetX(),BaseY+Del2.GetY(),0.0f);
        glVertex3f(BaseX+Del3.GetX(),BaseY+Del3.GetY(),0.0f);
        glVertex3f(BaseX+Del4.GetX(),BaseY+Del4.GetY(),0.0f);
    glEnd();
    glBegin(GL_POINTS);
        glColor3f(1.0,0.0,1.0);
        glVertex2f(BaseX,BaseY);
    glEnd();

}

void Trapezium::Move(Vec Del){ Anchor=Anchor+Del;}

void Trapezium::Rotate(float Theta,Vec Spin){
    Theta*=PI/180.0;
    Vec a_s=Anchor-Spin;
    Vec new_a_s=a_s<<Theta;
    Anchor=new_a_s+Spin;
    Del1=(Del1<<Theta); Del2=(Del2<<Theta); Del3=(Del3<<Theta); Del4=(Del4<<Theta);
}

void Trapezium::Zoom(float K,Vec Spin){
    Anchor=(Anchor-Spin)*K+Spin;
    Del1=Del1*K;Del2=Del2*K;Del3=Del3*K;Del4=Del4*K;
}



Triangle::Triangle(Vec _Anchor,float _Red,float _Green,float _Blue,Vec _Del1,Vec _Del2,Vec _Del3){
    Anchor=_Anchor;
    R=_Red; G=_Green; B=_Blue; 
    Del1=_Del1; Del2=_Del2; Del3=_Del3;
}

void Triangle::Draw(){
    float BaseX=Anchor.GetX(),BaseY=Anchor.GetY();
    glBegin(GL_TRIANGLES);
        glColor3f(R,G,B);
        glVertex3f(BaseX+Del1.GetX(),BaseY+Del1.GetY(),0.0f);
        glVertex3f(BaseX+Del2.GetX(),BaseY+Del2.GetY(),0.0f);
        glVertex3f(BaseX+Del3.GetX(),BaseY+Del3.GetY(),0.0f);
    glEnd();
    glBegin(GL_POINTS);
        glColor3f(0.0,0.0,1.0);
        glVertex2f(BaseX,BaseY);
    glEnd(); 
    glBegin(GL_POINTS);
        glColor3f(1.0,0.0,0.0);
        glVertex2f(-0.2,-0.2); glVertex2f(-0.2,-0.1); glVertex2f(-0.2,0); glVertex2f(-0.2,0.1); glVertex2f(-0.2,0.2);
        glVertex2f(-0.1,-0.2); glVertex2f(-0.1,-0.1); glVertex2f(-0.1,0); glVertex2f(-0.1,0.1); glVertex2f(-0.1,0.2);
        glVertex2f(0,-0.2); glVertex2f(0,-0.1); glVertex2f(0,0); glVertex2f(0,0.1); glVertex2f(0,0.2);
        glVertex2f(0.1,-0.2); glVertex2f(0.1,-0.1); glVertex2f(0.1,0); glVertex2f(0.1,0.1); glVertex2f(0.1,0.2);
        glVertex2f(0.2,-0.2); glVertex2f(0.2,-0.1); glVertex2f(0.2,0); glVertex2f(0.2,0.1); glVertex2f(0.2,0.2);
    glEnd(); 
}

void Triangle::Move(Vec Del){ Anchor=Anchor+Del; }

void Triangle::Rotate(float Theta,Vec Spin){
    Theta*=PI/180.0;
    Anchor=((Anchor-Spin)<<Theta)+Spin;
    Del1=Del1<<Theta; Del2=Del2<<Theta; Del3=Del3<<Theta;
}

void Triangle::Zoom(float K,Vec Spin){
    Anchor=(Anchor-Spin)*K+Spin;
    Del1=Del1*K; Del2=Del2*K; Del3=Del3*K;
}


Semicircle::Semicircle(Vec _Anchor,float _Red,float _Green,float _Blue,float _radius,int _Vertices,float _DelT){
    Anchor=_Anchor;
    R=_Red; G=_Green; B=_Blue; 
    radius=_radius; 
    Vertices=_Vertices;
    DelT=_DelT;
    
}

void Semicircle::Draw(){
    float BaseX=Anchor.GetX(),BaseY=Anchor.GetY();
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(R,G,B);
        glVertex2f(BaseX,BaseY);
        for (int i = 0; i <= Vertices; i++)
        {
            glVertex2f(BaseX+radius*cosf((i*PI/Vertices)+DelT),BaseY+radius*sinf((i*PI/Vertices)+DelT));
        }   
    glEnd(); 
    
}

void Semicircle::Move(Vec Del){ Anchor=Anchor+Del;}

void Semicircle::Rotate(float Theta,Vec Spin){
    Theta*=PI/180.0;
    Anchor=((Anchor-Spin)<<Theta)+Spin;
    DelT=DelT+Theta;
}

void Semicircle::Zoom(float K,Vec Spin){
    Anchor=(Anchor-Spin)*K+Spin;
    radius=radius*K;
}



Group::Group(float _X,float _Y){
    SetNormal.clear(); SetDecorate.clear();
    Anchor=Vec(_X,_Y);
    Track.push_back(Anchor); 
}

void Group::AddNormalFigure(initializer_list<Figure*> _FigList){
    for (FIGLSTITER it=_FigList.begin();it!=_FigList.end();it++) SetNormal.push_back((*it));
}

void Group::AddDecorateFigure(initializer_list<Decorating> _FigList){
    for (FIGDLSTITER it=_FigList.begin();it!=_FigList.end();it++) SetDecorate.push_back((*it));
}

void Group::AddTrack(initializer_list<Vec> _VecList){
    if (IsActing()){
        for (VECLSTITER it=_VecList.begin();it!=_VecList.end();it++) laterTrack.push_back((*it));
        return;
    }
    for (VECLSTITER it=_VecList.begin();it!=_VecList.end();it++) Track.push_back((*it));
}

void Group::ClearTrack(){ Track.clear(); }

void Group::GetStart(bool _Final){
    if (_Final) OptLeft.ReadyLeft=1;
    if (IsActing()) return;
    NowTrack=Track.begin(); NowTrack++;
    OptMove.Switch=1; OptTurn.Switch=0;
    OptMove.Cnt=0;
    Vec _thisTmp=((*NowTrack)-Anchor);
    if (fabs(_thisTmp.GetY())>=fabs(_thisTmp.GetX())) OptMove.Cup=_thisTmp.GetY()/OptMove.CDel;
    else OptMove.Cup=_thisTmp.GetX()/OptMove.CDel;
    OptMove.Cup=fabs(OptMove.Cup);
    OptMove.Del=Vec(_thisTmp.GetX()/(float)OptMove.Cup,_thisTmp.GetY()/(float)OptMove.Cup);
}

void Group::GetLeave(){ OptLeft.Switch=1; }

void Group::Draw(){
    for (FIGITER it=SetNormal.begin();it!=SetNormal.end();it++){
        (*it)->Draw();
    }
    for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
        (*it).Fig->Draw();
    }
    glFlush();
}

bool Group::IsActing(){ return OptMove.Switch|OptTurn.Switch|OptLeft.Switch; }

bool Group::Act(){
    if (OptMove.Switch){
        Anchor=Anchor+OptMove.Del;
        for (FIGITER it=SetNormal.begin();it!=SetNormal.end();it++){
            (*it)->Move(OptMove.Del);
        }
        for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
            (*it).Fig->Move(OptMove.Del);
        }
        OptMove.Cnt++; 
        return 1;
    }
    if (OptTurn.Switch){
        for (FIGITER it=SetNormal.begin();it!=SetNormal.end();it++){
            (*it)->Rotate(OptTurn.Del,OptTurn.Spin);
        }
        for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
            (*it).Fig->Rotate(OptTurn.Del,OptTurn.Spin);
            (*it).Del=(*it).Del<<(OptTurn.Del*PI/180.0);
        }
        OptTurn.Theta+=fabs(OptTurn.Del);
        return 1;
    }
    if (OptLeft.Switch){
        DecorateLeave();
        return 1;
    }
    return 0;
}

bool Group::Control(){
    if (NowTrack==Track.end()){
        OptTurn.Switch=OptMove.Switch=0;
        ClearTrack();
        if (laterTrack.size()){
            Track=laterTrack; laterTrack.clear(); GetStart(0);
        }
        if (OptLeft.ReadyLeft) OptLeft.Switch=1;
        return 0;
    }
    if (OptTurn.Switch&&OptTurn.Theta>=OptTurn.Cup){
        OptTurn.Switch=0; OptMove.Switch=1; 
        OptMove.Cnt=0;
        Vec _thisTmp=((*NowTrack)-Anchor);
        while (fabs(_thisTmp.GetX())+fabs(_thisTmp.GetY())<=EPS){
            NowTrack++;
            _thisTmp=((*NowTrack)-Anchor);
        }
        if (fabs(_thisTmp.GetY())>=fabs(_thisTmp.GetX())) OptMove.Cup=_thisTmp.GetY()/OptMove.CDel;
        else OptMove.Cup=_thisTmp.GetX()/OptMove.CDel;
        OptMove.Cup=fabs(OptMove.Cup);
        OptMove.Del=Vec(_thisTmp.GetX()/(float)OptMove.Cup,_thisTmp.GetY()/(float)OptMove.Cup);
        return 1;
    }
    else if (OptMove.Switch&&OptMove.Cnt>=OptMove.Cup){
        OptMove.Switch=0; OptTurn.Switch=1; 
        float _formerDir=fabs(OptMove.Del.GetX())<=EPS?1e9:OptMove.Del.GetY()/OptMove.Del.GetX();
        OptTurn.Theta=0; OptTurn.Spin=Anchor;
        NowTrack++; if (NowTrack==Track.end()) return 0;
        float _laterDir=fabs(((*NowTrack)-Anchor).GetX())<=EPS?1e9:((*NowTrack)-Anchor).GetY()/((*NowTrack)-Anchor).GetX();
        float _thisTmp=(1+_laterDir*_formerDir);
        OptTurn.Cup=fabs(_thisTmp)<=EPS?90.0:atan((_laterDir-_formerDir)/(1+_laterDir*_formerDir))/PI*180.0;
        if (fabs(OptTurn.Cup)<=EPS){
            OptTurn.Cup=0;
            return Control();
        }
        OptTurn.Del=(OptTurn.Cup>=0?1:-1); OptTurn.Cup=fabs(OptTurn.Cup);
        return 1;
    }
    return 0;
}

bool Group::Update(){
    bool _thisFlag=0;
    _thisFlag|=Control(); DecorateControl();
    _thisFlag|=Act(); DecorateAct();
    return _thisFlag;
}

Group::~Group(){}



Car::Car(float _X,float _Y):Vehicle(),Group(_X,_Y){
    Circle *Cir1=new Circle(Vec(-0.05,-0.04)+Anchor,1.0,0.0,0.0,0.03,100);
    Circle *Cir2=new Circle(Vec(0.05,-0.04)+Anchor,1.0,0.0,0.0,0.03,100);
    Quad *Qua1=new Quad(Anchor,0.0,1.0,0.0,Vec(0.1,0.05),Vec(0.1,-0.05),Vec(-0.1,-0.05),Vec(-0.1,0.05));
    Trapezium *Trap=new Trapezium(Vec(0.0,0.02)+Anchor,0.0,1.0,0.0,Vec(-sqrt(3)/20.0,-1.0/20.0),Vec(sqrt(3)/20.0,-1.0/20.0),Vec(1.0/20.0,sqrt(3)/20.0),Vec(-1.0/20.0,sqrt(3)/20.0));
    Quad *Qua2=new Quad(Vec(-0.07,0.08)+Anchor,0.0,0.0,1.0,Vec(0.01,0.005),Vec(0.01,-0.005),Vec(-0.01,-0.005),Vec(-0.01,0.005));
    Decorating QuaD2={Vec(0,0.005),20,0,1,Qua2};
    Quad *Qua3=new Quad(Vec(-0.085,0.07)+Anchor,0.0,0.0,1.0,Vec(0.01,0.005),Vec(0.01,-0.005),Vec(-0.01,-0.005),Vec(-0.01,0.005));
    Decorating QuaD3={Vec(0,0.004),25,0,1,Qua3};
    Quad *Qua4=new Quad(Vec(-0.10,0.08)+Anchor,0.0,0.0,1.0,Vec(0.01,0.005),Vec(0.01,-0.005),Vec(-0.01,-0.005),Vec(-0.01,0.005));
    Decorating QuaD4={Vec(0,0.006),15,0,1,Qua4};
    Quad *Qua5=new Quad(Vec(-0.115,0.07)+Anchor,0.0,0.0,1.0,Vec(0.01,0.005),Vec(0.01,-0.005),Vec(-0.01,-0.005),Vec(-0.01,0.005));
    Decorating QuaD5={Vec(0,0.003),30,0,1,Qua5};
    AddNormalFigure({Qua1,Trap,Cir1,Cir2});
    AddDecorateFigure({QuaD2,QuaD3,QuaD4,QuaD5});
}

Car *Car::GetInstance(){
    static Car *s=NULL;
    if (s==NULL) s=new Car(-1,-0.4);
    return s;
}

void Car::DeleteInstance(){
    Car *s=Car::GetInstance();
    if (s!=NULL) delete s;
    s=NULL;
}

int Car::GetType(){ return Type; }

void Car::ParkIn(ArrivalTicket *T){ 
    if (ArrivalTime==-1){
        ArrivalTime=T->GetTime();
        ATicket=T;
    }
    else {
        Trash.push_back(T);
        ATicket=T;
    }
}

void Car::ChangeSlot(ChangeTicket *T){
    if (CTicket==NULL) CTicket=T;
    else {
        Trash.push_back(CTicket);
        CTicket=T;
    }
}

void Car::ParkOut(DepartTicket *T){ 
    if (DepartTime==-1){
        DepartTime=T->GetTime();
        DTicket=T;
    }
    else{
        Trash.push_back(DTicket);
        DTicket=T;
    }
}

void Car::DecorateAct(){
    for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
        it->Fig->Move(it->Del*it->Dir);
        it->Cnt++;
    }
}

void Car::DecorateControl(){
    for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
        if (it->Cnt>=it->Cup){
            it->Dir*=-1; it->Cnt=0;
        }
    }
}

void Car::DecorateLeave(){
    for (FIGITER it=SetNormal.begin();it!=SetNormal.end();it++){
        (*it)->Zoom(0.95,Anchor);
        (*it)->Rotate(5,Anchor);
    }
    for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
        (*it).Fig->Zoom(0.95,Anchor);
        (*it).Fig->Rotate(5,Anchor);
    }
}

Car::~Car(){ 
    delete ATicket; delete DTicket; if (CTicket!=NULL) delete CTicket;
    for (vector<Ticket*>::iterator it=Trash.begin();it!=Trash.end();it++){
        Ticket* tmp=(*it);
        delete tmp; 
    }
    for (FIGITER it=SetNormal.begin();it!=SetNormal.end();it++){
        Figure *_thisTmp=*it;
        delete _thisTmp;
    }
    for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
        Figure *_thisTmp=it->Fig;
        delete _thisTmp;
    }
}



Vehicle::Vehicle(){
    ArrivalTime=-1; DepartTime=-1;
    ATicket=NULL; DTicket=NULL; CTicket=NULL;
    Trash.clear();
}

int Vehicle::GetATime(){ return ArrivalTime; }

int Vehicle::GetDTime(){ return DepartTime; }

ArrivalTicket *Vehicle::GetATicket(){ return ATicket; }

DepartTicket *Vehicle::GetDTicket(){ return DTicket; }

ChangeTicket *Vehicle::GetCTicket(){ return CTicket; }

Vehicle::~Vehicle(){}



Ticket::Ticket(){ Time=0; }

Ticket::Ticket(int T){ Time=T; }

int Ticket::GetTime(){ return Time; }

void Ticket::ScanType(int VT){ VecType=VT; }

ArrivalTicket::ArrivalTicket(int T){ SlotNumber=-1; Time=T; }

void ArrivalTicket::SetSlotNum(int SN){ SlotNumber=SN; }

unsigned long ArrivalTicket::GetSlotNum(){ return (unsigned long)SlotNumber; }

void ArrivalTicket::PrintTicket(){
    printf("CarType:%d ArrivalTime:%d SlotNumber:%d\n",VecType,Time,SlotNumber);
}

DepartTicket::DepartTicket(int T){ Price=-1; Time=T; }

int DepartTicket::SetPrice(int AT){ return Price=(Time-AT)*10; }

int DepartTicket::GetPrice(){ return Price; }

void DepartTicket::PrintTicket(){
    printf("CarType:%d DuringTime:%d Price:%d\n",VecType,Price/10,Price);
}

ChangeTicket::ChangeTicket(int T){ SlotNumber1=SlotNumber2=-1; Time=T; }

void ChangeTicket::SetSlotNum(int _SN1,int _SN2){ SlotNumber1=_SN1,SlotNumber2=_SN2; }

int ChangeTicket::GetFirstNum(){ return SlotNumber1; }

int ChangeTicket::GetSecondNum(){ return SlotNumber2; }

void ChangeTicket::PrintTicket(){
    printf("CarType:%d Change Slot from %d to %d\n",VecType,SlotNumber1,SlotNumber2);
}




void TimeStep(int n){
    glutTimerFunc((unsigned int)n,TimeStep,n); 
    glutPostRedisplay();
}

void Display(){
    Group *x=Car::GetInstance();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    x->Update(); x->Draw();
}

void Start(){
    Car *x=Car::GetInstance();
    x->AddTrack({Vec(-0.8,-0.4),Vec(-0.8,0),Vec(0.5,0),Vec(0.5,0.3)});
    x->AddTrack({Vec(-0.4,0.3),Vec(-0.35,0.35),Vec(-0.3,0.4),Vec(-0.3,0.6)});
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
    Car::DeleteInstance();
    return 0;
}

