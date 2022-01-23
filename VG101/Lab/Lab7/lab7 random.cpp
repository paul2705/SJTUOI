#include "lab7.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>

/***
 * For this LAB, you only need to change this file.
 * To complete Task 1, you should implement the functions in MyGame class
 * To complete Task 2, you should expose interfaces to your MyBrain class in MyGame class,
 * and complete your judge function based on your MyGame class.
 */

using namespace std;

// Create Your Data Structure Here (optional)
class Bullet
{
public:
    int x;
    int y;
    int num;
    Direction direction;
};

class tank
{
public:
    int x;
    int y;
    int life;
    Direction direction;
};

class MyGame : public Game {
private:
    // TODO: Create Your Data Structure Here
public:
    /**
     * @param A_X The X position for P1
     * @param A_Y The Y position for P1
     * @param B_X The X position for P2
     * @param B_Y The Y position for P2
     * @param A_direction The direction for P1
     * @param B_direction The direction for P2
     * To know the definition of Direction type, you can look at `lab7.h`
     * D_Left (0)  -> Towards negative X
     * D_Up (1)    -> Towards negative Y
     * D_Right (2) -> Towards positive X
     * D_Down (3)  -> Towards positive Y
     */
    tank Tank_A;
    tank Tank_B;
    int Round;
    int border;
    int bulletnum;
    Bullet bullet[1000];
    void initialize(int A_X, int A_Y, int B_X, int B_Y, Direction A_direction,
                    Direction B_direction) override {
        // TODO: Initialize Your Game Here
    Round=1;
    Tank_A.x=A_X;
    Tank_A.y=A_Y;
    Tank_B.x=B_X;
    Tank_B.y=B_Y;
    Tank_A.direction=A_direction;
    Tank_B.direction=B_direction;
    Tank_A.life=5;
    Tank_B.life=5;
    border=0;
    bulletnum=0;
    for (int i=0;i<1000;++i)
    {
        bullet[i].x=1000;
        bullet[i].y=1000;
    }
}

    /**
     * Perform the move action of the given tank
     * @param tank The tank that is going to move
     * Tank_A (0) -> P1
     * Tank_B (1) -> P2
     * @param move The action it wants to take
     * M_Forward (0) -> Move Forward
     * M_Left (1)    -> Turn Left
     * M_Right (2)   -> Turn Right
     */
    
