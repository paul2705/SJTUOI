#include "lab7.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <ctime>

/***
 * For this LAB, you only need to change this file.
 * To complete Task 1, you should implement the functions in MyGame class
 * To complete Task 2, you should expose interfaces to your MyBrain class in MyGame class,
 * and complete your judge function based on your MyGame class.
 */

using namespace std;

const int dx[4]={-1,0,1,0};
const int dy[4]={0,-1,0,1};
const int nx[25]={-2,-2,-2,-2,-2,-1,-1,-1,-1,-1,0,0,0,0,0,1,1,1,1,1,2,2,2,2,2};
const int ny[25]={-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2};
#define BUITER vector<MyBullet>::iterator

class MyBullet{
    private:
        Vector2<int> Pos;
        Direction Dir;
        bool Active;
    public:
        MyBullet(){}
        MyBullet(Vector2<int> Pos,Direction Dir){ this->Pos=Pos,this->Dir=Dir,this->Active=1; }
        Vector2<int> GetPos(){ return Pos; }
        void Move(){ Pos+=Vector2<int>(dx[Dir],dy[Dir])*2; }
        void DMove(){ Pos-=Vector2<int>(dx[Dir],dy[Dir])*2; }
        void Explode(){ Active=0; }
        void ReActive(){ Active=1; }
        bool Check(int Bound){ return Pos.x>=20-Bound&&Pos.y>=20-Bound&&Pos.x<Bound&&Pos.y<Bound; }
        bool Status(){ return Active; }
};

class MyTank{
    private:
        Vector2<int> Pos;
        int life;
        Direction Dir;
    public:
        MyTank(){}
        MyTank(Vector2<int> Pos,int life,Direction Dir){ this->Pos=Pos,this->life=life,this->Dir=Dir; }
        Vector2<int> GetPos(){ return Pos; }
        int GetLife() const { return life; }
        void Move(){ Pos+=Vector2<int>(dx[Dir],dy[Dir]); }
        void DMove(){ Pos-=Vector2<int>(dx[Dir],dy[Dir]); }
        void Turn(int x){ Dir=Direction((Dir+x+4)%4); }
        void Hurt(){ life--; }
        void Heal(){ life++; }
        bool Check(int Bound){ return Pos.x>=20-Bound&&Pos.y>=20-Bound&&Pos.x<Bound&&Pos.y<Bound; }
        bool Die(){ return life<=0; }
        MyBullet Shoot(){ return MyBullet(Pos+Vector2<int>(dx[Dir],dy[Dir]),Dir); }
};

struct Opt{
    Move M; double Score;
};

class MyGame : public Game {
    private:
        MyTank tank[2];
        Map map;
        vector<MyBullet> Bullet;
        int TurnNum;
    public:
        void initialize(int A_X,int A_Y,int B_X,int B_Y,Direction A_direction,Direction B_direction) override {
            tank[0]=MyTank(Vector2<int>(A_X,A_Y),5,A_direction);
            tank[1]=MyTank(Vector2<int>(B_X,B_Y),5,B_direction);
            Bullet.clear(); TurnNum=1; map.border=20; GetMap();
        }
        void move(Tank T, Move M) override {
            switch (M){
                case 0: tank[T].Move(); break;
                case 1: tank[T].Turn(-1); tank[T].Move(); break;
                case 2: tank[T].Turn(1); tank[T].Move(); break;
            }
            if (TurnNum%3==1) Bullet.push_back(tank[T].Shoot());
        }

