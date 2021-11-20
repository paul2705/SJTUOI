#include "display.h"

// Welcome
void welcome(int deck, int initial, int user, int round, FILE *fp){
    printf("########################\n"
           "#                      #\n"
           "#                      #\n"
           "# Welcome to One Card! #\n"
           "#                      #\n"
           "#                      #\n"
           "########################\n"
           "\n"
           "---- Initial setup ----\n");
    printf("Number of rounds: %d\n", round);
    printf("Number of decks: %d\n", deck);
    printf("Number of players: %d\n", user);
    printf("Dealing cards...\n"
           "Each player will be dealt with %d cards\n", initial);
    printf("\n");
    fprintf(fp,"---- Initial setup ----\n");
    fprintf(fp,"Number of rounds: %d\n", round);
    fprintf(fp,"Number of decks: %d\n", deck);
    fprintf(fp,"Number of players: %d\n", user);
    fprintf(fp,"Dealing cards...\n"
           "Each player will be dealt with %d cards\n", initial);
    fprintf(fp,"\n");
    fprintf(fp,"\n---- Game start ----\n");
}

// Show status for human player
void status(int user, PLAYER* start, FILE * fp){
    printf("---- Player %d's Round ----\n",start->id);
    fprintf(fp,"---- Player %d's Round ----\n",start->id);
    for (int i = 0; i < user; i++) {
        printf("Player %d has %d card(s)\n", start->id, start->length);
        start = start->next;
    }
    printf("\n");
}

// Display the information of a card
void display(int rank, int suit, FILE* fp){
    switch(rank){
        case 11: printf("JACK ");fprintf(fp,"JACK ");break;
        case 12: printf("QUEEN ");fprintf(fp,"QUEEN ");break;
        case 13: printf("KING ");fprintf(fp,"KING ");break;
        case 14: printf("ACE ");fprintf(fp,"ACE ");break;
        default: printf("%d ", rank);fprintf(fp,"%d ", rank);
    }
    switch(suit){
        case 1: printf("HEARTS  ");fprintf(fp,"HEARTS  ");break;
        case 2: printf("SPADES  ");fprintf(fp,"SPADES  ");break;
        case 3: printf("CLUBS  ");fprintf(fp,"CLUBS  ");break;
        case 4: printf("DIAMOND  ");fprintf(fp,"DIAMOND  ");break;
        default: printf("%d  ", suit);fprintf(fp,"%d  ", suit);
    }
}

//Show status of each player
void show_status(PLAYER* start, FILE * fp){
    printf("Player %d now has %d cards\n", start->id, start->length);
    fprintf(fp,"Player %d now has %d cards\n", start->id, start->length);
    printf("Player %d's cards:\n", start->id);
    fprintf(fp,"Player %d's cards: ", start->id);
    for (int i=0;i<start->length;i++){
        display(start->card[i].rank, start->card[i].suit, fp);
    }
    printf("\n");
    fprintf(fp,"\n");
}

// Show action of each player
void show_action1(PLAYER* start, CARD* temp, int mode, FILE * fp){
    if (temp[0].suit==0 && temp[0].rank==0){
        printf("Round 1: Player %d has no card to play\n", start->id);
        fprintf(fp,"Round 1: Player %d has no card to play\n", start->id);
        if (mode == 0) {
            printf("Press enter to continue...\n");
            getchar();
        }
    }
    else{
        printf("Round 1: Player %d plays ", start->id);
        fprintf(fp,"Round 1: Player %d plays ", start->id);
        display(temp[0].rank, temp[0].suit, fp);
        printf("\n");
        fprintf(fp,"\n");
    }
}
void show_action2(PLAYER* start, CARD* temp, int mode, FILE * fp){
    if (temp[1].suit==0 && temp[1].rank==0){
        printf("Round 2: Player %d has no card to play\n", start->id);
        fprintf(fp,"Round 2: Player %d has no card to play\n", start->id);
        if (mode == 0) {
            printf("Press enter to continue...\n");
            getchar();
        }
    }
    else{
        printf("Round 2: Player %d plays ", start->id);
        fprintf(fp,"Round 2: Player %d plays ", start->id);
        display(temp[1].rank, temp[1].suit,fp);
        printf("\n");
        fprintf(fp,"\n");
    }
}