    void move(Tank tank, Move move) override {
        // TODO: Record A Move And Update Your Game
        // 1. Tank Moves
        if (tank==0)
        {
            if (Tank_A.direction==Direction(0))
            {
                if (move==0) Tank_A.x-=1;
                if (move==1) 
                {
                    Tank_A.y+=1;
                    Tank_A.direction=Direction(3);
                }
                if (move==2) 
                {
                    Tank_A.y-=1;
                    Tank_A.direction=Direction(1);
                }
            }
            else if (Tank_A.direction==1)
            {
                if (move==0) Tank_A.y-=1;
                if (move==1)
                {
                    Tank_A.x-=1;
                    Tank_A.direction=Direction(0);
                }
                if (move==2)
                {
                    Tank_A.x+=1;
                    Tank_A.direction=Direction(2);
                }
            }
            else if (Tank_A.direction==Direction(2))
            {
                if (move==0) Tank_A.x+=1;
                if (move==1)
                {
                     Tank_A.y-=1;
                     Tank_A.direction=Direction(1);
                }
                if (move==2)
                {
                    Tank_A.y+=1;
                    Tank_A.direction=Direction(3);
                }
            }
            else if (Tank_A.direction==3)
            {
                if (move==0) Tank_A.y+=1;
                if (move==1)
                {
                     Tank_A.x+=1;
                     Tank_A.direction=Direction(2);
                }
                if (move==2)
                {
                     Tank_A.x-=1;
                     Tank_A.direction=Direction(0);
                }
            }
        }
        else if (tank==1)
        {
            if (Tank_B.direction==0)
            {
                if (move==0) Tank_B.x-=1;
                if (move==1) 
                {
                    Tank_B.y+=1;
                    Tank_B.direction=Direction(3);
                }
                if (move==2) 
                {
                    Tank_B.y-=1;
                    Tank_B.direction=Direction(1);
                }
            }
            else if (Tank_B.direction==1)
            {
                if (move==0) Tank_B.y-=1;
                if (move==1)
                {
                    Tank_B.x-=1;
                    Tank_B.direction=Direction(0);
                }
                if (move==2)
                {
                    Tank_B.x+=1;
                    Tank_B.direction=Direction(2);
                }
            }
            else if (Tank_B.direction==2)
            {
                if (move==0) Tank_B.x+=1;
                if (move==1)
                {
                     Tank_B.y-=1;
                     Tank_B.direction=Direction(1);
                }
                if (move==2)
                {
                     Tank_B.y+=1;
                     Tank_B.direction=Direction(3);
                }
            }
            else if (Tank_B.direction==3)
            {
                if (move==0) Tank_B.y+=1;
                if (move==1)
                {
                     Tank_B.x+=1;
                     Tank_B.direction=Direction(2);
                }
                if (move==2)
                {
                     Tank_B.x-=1;
                     Tank_B.direction=Direction(0);
                }
            }
        }
        // 2. Tank Shoots
        if ((Round-1)%3==0)
        {   
            if (tank==0)
            {
                bullet[bulletnum].direction=Tank_A.direction;
                if (Tank_A.direction==0)
                {
                    bullet[bulletnum].x=Tank_A.x-1;
                    bullet[bulletnum].y=Tank_A.y;
                }
                if (Tank_A.direction==1)
                {
                    bullet[bulletnum].x=Tank_A.x;
                    bullet[bulletnum].y=Tank_A.y-1;
                }
                if (Tank_A.direction==2)
                {
                    bullet[bulletnum].x=Tank_A.x+1;
                    bullet[bulletnum].y=Tank_A.y;
                }
                if (Tank_A.direction==3)
                {
                    bullet[bulletnum].x=Tank_A.x;
                    bullet[bulletnum].y=Tank_A.y+1;
                }
                bulletnum+=1;
            }
            if (tank==1)
            {
                bullet[bulletnum].direction=Tank_B.direction;
                if (Tank_B.direction==0)
                {
                    bullet[bulletnum].x=Tank_B.x-1;
                    bullet[bulletnum].y=Tank_B.y;
                }
                if (Tank_B.direction==1)
                {
                    bullet[bulletnum].x=Tank_B.x;
                    bullet[bulletnum].y=Tank_B.y-1;
                }
                if (Tank_B.direction==2)
                {
                    bullet[bulletnum].x=Tank_B.x+1;
                    bullet[bulletnum].y=Tank_B.y;
                }
                if (Tank_B.direction==3)
                {
                    bullet[bulletnum].x=Tank_B.x;
                    bullet[bulletnum].y=Tank_B.y+1;
                }
                bulletnum+=1;
            }
        }
    }

