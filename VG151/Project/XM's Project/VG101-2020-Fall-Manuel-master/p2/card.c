#include <stdlib.h>
#include "card.h"
#include "display.h"

// Randomize an array of CARD
void randomize(CARD *card, int n){
    CARD temp;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int j = rand() % (n-i) + i;
        temp = card[i];
        card[i] = card[j];
        card[j] = temp;
    }
}

// Generate random DECK piles of cards
CARD *initial_card(int deck, int mode, FILE * fp) {
    // Generate DECK piles of ordered cards
    CARD pile[SUM*deck];
    CARD original_pile[SUM]={
            {2, HEARTS}, {2, SPADES}, {2, CLUBS}, {2, DIAMOND},
            {3, HEARTS}, {3, SPADES}, {3, CLUBS}, {3, DIAMOND},
            {4, HEARTS}, {4, SPADES}, {4, CLUBS}, {4, DIAMOND},
            {5, HEARTS}, {5, SPADES}, {5, CLUBS}, {5, DIAMOND},
            {6, HEARTS}, {6, SPADES}, {6, CLUBS}, {6, DIAMOND},
            {7, HEARTS}, {7, SPADES}, {7, CLUBS}, {7, DIAMOND},
            {8, HEARTS}, {8, SPADES}, {8, CLUBS}, {8, DIAMOND},
            {9, HEARTS}, {9, SPADES}, {9, CLUBS}, {9, DIAMOND},
            {10, HEARTS}, {10, SPADES}, {10, CLUBS}, {10, DIAMOND},
            {JACK, HEARTS}, {JACK, SPADES}, {JACK, CLUBS}, {JACK, DIAMOND},
            {QUEEN, HEARTS}, {QUEEN, SPADES}, {QUEEN, CLUBS}, {QUEEN, DIAMOND},
            {KING, HEARTS}, {KING, SPADES}, {KING, CLUBS}, {KING, DIAMOND},
            {ACE, HEARTS}, {ACE, SPADES}, {ACE, CLUBS}, {ACE, DIAMOND}
    };
    for (int i=0; i<deck; i++){
        for (int j=0; j<SUM; j++){
            pile[i*SUM+j] = original_pile[j];
        }
    }

    // Randomize
    CARD * p_pile = (CARD *)malloc((SUM*deck)*sizeof(CARD));
    for(int i=0; i<SUM*deck; i++) p_pile[i]=pile[i];
    randomize(p_pile, (SUM*deck));

    for (int i=0; i<deck; i++){
        for (int j=0; j<SUM; j++){
            pile[i*SUM+j] = original_pile[j];
        }
    }

    // Display shuffling result
    if(mode == 1) {
        printf("Shuffling cards...\n"
               "Shuffle result:\n");
        fprintf(fp,"Shuffling cards...\n"
               "Shuffle result:\n");
        for (int i=0; i<deck; i++){
            for (int j=0; j<SUM; j++){
                display(pile[i*SUM+j].rank, pile[i*SUM+j].suit, fp);
            }
        }
        printf("\n\n");
        fprintf(fp,"\n\n");
    }

    return p_pile;
}




