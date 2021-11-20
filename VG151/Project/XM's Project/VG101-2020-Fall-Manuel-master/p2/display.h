#ifndef P2_DISPLAY_H
#define P2_DISPLAY_H
#include "player.h"
#include <stdlib.h>

// Print welcome message
void welcome(int, int, int, int,FILE *);

// Show status for human player
void status(int, PLAYER *, FILE *);

// Display the information of a card
void display(int, int, FILE*);

//Show status of each player in auto mode
void show_status(PLAYER *, FILE *);

// Show action of each player
void show_action1(PLAYER *, CARD *, int, FILE *);
void show_action2(PLAYER *, CARD *, int, FILE *);

// Show the winning status
int win(PLAYER* player, int, int, FILE *);

// Print the result of the game in each round
void scoreboard(PLAYER *, int, FILE *, int, int);

// Draw a set of cards in ascii art
void asciiart(PLAYER* start);

// Draw a single card in ascii art
void asciiart_demo(CARD flag);

#endif //P2_DISPLAY_H