    /**
     * Calculate the result at the end of the turn. It will be called after two
     * tanks make their move. (You can check `main.cpp` for detail)
     * @return
     * T_Cont (0)  -> Game continues
     * T_A_Win (1) -> P1 Wins
     * T_B_Win (2) -> P2 Wins
     * T_Draw (3)  -> Draw
     */
    Turn turn() override {
        // TODO: Make Your Turn Here
        // 0. Judge Whether Tanks Crash
        if (Tank_A.x==Tank_B.x&&Tank_A.y==Tank_B.y)
        {
            if (Tank_A.life>Tank_B.life) return T_A_Win;
            if (Tank_A.life<Tank_B.life) return T_B_Win;
            if (Tank_A.life==Tank_B.life) return T_Draw;
        }
        // 1. Move Bullets
        for (int i=0;i<=bulletnum;++i)
        {
            if (bullet[i].x==Tank_B.x&&bullet[i].y==Tank_B.y)
            {
                Tank_B.life-=2;
                bullet[i].x=1000;
                bullet[i].y=1000;
            }
            if (bullet[i].x==Tank_A.x&&bullet[i].y==Tank_A.y) 
            {
                Tank_A.life-=2;
                bullet[i].x=1000;
                bullet[i].y=1000;
            }
        }
        for (int i=0;i<=bulletnum;++i)
        {
            if (bullet[i].direction==0) bullet[i].x-=1;
            if (bullet[i].direction==1) bullet[i].y-=1;
            if (bullet[i].direction==2) bullet[i].x+=1;
            if (bullet[i].direction==3) bullet[i].y+=1;
        }
        for (int i=0;i<=bulletnum;++i)
        {
            if (bullet[i].x==Tank_B.x&&bullet[i].y==Tank_B.y)
            {
                Tank_B.life-=2;
                bullet[i].x=1000;
                bullet[i].y=1000;
            }
            if (bullet[i].x==Tank_A.x&&bullet[i].y==Tank_A.y) 
            {
                Tank_A.life-=2;
                bullet[i].x=1000;
                bullet[i].y=1000;
            }
        }
        for (int i=0;i<=bulletnum;++i)
        {
            if (bullet[i].direction==0) bullet[i].x-=1;
            if (bullet[i].direction==1) bullet[i].y-=1;
            if (bullet[i].direction==2) bullet[i].x+=1;
            if (bullet[i].direction==3) bullet[i].y+=1;
        }
        for (int i=0;i<=bulletnum;++i)
        {
            if (bullet[i].x==Tank_B.x&&bullet[i].y==Tank_B.y)
            {
                Tank_B.life-=2;
                bullet[i].x=1000;
                bullet[i].y=1000;
            }
            if (bullet[i].x==Tank_A.x&&bullet[i].y==Tank_A.y) 
            {
                Tank_A.life-=2;
                bullet[i].x=1000;
                bullet[i].y=1000;
            }
        }
        // 2. Judge Whether Out of Boundary
        if (Round%16==0) border+=1;
        if (Tank_A.x<border||Tank_A.x>MAP_SIZE-border-1||Tank_A.y<border||Tank_A.y>MAP_SIZE-border-1) Tank_A.life-=1;
        if (Tank_B.x<border||Tank_B.x>MAP_SIZE-border-1||Tank_B.y<border||Tank_B.y>MAP_SIZE-border-1) Tank_B.life-=1;
        // 3. Judge Win or Lose
        if (Tank_A.life<=0&&Tank_B.life<=0) return T_Draw;
        else if (Tank_A.life<=0&&Tank_B.life>0) return T_B_Win;
        else if (Tank_B.life<=0&&Tank_A.life>0) return T_A_Win;
        Round+=1;
        return T_Cont;
    }

    /**
     * Draw the battlefield
     * @return
     */
    
    string draw() const override {
        // TODO: Draw the Battlefield (optional for Task 1 and Task 2)
        ostringstream result;
        for (int y = -5; y < MAP_SIZE + 5; y++) {
            for (int x = -5; x < MAP_SIZE + 5; x++) {
                char cur = ' ';
                Vector2<int> curPos(x, y);
                if (x < border || y < border || x >= MAP_SIZE - border || y >= MAP_SIZE - border) cur = '-';
                if (Tank_A.x == curPos.x && Tank_A.y == curPos.y) 
                {
                    cur = 'A';
                }
                if (Tank_B.x == curPos.x && Tank_B.y == curPos.y) 
                {
                    cur = 'B';
                }
                for (int i=0;i<bulletnum;++i)
                {
                    if (bullet[i].x == curPos.x && bullet[i].y == curPos.y) cur = '*';
                }
                result << cur << "|";
            }
            result << "\n";
        }
        result << "\nA: " << Tank_A.life << ", B: " << Tank_B.life << endl;
        return result.str();
        return "I hate drawing!\n";
    }