        void Dmove(Tank T, Move M){
            switch (M){
                case 0: tank[T].DMove(); break;
                case 1: tank[T].DMove(); tank[T].Turn(1); break;
                case 2: tank[T].DMove(); tank[T].Turn(-1); break;
            }
            if (TurnNum%3==1) Bullet.pop_back();
        }
        Turn turn() override {
            TurnNum++; GetMap();
            if (tank[0].GetPos()==tank[1].GetPos()){
                if (tank[0].GetLife()>tank[1].GetLife()) return T_A_Win;
                else if (tank[0].GetLife()<tank[1].GetLife()) return T_B_Win;
                else return T_Draw;
            }
            for (BUITER it=Bullet.begin();it!=Bullet.end();it++){
                it->Move();
                for (int j=0;j<2;j++){
                    if (tank[j].GetPos()==it->GetPos()){
                        tank[j].Hurt(); tank[j].Hurt();
                        it->Explode();
                    }
                }
            }
            if ((TurnNum-1)%16==0) map.border-=1;
            for (int i=0;i<2;i++){
                if (!tank[i].Check(map.border)) tank[i].Hurt();
            }
            if (tank[0].Die()&&tank[1].Die()) return T_Draw;
            else if (tank[0].Die()) return T_B_Win;
            else if (tank[1].Die()) return T_A_Win;
            else return T_Cont;
        }
        Turn Check(){
            if (tank[0].GetPos()==tank[1].GetPos()){
                if (tank[0].GetLife()>tank[1].GetLife()) return T_A_Win;
                else if (tank[0].GetLife()<tank[1].GetLife()) return T_B_Win;
                else return T_Draw;
            }
            if (tank[0].Die()&&tank[1].Die()) return T_Draw;
            else if (tank[0].Die()) return T_B_Win;
            else if (tank[1].Die()) return T_A_Win;
            else return T_Cont;
        }
        Turn DTurn(){
            if (tank[0].GetPos()==tank[1].GetPos()){
                if (tank[0].GetLife()>tank[1].GetLife()) return TurnNum--,T_A_Win;
                else if (tank[0].GetLife()<tank[1].GetLife()) return TurnNum--,T_B_Win;
                else return TurnNum--,T_Draw;
            }
            for (int i=0;i<2;i++){
                if (!tank[i].Check(map.border)) tank[i].Heal();
            }
            if ((TurnNum-1)%16==0) map.border+=1;
            for (BUITER it=Bullet.begin();it!=Bullet.end();it++){
                for (int j=0;j<2;j++){
                    if (tank[j].GetPos()==it->GetPos()){
                        tank[j].Heal(); tank[j].Heal();
                        it->ReActive();
                    }
                }
                it->DMove();
            }
            TurnNum--;
            GetMap();
            return T_Cont;
        }
        string draw() const override {
            char c[5]={'-','+','A','B',' '};
            cout<<" Turn:"<<TurnNum<<" A:"<<tank[0].GetLife()<<" B:"<<tank[1].GetLife()<<endl;
            cout<<" Border:"<<map.border<<endl;
            for (int i=2;i<28;i++){
                for (int j=2;j<28;j++){
                        if (map.block[i][j]==0){
                        if (i-5>=20-map.border&&j-5>=20-map.border&&i-5<map.border&&j-5<map.border) printf("|%c",c[4]);
                        else printf("|%c",c[map.block[i][j]]);
                    }
                    else printf("|%c",c[map.block[i][j]]);
                }
                printf("|\n");
            }
            string s; return s;
        }
        Map getMap() const override { return map; }
        Map GetMap(){
            for (int i=0;i<30;i++){
                for (int j=0;j<30;j++) map.block[i][j]=B_Blank;
            }
            Vector2<int> Pos,Del(EXTRA_SIZE,EXTRA_SIZE);
            for (BUITER it=Bullet.begin();it!=Bullet.end();it++){
                if (!it->Check(map.border)) it->Explode();
                if (it->Check(map.border)) it->ReActive();
                if (!it->Status()) continue;
                Pos=it->GetPos()+Del;
                map.block[Pos.y][Pos.x]=B_Bullet;
            }
            Pos=tank[0].GetPos()+Del; map.block[Pos.y][Pos.x]=B_Tank_A;
            Pos=tank[1].GetPos()+Del; map.block[Pos.y][Pos.x]=B_Tank_B;
            return map;
        }
        void addBullet(const Vector2<> &pos, Direction direction) override {
            Bullet.push_back(MyBullet(pos,direction));
        }
        void setBorder(int _border) override { map.border=_border; }
        double distance(){
            Vector2<int> Del=tank[0].GetPos()-tank[1].GetPos();
            return Del.length();
        }
        double HurtDensity(int T){
            GetMap(); 
            double cnt=0;
            for (int i=0;i<25;i++){
                Vector2<int> Del(nx[i]+5,ny[i]+5);
                Vector2<int> Pos=tank[T].GetPos()+Del;
                if (i==10) cnt+=(map.block[Pos.y][Pos.x]==B_Bullet?15.0:0.0);
                else cnt+=(map.block[Pos.y][Pos.x]==B_Bullet?1.0:0.0);
            }
            return cnt;
        }
        double Evaluate(){
            double S=double(tank[0].GetLife()-tank[1].GetLife())/5.0*200.0; //血量
            if (distance()<=0) S-=rand()%50; // 斥力，拒绝太近
            if (distance()<=1) S-=rand()%70; // 斥力，拒绝太近
            if (distance()<=2) S-=rand()%90; // 斥力，拒绝太近
            else S+=double(30-distance())/30.0*100.0; // 拉近距离
            Vector2<int> Del=tank[0].GetPos()-Vector2<int>(9,10); // 吸向中心
            S+=double(15-Del.length())/15.0*120; // 吸向中心
            S+=double(HurtDensity(0)-HurtDensity(1))/18.0*80; // 防弹
            return S;
        }
};

class MyBrain : public Brain {
    private:
        MyGame *game = nullptr;
    public:
        void initialize() override {
            game = dynamic_cast<MyGame *>(getMyGame());
            srand((unsigned int)time(NULL));
        }
        Opt Dfs(int Step,int Player,double A,double B){
            //cerr<<"Step:"<<Step<<" Player:"<<Player<<" A:"<<A<<" B:"<<B<<endl;
            //game->GetMap(); game->draw();
            //cout<<"---------------------------------------\n";
            Turn T=game->Check();
            if (T==T_A_Win) return {Move(0),double(180+rand()%100)};
            if (T==T_B_Win) return {Move(0),-double(180+rand()%100)};
            if (Step==13) return {Move(0),game->Evaluate()};
            Opt ans={Move(0),Player?1000.0:-1000.0};
            double Sum=0;
            for (int i=0;i<3;i++){
                game->move(Tank(Player),Move(i));
                game->turn();
                if (Player){
                    Opt tmp=Dfs(Step+1,Player^1,A,ans.Score);
                    Sum+=tmp.Score;
                    if (ans.Score>tmp.Score) ans={Move(i),tmp.Score}; //Min
                    if (ans.Score<=A){
                        game->DTurn();
                        game->Dmove(Tank(Player),Move(i));
                        break;
                    }
                }
                else {
                    Opt tmp=Dfs(Step+1,Player^1,ans.Score,B);
                    Sum+=tmp.Score;
                    if (ans.Score<tmp.Score) ans={Move(i),tmp.Score}; //Max
                    if (B<=ans.Score){
                        game->DTurn();
                        game->Dmove(Tank(Player),Move(i));
                        break;
                    }
                }
                game->DTurn();
                game->Dmove(Tank(Player),Move(i));
            }
            return ans;
        }
        Move judge() override {
            Opt tmp=Dfs(0,0,-5000,5000);
            return tmp.M;
        }
};

static MyGame game;
static MyBrain brain;

Game *getMyGame() { return &game; }

Brain *getMyBrain() { return &brain; }
