#ifndef P2_PLAYER_H
#define P2_PLAYER_H
#define USER 4 // Total number of players
#include <stdio.h>
#include <string.h>
#include "card.h"

// Define a structure for a players
typedef struct player{
    int id;
    int score;
    CARD card[100];
    int length;
    struct player * next;
    struct player * prev;
}PLAYER;

// Generate USER players with DEFAULT cards and respective name, score
PLAYER *initlist(int, int);

// Deal respective cards to each player
PLAYER *deal(PLAYER *, CARD *, int, int, int);

// Decide the sequence of the players
PLAYER *sequence(PLAYER *, int, FILE *);

// Free memory usage
void free_player(PLAYER *, int);

#endif //P2_PLAYER_H