// Show the winning status
int win(PLAYER* start, int user, int game, FILE * fp){
    printf("Congratulations! Player %d wins!\n", start->id);
    fprintf(fp,"Player %d wins!\n", start->id);
    printf("Press enter to start the next round or check the scoreboard when the round is over:\n ");
    getchar();
    game = 0;
    for (int i = 0; i < user; i++) {
        start->score = start->score - start->length;
        start = start->next;
    }
    return game;
}

// Print the result of the game in each round
void scoreboard(PLAYER* start, int user, FILE * fp, int i, int round){
    if (i == (round-1)) {
        printf("Score board:\n");
        fprintf(fp,"Score board:\n");
        for (int j=0; j<user; j++){
            printf("Player %d's score is %d\n", start->id, start->score);
            fprintf(fp,"Player %d's score is %d\n", start->id, start->score);
            start = start->next;
        }
    }
    else {
        printf("---- Stats ----\n"
               "Round %d result:\n", i+1);
        fprintf(fp,"---- Stats ----\n"
                   "Round %d result:\n", i+1);
        for (int j = 0; j < user; j++) {
            printf("Player %d's score is %d\n", start->id, start->score);
            fprintf(fp,"Player %d's score is %d\n", start->id, start->score);
            start = start->next;
        }
    }
    printf("Round %d ends.\n", i+1);
    fprintf(fp,"Round %d ends.\n", i+1);
}