    /**
     * Get the battlefield.
     * Map.block: Each block of the map. The first index is `y` and the second
     * index is `x`
     * @return
     */
    Map getMap() const override {
        // TODO: Return the Battlefield (optional for Task 2)
        Map map;
        map.border=border;
        int y,x;
        for (y=-5;y<MAP_SIZE+5;++y)
        {
            for (x=-5;x<MAP_SIZE+5;++x)
            {
                if (y==Tank_A.y&&x==Tank_A.x) map.block[y+5][x+5]=B_Tank_A;
                else if (y==Tank_B.y&&x==Tank_B.x) map.block[y+5][x+5]=B_Tank_B;
                else map.block[y+5][x+5]=B_Blank;
            }
        }
        for (int i=0;i<=bulletnum;++i)
        {
            if (bullet[i].x<25&&bullet[i].x>=-5&&bullet[i].y<25&&bullet[i].y>=-5) map.block[bullet[i].y+5][bullet[i].x+5]=B_Bullet;
        }
        return map;
    }

    /**
     * Add a bullet to the battlefield
     * @param pos
     * @param direction
     */
    void addBullet(const Vector2<> &pos, Direction direction) override {
        // TODO: Manually Add One Bullet (optional for Task 2)
        bulletnum+=1;
        bullet[bulletnum].x=pos.x;
        bullet[bulletnum].y=pos.y;
        bullet[bulletnum].direction=direction;
    }

    /**
     * Set the border to certain value, notice that it will not reset the shrink
     * time
     * @param border
     */
    void setBorder(int _border) override {
        // TODO: Manually Set the Border (optional for Task 2)
        border=_border;
    }
};

class MyBrain : public Brain {
    // TODO: Create Your Status Variables Here (optional)
    const MyGame *game = nullptr;

public:
    void initialize() override {
        // TODO: Initialize Your AI here (optional)
        game = dynamic_cast<MyGame *>(getMyGame());
        // This will give you a MyGame pointer from the Game pointer returned by getMyGame()
        // So you can access the variable before it's declared.
    }

