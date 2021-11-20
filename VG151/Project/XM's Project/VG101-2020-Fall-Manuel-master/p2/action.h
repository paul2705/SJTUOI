#ifndef P2_ACTION_H
#define P2_ACTION_H
#define ROUND 1 // Rounds being played
#include <math.h>
#include <stdlib.h>
#include <getopt.h>
#include "card.h"
#include "player.h"
#include "display.h"
#include <unistd.h>
#ifdef __WIN32
#define CLEAR() do { if(system("cls")){}; } while ((void)0, 0)
#else
#define CLEAR() do { if(system("clear")){}; } while ((void)0, 0)
#endif

// Scan values of variables from command line
void initialize(int, char*[], char *, int *);

// Judge and play a card, a.k.a removing a certain card from the player's card pile
void play(CARD *, PLAYER *, CARD, int, int, FILE *);

// Show effect passed on the next player
void effect(int *, CARD *, CARD *, PLAYER *, int, int, int, int, int, FILE *);

// Move to the next player
PLAYER *pass(CARD* temp, PLAYER* start, int reverse);

// Sort cards
PLAYER *sort(PLAYER *);

// Take one card from the original card pile to the player's card pile
void take(CARD *, PLAYER *, int, FILE *);

// Return the played cards to the original pile then shuffle
void discard(CARD *, CARD *);

#endif //P2_ACTION_H
