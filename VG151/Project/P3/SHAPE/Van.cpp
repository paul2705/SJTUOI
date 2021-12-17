#include"Van.h"

using namespace DLB;
    #define fabs(a) (a>=0?a:-a)
    #define Aabs(a) (a>=0?a:270+a)
    #define EPS 1e-5
    #define FIGITER vector<Figure*>::iterator
    #define DECITER vector<Decorating>::iterator
    #define VECITER vector<Vec>::iterator
    #define VECLSTITER initializer_list<Vec>::iterator
    #define FIGLSTITER initializer_list<Figure*>::iterator
    #define FIGDLSTITER initializer_list<Decorating>::iterator

Van::Van(float _PointX,float _PointY):Vehicle(),Group(_PointX,_PointY){
    Circle *Cir1=new Circle(Vec(-0.05,-0.04)+Anchor,1.0,0.0,0.0,0.03,100);
    Decorating CirD1={Vec(0,0.005),20,0,1,Cir1};
    Circle *Cir2=new Circle(Vec(0.05,-0.04)+Anchor,1.0,0.0,0.0,0.03,100);
    Decorating CirD2={Vec(0,0.005),20,0,1,Cir2};
    Quad *Qua1=new Quad(Anchor,0.0,1.0,0.0,Vec(0.1,0.05),Vec(0.1,-0.05),Vec(-0.1,-0.05),Vec(-0.1,0.05));
    Decorating QuaD1={Vec(0,0.005),20,0,1,Qua1};
    Trapezium *Trap=new Trapezium(Vec(0.0,0.02)+Anchor,0.0,1.0,0.0,Vec(-sqrt(3)/20.0,-1.0/20.0),Vec(sqrt(3)/20.0,-1.0/20.0),Vec(1.0/20.0,sqrt(3)/20.0),Vec(-1.0/20.0,sqrt(3)/20.0));
    Decorating TrapD={Vec(0,0.005),20,0,1,Trap};
    AddNormalFigure({});
    AddDecorateFigure({QuaD1,TrapD,CirD1,CirD2});
}

Van *Van::GetInstance(){
    static Van *s=NULL;
    if (s==NULL) s=new Van(-1,0.7);
    return s;
}

void Van::DeleteInstance(){
    Van *s=Van::GetInstance();
    if (s!=NULL) delete s;
    s=NULL;
}

int Van::GetType(){ return Type; }

void Van::ParkIn(ArrivalTicket *T){ 
    if (ArrivalTime==-1){
        ArrivalTime=T->GetTime();
        ATicket=T;
    }
    else {
        Trash.push_back(T);
        ATicket=T;
    }
}

void Van::ChangeSlot(ChangeTicket *T){
    if (CTicket==NULL) CTicket=T;
    else {
        Trash.push_back(CTicket);
        CTicket=T;
    }
}

void Van::ParkOut(DepartTicket *T){ 
    if (DepartTime==-1){
        DepartTime=T->GetTime();
        DTicket=T;
    }
    else{
        Trash.push_back(DTicket);
        DTicket=T;
    }
}

void Van::DecorateAct(){
    for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
        it->Fig->Move(it->Del*it->Dir);
        it->Cnt++;
    }
}

void Van::DecorateControl(){
    for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
        if (it->Cnt>=it->Cup){
            it->Dir*=-1; it->Cnt=0;
        }
    }
}

void Van::DecorateLeave(){
    static Vec Del1=Vec(0.03,0),Del2=Vec(0,0);
    static Vec Del=Vec(0,-0.005);
    for (FIGITER it=SetNormal.begin();it!=SetNormal.end();it++){
        (*it)->Move(Del1);
        (*it)->Move(Del2);
    }
    for (DECITER it=SetDecorate.begin();it!=SetDecorate.end();it++){
        (*it).Fig->Move(Del1);
        (*it).Fig->Move(Del2); 
    }
    Del2=Del2+Del;
}

Van::~Van(){ 
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