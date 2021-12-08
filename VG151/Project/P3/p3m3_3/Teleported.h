#ifndef _TELEPORTED_H_
    #define _TELEPORTED_H_
    #include<iostream>
	#include<cstdio>
	#include<cstring>
	#include<algorithm>
	#include<vector>
	#include"Vehicle.h"
	#include"Group.h"
	using namespace std;
    

    class Teleported : public Vehicle, public Group{
        private:
            const int Type=TELEPORTED;
        public:
            Teleported(float _X,float _Y);
            static Teleported *GetInstance(){
                static Teleported *s=NULL;
                if (s==NULL) s=new Teleported(-1,-0.4);
                return s;
            }
            static void DeleteInstance(){
                Teleported *s=Teleported::GetInstance();
                if (s!=NULL) delete s;
                s=NULL;
            }
        void ParkIn(ArrivalTicket *T);
		void ParkOut(DepartTicket *T);
		void DecorateLeave();//zoom and rotate to present an image of leaving
        void ReadyLeave();//change into the reverse pattern
		int GetType();
        void DecorateAct();
		void DecorateControl();
		~Teleported();
    };

#endif