// Draw a set of cards in ascii art
void asciiart(PLAYER* start) {
    char disp_rank[5];
    char disp_suit[5];
    for (int i = 0;i < (int)(start->length/5); i++){
        for (int j = 0; j < 5; j++) {
            switch (start->card[i*5+j].rank) {
                case 2: disp_rank[j] = '2'; break;
                case 3: disp_rank[j] = '3'; break;
                case 4: disp_rank[j] = '4'; break;
                case 5: disp_rank[j] = '5'; break;
                case 6: disp_rank[j] = '6'; break;
                case 7: disp_rank[j] = '7'; break;
                case 8: disp_rank[j] = '8'; break;
                case 9: disp_rank[j] = '9'; break;
                case 10: disp_rank[j] = 'T'; break;
                case 11: disp_rank[j] = 'J'; break;
                case 12: disp_rank[j] = 'Q'; break;
                case 13: disp_rank[j] = 'K'; break;
                case 14: disp_rank[j] = 'A'; break;
                default: break;
            }
            switch (start->card[i*5+j].suit) {
                case 1: disp_suit[j] = 'H'; break;
                case 2: disp_suit[j] = 'S'; break;
                case 3: disp_suit[j] = 'C'; break;
                case 4: disp_suit[j] = 'D'; break;
                default: break;
            }
        }
        printf("+_______+  +_______+  +_______+  +_______+  +_______+\n");
        printf("| %c     |  | %c     |  | %c     |  | %c     |  | %c     |\n", disp_rank[0], disp_rank[1], disp_rank[2], disp_rank[3], disp_rank[4]);
        printf("|       |  |       |  |       |  |       |  |       |\n");
        printf("|   %c   |  |   %c   |  |   %c   |  |   %c   |  |   %c   |\n", disp_suit[0], disp_suit[1], disp_suit[2], disp_suit[3], disp_suit[4]);
        printf("|       |  |       |  |       |  |       |  |       |\n");
        printf("|     %c |  |     %c |  |     %c |  |     %c |  |     %c |\n", disp_rank[0], disp_rank[1], disp_rank[2], disp_rank[3], disp_rank[4]);
        printf("+-------+  +-------+  +-------+  +-------+  +-------+\n");
        printf("    %d          %d          %d          %d          %d    \n", i*5+1, i*5+2, i*5+3, i*5+4, i*5+5);
    }
    switch (start->length%5) {
        case 0: break;
        case 1:
            for (int j = 0; j < 1; j++) {
                switch (start->card[((int)(start->length/5))*5+j].rank) {
                    case 2: disp_rank[j] = '2'; break;
                    case 3: disp_rank[j] = '3'; break;
                    case 4: disp_rank[j] = '4'; break;
                    case 5: disp_rank[j] = '5'; break;
                    case 6: disp_rank[j] = '6'; break;
                    case 7: disp_rank[j] = '7'; break;
                    case 8: disp_rank[j] = '8'; break;
                    case 9: disp_rank[j] = '9'; break;
                    case 10: disp_rank[j] = 'T'; break;
                    case 11: disp_rank[j] = 'J'; break;
                    case 12: disp_rank[j] = 'Q'; break;
                    case 13: disp_rank[j] = 'K'; break;
                    case 14: disp_rank[j] = 'A'; break;
                    default: break;
                }
                switch (start->card[((int)(start->length/5))*5+j].suit) {
                    case 1: disp_suit[j] = 'H'; break;
                    case 2: disp_suit[j] = 'S'; break;
                    case 3: disp_suit[j] = 'C'; break;
                    case 4: disp_suit[j] = 'D'; break;
                    default: break;
                }
            }
            printf("+_______+\n");
            printf("| %c     |\n", disp_rank[0]);
            printf("|       |\n");
            printf("|   %c   |\n", disp_suit[0]);
            printf("|       |\n");
            printf("|     %c |\n", disp_rank[0]);
            printf("+-------+\n");
            printf("    %d    \n", ((int)(start->length/5))*5+1);
            break;
        case 2:
            for (int j = 0; j < 2; j++) {
                switch (start->card[((int)(start->length/5))*5+j].rank) {
                    case 2: disp_rank[j] = '2'; break;
                    case 3: disp_rank[j] = '3'; break;
                    case 4: disp_rank[j] = '4'; break;
                    case 5: disp_rank[j] = '5'; break;
                    case 6: disp_rank[j] = '6'; break;
                    case 7: disp_rank[j] = '7'; break;
                    case 8: disp_rank[j] = '8'; break;
                    case 9: disp_rank[j] = '9'; break;
                    case 10: disp_rank[j] = 'T'; break;
                    case 11: disp_rank[j] = 'J'; break;
                    case 12: disp_rank[j] = 'Q'; break;
                    case 13: disp_rank[j] = 'K'; break;
                    case 14: disp_rank[j] = 'A'; break;
                    default: break;
                }
                switch (start->card[((int)(start->length/5))*5+j].suit) {
                    case 1: disp_suit[j] = 'H'; break;
                    case 2: disp_suit[j] = 'S'; break;
                    case 3: disp_suit[j] = 'C'; break;
                    case 4: disp_suit[j] = 'D'; break;
                    default: break;
                }
            }
            printf("+_______+  +_______+\n");
            printf("| %c     |  | %c     |\n", disp_rank[0], disp_rank[1]);
            printf("|       |  |       |\n");
            printf("|   %c   |  |   %c   |\n", disp_suit[0], disp_suit[1]);
            printf("|       |  |       |\n");
            printf("|     %c |  |     %c |\n", disp_rank[0],disp_rank[1]);
            printf("+-------+  +-------+\n");
            printf("    %d          %d    \n", ((int)(start->length/5))*5+1, ((int)(start->length/5))*5+2);
            break;
        case 3:
            for (int j = 0; j < 3; j++) {
                switch (start->card[((int)(start->length/5))*5+j].rank) {
                    case 2: disp_rank[j] = '2'; break;
                    case 3: disp_rank[j] = '3'; break;
                    case 4: disp_rank[j] = '4'; break;
                    case 5: disp_rank[j] = '5'; break;
                    case 6: disp_rank[j] = '6'; break;
                    case 7: disp_rank[j] = '7'; break;
                    case 8: disp_rank[j] = '8'; break;
                    case 9: disp_rank[j] = '9'; break;
                    case 10: disp_rank[j] = 'T'; break;
                    case 11: disp_rank[j] = 'J'; break;
                    case 12: disp_rank[j] = 'Q'; break;
                    case 13: disp_rank[j] = 'K'; break;
                    case 14: disp_rank[j] = 'A'; break;
                    default: break;
                }
                switch (start->card[((int)(start->length/5))*5+j].suit) {
                    case 1: disp_suit[j] = 'H'; break;
                    case 2: disp_suit[j] = 'S'; break;
                    case 3: disp_suit[j] = 'C'; break;
                    case 4: disp_suit[j] = 'D'; break;
                    default: break;
                }
            }
            printf("+_______+  +_______+  +_______+\n");
            printf("| %c     |  | %c     |  | %c     |\n", disp_rank[0], disp_rank[1], disp_rank[2]);
            printf("|       |  |       |  |       |\n");
            printf("|   %c   |  |   %c   |  |   %c   |\n", disp_suit[0], disp_suit[1], disp_suit[2]);
            printf("|       |  |       |  |       |\n");
            printf("|     %c |  |     %c |  |     %c |\n", disp_rank[0], disp_rank[1], disp_rank[2]);
            printf("+-------+  +-------+  +-------+\n");
            printf("    %d          %d          %d      \n", ((int)(start->length/5))*5+1, ((int)(start->length/5))*5+2, ((int)(start->length/5))*5+3);
            break;
        case 4:
            for (int j = 0; j < 4; j++) {
                switch (start->card[((int)(start->length/5))*5+j].rank) {
                    case 2: disp_rank[j] = '2'; break;
                    case 3: disp_rank[j] = '3'; break;
                    case 4: disp_rank[j] = '4'; break;
                    case 5: disp_rank[j] = '5'; break;
                    case 6: disp_rank[j] = '6'; break;
                    case 7: disp_rank[j] = '7'; break;
                    case 8: disp_rank[j] = '8'; break;
                    case 9: disp_rank[j] = '9'; break;
                    case 10: disp_rank[j] = 'T'; break;
                    case 11: disp_rank[j] = 'J'; break;
                    case 12: disp_rank[j] = 'Q'; break;
                    case 13: disp_rank[j] = 'K'; break;
                    case 14: disp_rank[j] = 'A'; break;
                    default: break;
                }
                switch (start->card[((int)(start->length/5))*5+j].suit) {
                    case 1: disp_suit[j] = 'H'; break;
                    case 2: disp_suit[j] = 'S'; break;
                    case 3: disp_suit[j] = 'C'; break;
                    case 4: disp_suit[j] = 'D'; break;
                    default: break;
                }
            }
            printf("+_______+  +_______+  +_______+  +_______+\n");
            printf("| %c     |  | %c     |  | %c     |  | %c     |\n", disp_rank[0], disp_rank[1], disp_rank[2], disp_rank[3]);
            printf("|       |  |       |  |       |  |       |\n");
            printf("|   %c   |  |   %c   |  |   %c   |  |   %c   |\n", disp_suit[0], disp_suit[1], disp_suit[2], disp_suit[3]);
            printf("|       |  |       |  |       |  |       |\n");
            printf("|     %c |  |     %c |  |     %c |  |     %c |\n", disp_rank[0], disp_rank[1], disp_rank[2], disp_rank[3]);
            printf("+-------+  +-------+  +-------+  +-------+\n");
            printf("    %d          %d          %d          %d    \n", ((int)(start->length/5))*5+1, ((int)(start->length/5))*5+2, ((int)(start->length/5))*5+3, ((int)(start->length/5))*5+4);
            break;
        default: break;
    }
} // Ascii art

