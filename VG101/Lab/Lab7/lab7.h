#ifndef LAB7_H
#define LAB7_H

#include <string>
#include <cmath>

#define MAP_SIZE 20
#define EXTRA_SIZE 5

template<typename B = int>
struct Vector2 {
    B x, y;

    Vector2(B _x = 0, B _y = 0) : x(_x), y(_y) {}

    Vector2<B> operator+(const Vector2<B> &another) const { return {x + another.x, y + another.y}; }

    Vector2<B> operator-(const Vector2<B> &another) const { return {x - another.x, y - another.y}; }

    Vector2<B> operator*(B multiplier) const { return {x * multiplier, y * multiplier}; }

    Vector2<B> operator/(B multiplier) const { return {x / multiplier, y / multiplier}; }

    Vector2<B> operator+=(const Vector2<B> &another) {
        x += another.x;
        y += another.y;
        return *this;
    }

    Vector2<B> operator-=(const Vector2<B> &another) {
        x -= another.x;
        y -= another.y;
        return *this;
    }

    Vector2<B> operator*=(B multiplier) {
        x *= multiplier;
        y *= multiplier;
        return *this;
    }

    Vector2<B> operator/=(B multiplier) {
        x /= multiplier;
        y /= multiplier;
        return *this;
    }

    bool operator==(const Vector2<B> &another) const { return x == another.x && y == another.y; }

    double length() const { return sqrt(double(x * x + y * y)); }
};

// The identifiers of tanks
enum Tank {
    Tank_A, Tank_B
};

// The directions of tanks and bullets
enum Direction {
    D_Left, D_Up, D_Right, D_Down
};

// The actions of tanks each turn
enum Move {
    M_Forward, M_Left, M_Right
};

// The results of each turn
enum Turn {
    T_Cont, T_A_Win, T_B_Win, T_Draw
};

// The elements of each block on the map
enum Block {
    B_Blank, B_Bullet, B_Tank_A, B_Tank_B
};

struct Map {
    Block block[MAP_SIZE + 2 * EXTRA_SIZE][MAP_SIZE + 2 * EXTRA_SIZE];
    int border;
};

class Game {
public:
    virtual void initialize(int A_X, int A_Y, int B_X, int B_Y, Direction A_direction, Direction B_direction) = 0;

    virtual void move(Tank tank, Move move) = 0;

    virtual Turn turn() = 0;

    virtual std::string draw() const = 0;

    virtual Map getMap() const { return {}; }

    virtual void addBullet(const Vector2<> &pos, Direction direction) {};

    virtual void setBorder(int border) {};

    virtual Map GetMap()=0;
};

class Brain {
public:
    virtual void initialize() = 0;

    virtual Move judge() = 0;
};

Game *getMyGame();

Brain *getMyBrain();

#endif // LAB7_H
