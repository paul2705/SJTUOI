#ifndef P2_CARD_H
#define P2_CARD_H
#define ACE 14
#define KING 13
#define QUEEN 12
#define JACK 11
#define HEARTS 1
#define SPADES 2
#define CLUBS 3
#define DIAMOND 4
#define SUM 52 // Sum of a card pile
#define DECK 2 // Number of card piles
#define DEFAULT 5 // The original number of cards distributed into each player
#include <stdio.h>
#include <time.h>

// Define a structure for a card
typedef struct card{
    int rank;
    int suit;
}CARD;

// Randomize an array of CARD
void randomize(CARD *, int);

// Generate random DECK piles of cards
CARD *initial_card(int, int, FILE *);

#endif //P2_CARD_H
