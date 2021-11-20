#ifndef STRUCTURE_H
#define STRUCTURE_H

typedef struct cd
{ //Car names
    char *suit[4];
    char *mcards[13];
    int playernum; //number of players
    int cardperplayer;
    int decknum;
    int roundnum;
    int demomode;
    char logname[30];
} constant;

typedef struct cards
{
    int cardOnDesk;
    int *cardsRemain;
    int *cardsQuit;
} cards;

typedef struct ply
{
    int player_id;
    int current_penalty;
    int total_penalty;
    int *cardsinhand;
    int isOutCard;
    struct ply *prior;
    struct ply *next;
} player;

typedef struct rnd
{
    int oclock; //rclock(1) or lclock(0)
    player *currentPlayer;
    int cardoverlay;
    int turnnum;
    int roundnum;
} round;

typedef struct glb
{ //All variables
    constant constant;
    cards cards;
    round round;
} game;

#endif