    Move judge() override {
        // TODO: Determine Your Move Here
        while (game->Tank_A.life>0)
        {
            srand(time(NULL));
            int move=rand()%4;
            if (1)
            {
                if (game->Tank_A.x-2<game->border)
                {
                    if (game->Tank_A.direction==0) return M_Right;
                    if (game->Tank_A.direction==1) return M_Right;
                    if (game->Tank_A.direction==2) return M_Forward;
                    if (game->Tank_A.direction==3) return M_Left;
                }
                else if (game->Tank_A.x+2>MAP_SIZE-game->border-1)
                {
                    if (game->Tank_A.direction==0) return M_Forward;
                    if (game->Tank_A.direction==1) return M_Left;
                    if (game->Tank_A.direction==2) return M_Left;
                    if (game->Tank_A.direction==3) return M_Right;
                }
                else if (game->Tank_A.y-2<game->border)
                {
                    if (game->Tank_A.direction==0) return M_Left;
                    if (game->Tank_A.direction==1) return M_Left;
                    if (game->Tank_A.direction==2) return M_Right;
                    if (game->Tank_A.direction==3) return M_Forward;
                }
                else if (game->Tank_A.y+2>MAP_SIZE-game->border-1)
                {
                    if (game->Tank_A.direction==0) return M_Right;
                    if (game->Tank_A.direction==1) return M_Forward;
                    if (game->Tank_A.direction==2) return M_Left;
                    if (game->Tank_A.direction==3) return M_Left;
                }
            }
                if (game->Tank_A.direction==0)
                {
                    if (move==0) 
                    {
                        if (game->Tank_A.x-3<game->border) break; 
                        for (int i=0;i<=game->bulletnum;++i)
                        {
                            if (game->bullet[i].x==game->Tank_A.x-1&&game->bullet[i].y==game->Tank_A.y) break;
                        }
                        return M_Forward;
                    }
                    if (move==1) 
                    {
                        if (game->Tank_A.y+3>MAP_SIZE-game->border-1) break;
                        for (int i=0;i<=game->bulletnum;++i)
                        {
                            if (game->bullet[i].x==game->Tank_A.x&&game->bullet[i].y==game->Tank_A.y+1) break;
                        }
                        return M_Left;
                    }
                    if (move==2) 
                    {
                        if (game->Tank_A.y-3<game->border) break;
                        for (int i=0;i<=game->bulletnum;++i)
                        {
                            if (game->bullet[i].x==game->Tank_A.x&&game->bullet[i].y==game->Tank_A.y-1) break;
                        }
                        return M_Right;
                    }
                }
                else if (game->Tank_A.direction==1)
                {
                    if (move==0) 
                    {
                        if (game->Tank_A.y-3<game->border) break;
                        for (int i=0;i<=game->bulletnum;++i)
                        {
                            if (game->bullet[i].x==game->Tank_A.x&&game->bullet[i].y==game->Tank_A.y-1) break;
                        }
                        return M_Forward;
                    }
                    if (move==1)
                    {
                        if (game->Tank_A.x-3<game->border) break;
                        for (int i=0;i<=game->bulletnum;++i)
                        {
                            if (game->bullet[i].x==game->Tank_A.x-1&&game->bullet[i].y==game->Tank_A.y) break;
                        }
                        return M_Left;
                    }
                    if (move==2)
                    {
                        if (game->Tank_A.x+3>MAP_SIZE-game->border-1) break;
                        for (int i=0;i<=game->bulletnum;++i)
                        {
                            if (game->bullet[i].x==game->Tank_A.x+1&&game->bullet[i].y==game->Tank_A.y) break;
                        }
                        return M_Right;
                    }
                }
                else if (game->Tank_A.direction==2)
                {
                    if (move==0) 
                    {
                        if (game->Tank_A.x+3>MAP_SIZE-game->border-1) break;
                        for (int i=0;i<=game->bulletnum;++i)
                        {
                            if (game->bullet[i].x==game->Tank_A.x+1&&game->bullet[i].y==game->Tank_A.y) break;
                        }
                        return M_Forward;
                    }
                    if (move==1)
                    {
                        if (game->Tank_A.y-3<game->border) break;
                        for (int i=0;i<=game->bulletnum;++i)
                        {
                            if (game->bullet[i].x==game->Tank_A.x&&game->bullet[i].y==game->Tank_A.y-1) break;
                        }
                        return M_Left;
                    }
                    if (move==2)
                    {
                        if (game->Tank_A.y+3>MAP_SIZE-game->border-1) break;
                        for (int i=0;i<=game->bulletnum;++i)
                        {
                            if (game->bullet[i].x==game->Tank_A.x&&game->bullet[i].y==game->Tank_A.y+1) break;
                        }
                        return M_Right;
                    }
                }
                else if (game->Tank_A.direction==3)
                {
                    if (move==0) 
                    {
                        if (game->Tank_A.y+3>MAP_SIZE-game->border-1) break;
                        for (int i=0;i<=game->bulletnum;++i)
                        {
                            if (game->bullet[i].x==game->Tank_A.x&&game->bullet[i].y==game->Tank_A.y+1) break;
                        }
                        return M_Forward;
                    }
                    if (move==1)
                    {
                        if (game->Tank_A.x+3>MAP_SIZE-game->border-1) break;
                        for (int i=0;i<=game->bulletnum;++i)
                        {
                            if (game->bullet[i].x==game->Tank_A.x+1&&game->bullet[i].y==game->Tank_A.y) break;
                        }
                        return M_Left;
                    }
                    if (move==2)
                    {
                        if (game->Tank_A.x-3<game->border) break;
                        for (int i=0;i<=game->bulletnum;++i)
                        {
                            if (game->bullet[i].x==game->Tank_A.x-1&&game->bullet[i].y==game->Tank_A.y) break;
                        }
                        return M_Right;
                    }
                }
        }
        return M_Forward;
    }
};

static MyGame game;
static MyBrain brain;

Game *getMyGame() { return &game; }

Brain *getMyBrain() { return &brain; }