// Draw a single card in ascii art
void asciiart_demo(CARD flag){
    char disp_rank = '\0';
    char disp_suit = '\0';
    switch (flag.rank) {
        case 2: disp_rank = '2'; break;
        case 3: disp_rank = '3'; break;
        case 4: disp_rank = '4'; break;
        case 5: disp_rank = '5'; break;
        case 6: disp_rank = '6'; break;
        case 7: disp_rank = '7'; break;
        case 8: disp_rank = '8'; break;
        case 9: disp_rank = '9'; break;
        case 10: disp_rank = 'T'; break;
        case 11: disp_rank = 'J'; break;
        case 12: disp_rank = 'Q'; break;
        case 13: disp_rank = 'K'; break;
        case 14: disp_rank = 'A'; break;
    }
    switch (flag.suit) {
        case 1: disp_suit = 'H'; break;
        case 2: disp_suit = 'S'; break;
        case 3: disp_suit = 'C'; break;
        case 4: disp_suit = 'D'; break;
    }
    printf("The previous card is:\n");
    printf("+_______+\n");
    printf("| %c     |\n", disp_rank);
    printf("|       |\n");
    printf("|   %c   |\n", disp_suit);
    printf("|       |\n");
    printf("|     %c |\n", disp_rank);
    printf("+-------+\n");
}

