#include "action.h"

// Scan values of variables from command line
void initialize(int argc, char *argv[], char * str, int * parameter)
{
    int opt;
    int option_index = 0;
    char *string = "l::n:c:r:d:ha";
    static struct option long_options[] =
            {
                    {"log", required_argument,NULL, 'l'},
                    {"player-number", optional_argument,NULL, 'n'},
                    {"card", optional_argument,NULL, 'c'},
                    {"round", optional_argument,NULL, 'r'},
                    {"deck", optional_argument,NULL, 'd'},
                    {"help", no_argument, NULL,'h'},
                    {"auto", no_argument, NULL,'a'},
            };
    while((opt =getopt_long_only(argc,argv,string,long_options,&option_index))!= -1)
    {
        switch (opt) {
            case 'n':  parameter[1] = atoi(optarg); break;
            case 'c': parameter[2] = atoi(optarg); break;
            case 'd': parameter[0] = atoi(optarg); break;
            case 'r': parameter[3] = atoi(optarg); break;
            case 'h':
                printf("./onecard -h\n"
                       "-h|--help print this help message\n"
                       "--log| filename write the logs in filename (default: onecard.log)\n"
                       "-n n|--player-number=n n players, n must be larger than 2 (default: 4)\n"
                       "-c c|--card=c deal c cards per player, c must be at least 2 (default: 5)\n"
                       "-d d|--deck=d use d decks 52 cards each, d must be at least 2 (default: 2)\n"
                       "-r r|--round=r play r rounds, r must be at least 1 (default: 1)\n"
                       "-a|--auto run in demo mode with default parameters\n");
                printf("\n");
                printf("Press enter to exit...\n");
                getchar();
                parameter[5] = -1;
                break;
            case 'a':
                printf("Entering demo mode... A demo played automatically by computer will be presented for you:\n");
                parameter[4] = 1;
                printf("\n");
                break;
            case 'l':
                memcpy(str, optarg, strlen(optarg));
                parameter[5] = 1;
                break;
            default:
                parameter[5] = -1;
        }
    }
}

// Judge and play a card, a.k.a removing a certain card from the player's card pile
void play(CARD *target, PLAYER *start, CARD flag, int attack, int mode, FILE * fp){
    CARD * p = start->card;
    target[0].suit = 0; target[0].rank = 0; target[1].suit = 0; target[1].rank = 0;
    int available[start->length];
    for (int i=0; i<start->length; i++) {available[i] = 0;}
    int decide = 0; int judge = 0; int judge2 = 0; int input = 0; // Initialize all parameters
    start = sort(start);
    if (attack == 1) {
        printf("Player %d is under attack!\n", start->id);
        fprintf(fp,"Player %d is under attack!\n", start->id);
    } // Print attack message
    if (start->length != 0 && mode == 0) {
        printf("Player %d's cards: (from 1 to %d)\n", start->id, start->length);
        asciiart(start);
    } // Draw human player's cards in ascii art
    if (mode == 1) {
        show_status(start,fp);
        printf("Player %d now has %d cards\n", start->id, start->length);
        fprintf(fp,"Player %d now has %d cards\n", start->id, start->length);
    } // Print each player's status in auto mode

    if (attack == 0){
        for (int i=0; i < start->length; i++) {
            if ((p+i)->suit==flag.suit || (p+i)->rank==flag.rank) {
                available[i] = 1;
            }
        } // Scan for possible cards to play
        for (int i=0; i < start->length; i++) {
            if(available[i] == 1){
                judge = 1;
            }
        } // Judge whether a player can play a card
        if (mode == 0) {
            if (judge == 1) {
                printf("Please enter number to play the first card, input 0 to jump the round: \n");
                if(scanf("%d", &input)){};
                while (getchar() != '\n');
                if (input != 0) {
                    while (available[input-1] == 0) {
                        printf("Not available, please enter another number: \n");
                        if(scanf("%d", &input)){};
                        while (getchar() != '\n');
                    }
                    decide = input - 1;
                    target[0].rank = (p + decide)->rank;
                    target[0].suit = (p + decide)->suit;
                    for (int k = decide; k < start->length - 1; k++) {
                        *(p + k) = *(p + k + 1);
                        decide--;
                    }
                    (p + start->length - 1)->suit = 0;
                    (p + start->length - 1)->rank = 0;
                    start->length = start->length - 1;
                } // Delete a card from the card pile
            }
            else {
                printf("No available cards to be played\n");
                fprintf(fp,"No available cards to be played\n");
            } // Manually select cards
        }
        else {
            for (int i=0; i < start->length; i++) {
                if(available[i] == 1){
                    decide = i; judge = 1; break;
                }
            }
            if (judge == 1) {
                target[0].rank = (p + decide)->rank;
                target[0].suit = (p + decide)->suit;
                for (int k = decide; k < start->length - 1; k++) {
                    *(p + k) = *(p + k + 1);
                    decide--;
                }
                (p + start->length - 1)->suit = 0;
                (p + start->length - 1)->rank = 0;
                start->length = start->length - 1;
            } // Delete a card from the card pile
        } // Automatically select a card
    }
    else{
        for (int i=0; i < start->length; i++){
            if ((p+i)->rank==2 || (p+i)->rank==3
                     || ((p+i)->suit==flag.suit && (p+i)->rank==7)
                     || ((p+i)->suit==flag.suit && (p+i)->rank==QUEEN)||(flag.rank==QUEEN && (p+i)->rank==QUEEN)
                     || ((p+i)->suit==flag.suit && (p+i)->rank==JACK)||(flag.rank==JACK && (p+i)->rank==JACK)){
                available[i] = 1;
            }
        } // Scan for possible cards to play
        for (int i=0; i < start->length; i++) {
            if(available[i] == 1){
                judge = 1;
            }
        }
        if (mode == 0){
            if (judge == 1) {
                printf("Please enter number to play the first card, input 0 to jump the round: \n");
                if(scanf("%d", &input)){};
                while (getchar() != '\n');
                if (input != 0) {
                    while (available[input-1] == 0) {
                        printf("Not available, please enter another number: \n");
                        if(scanf("%d", &input)){};
                        while (getchar() != '\n');
                    }
                    decide = input - 1;
                    target[0].rank = (p + decide)->rank;
                    target[0].suit = (p + decide)->suit;
                    for (int k = decide; k < start->length - 1; k++) {
                        *(p + k) = *(p + k + 1);
                        decide--;
                    }
                    (p + start->length - 1)->suit = 0;
                    (p + start->length - 1)->rank = 0;
                    start->length = start->length - 1;
                }
            } // Delete a card from the card pile
            else {
                printf("No available cards to be played\n");
                fprintf(fp,"No available cards to be played\n");
            }
        }
        else {
            for (int i=0; i<start->length; i++) {
                if(available[i] == 1){
                    decide = i; judge = 1;
                    break;
                }
            }
            if (judge == 1) {
                target[0].rank = (p + decide)->rank;
                target[0].suit = (p + decide)->suit;
                for (int k = decide; k < start->length - 1; k++) {
                    *(p + k) = *(p + k + 1);
                    decide--;
                }
                (p + start->length - 1)->suit = 0;
                (p + start->length - 1)->rank = 0;
                start->length = start->length - 1;
            }
        }
    }
    if (target[0].rank == 2 || target[0].rank == 3) {attack = 1;}
    if (target[0].rank == 7) {attack = 0;} // Judge the attack mode
    show_action1(start, target , mode, fp);
    if (target[0].rank==0) {printf("\n");fprintf(fp,"\n"); return;}
    if (attack == 1) {
        printf("Player %d imposes(passes) an attack!\n", start->id);
        fprintf(fp,"Player %d imposes(passes) an attack!\n", start->id);
    } // Show result of the first round
        if (mode == 0) {
            printf("Player %d now has %d cards\n", start->id, start->length);
            fprintf(fp,"Player %d now has %d cards\n", start->id, start->length);
            printf("Player %d's cards: (from 1 to %d)\n", start->id, start->length);
            asciiart(start);
        }
        else {
            show_status(start,fp);
            printf("Player %d now has %d cards\n", start->id, start->length);
            fprintf(fp,"Player %d now has %d cards\n", start->id, start->length);
        } // Show player status in the second round
    int available2[start->length];
    for (int i=0; i<start->length; i++) {available2[i] = 0;}
    flag = target[0];

    if (attack == 0){
            for (int i=0; i<start->length; i++){
                if ((p+i)->suit==flag.suit || (p+i)->rank==flag.rank){
                    available2[i] = 1;
                }
            }
            for (int i=0; i<(start->length); i++){
                if(available2[i] == 1){
                    judge2 = 1;
                }
            }
            if (mode == 0) {
                if (judge2 == 1) {
                    printf("Please enter number to play the second card, input 0 to jump the round: \n");
                    if(scanf("%d", &input)){};
                    while (getchar() != '\n');
                    if (input != 0) {
                        while (available2[input-1] == 0) {
                            printf("Not available, please enter another number: \n");
                            if(scanf("%d", &input)){};
                            while (getchar() != '\n');
                        }
                        decide = input - 1;
                        target[1].rank = (p + decide)->rank;
                        target[1].suit = (p + decide)->suit;
                        for (int k = decide; k < start->length - 1; k++) {
                            *(p + k) = *(p + k + 1);
                            decide--;
                        }
                        (p + start->length - 1)->suit = 0;
                        (p + start->length - 1)->rank = 0;
                        start->length = start->length - 1;
                    }
                }
                else {
                    if(target[1].rank != 0) {
                        printf("No available cards to be played\n");
                    }
                }
            }
            else {
                for (int i=0; i<start->length; i++) {
                    if(available2[i] == 1){
                        decide = i; judge2 = 1; break;
                    }
                }
                if (judge2 == 1) {
                    target[1].rank = (p + decide)->rank;
                    target[1].suit = (p + decide)->suit;
                    for (int k = decide; k < start->length - 1; k++) {
                        *(p + k) = *(p + k + 1);
                        decide--;
                    }
                    (p + start->length - 1)->suit = 0;
                    (p + start->length - 1)->rank = 0;
                    start->length = start->length - 1;
                }
            }
        }
    else{
            for (int i=0; i<start->length; i++){
                if ((p+i)->rank==2 || (p+i)->rank==3
                         || ((p+i)->suit==flag.suit && (p+i)->rank==7)
                         || ((p+i)->suit==flag.suit && (p+i)->rank==QUEEN)||(flag.rank==QUEEN && (p+i)->rank==QUEEN)
                         || ((p+i)->suit==flag.suit && (p+i)->rank==JACK)||(flag.rank==JACK && (p+i)->rank==JACK)) {
                    available2[i] = 1;
                }
            }
            for (int i=0; i<start->length; i++){
                if(available2[i] == 1){
                    judge2 = 1;
                }
            }
            if (mode == 0) {
                if (judge2 == 1) {
                    printf("Please enter number to play the second card, input 0 to jump the round: \n");
                    if(scanf("%d", &input)){};
                    while (getchar() != '\n');
                    if (input != 0) {
                        while (available2[input-1] == 0) {
                            printf("Not available, please enter another number: \n");
                            if(scanf("%d", &input)){};
                            while (getchar() != '\n');
                        }
                        decide = input - 1;
                        target[1].rank = (p + decide)->rank;
                        target[1].suit = (p + decide)->suit;
                        for (int k = decide; k < start->length - 1; k++) {
                            *(p + k) = *(p + k + 1);
                            decide--;
                        }
                        (p + start->length - 1)->suit = 0;
                        (p + start->length - 1)->rank = 0;
                        start->length = start->length - 1;
                    }
                }
                else {
                    if(target[1].rank != 0) {
                        printf("No available cards to be played\n");
                    }
                }
            }
            else {
                for (int i=0; i<start->length; i++) {
                    if(available2[i] == 1){
                        decide = i; judge2 = 1;
                        break;
                    }
                }
                if (judge2 == 1) {
                    target[1].rank = (p + decide)->rank;
                    target[1].suit = (p + decide)->suit;
                    for (int k = decide; k < start->length; k++) {
                        *(p + k) = *(p + k + 1);
                        decide--;
                    }
                    (p + start->length - 1)->suit = 0;
                    (p + start->length - 1)->rank = 0;
                    start->length = start->length - 1;
                }
            }
        }
    if(start->length != 0) {
        show_action2(start, target, mode, fp);
    }
    printf("\n");
}

// Show effect passed on the next player
void effect(int * result, CARD* temp, CARD* pile, PLAYER* start, int draw, int user, int attack, int game, int reverse, FILE * fp){
    // If the player has no card to play
    if ((temp[0].suit == 0) && (temp[0].rank == 0)) {
        take(pile, start, draw, fp); // The player draw a card from the card pile
        draw = 0; attack = 0;
    }
    // If the player plays one special card or another is a regular card
    else if ((temp[1].rank!=2 && temp[1].rank!=3 && temp[1].rank!=7 && temp[1].rank!=QUEEN)||
             (temp[0].rank!=2 && temp[0].rank!=3 && temp[0].rank!=7 && temp[0].rank!=QUEEN)) {
        if (temp[0].rank==2 || temp[0].rank==3) {
            discard(pile, temp); // Return the played card to the original card pile
            if (start->card[0].rank==0 && start->card[0].suit==0) {
                game = win(start, user, game, fp); result[3] = game;
            } // Judge the winning condition
            draw = draw + temp[0].rank; attack = 1;
        }
        else if (temp[0].rank==7 || temp[1].rank==7) {
            discard(pile, temp); // Return the played card to the original card pile
            if (start->card[0].rank==0 && start->card[0].suit==0) {
                game = win(start, user, game, fp); result[3] = game;
            } // Judge the winning condition
            draw = 0; attack = 0;
        }
        else if (temp[0].rank==QUEEN || temp[1].rank==QUEEN) {
            discard(pile, temp); // Return the played card to the original card pile
            if (start->card[0].rank==0 && start->card[0].suit==0) {
                game = win(start, user, game, fp); result[3] = game;
            } // Judge the winning condition
            reverse = 1 - reverse;
        }
        else if (temp[1].rank==2 || temp[1].rank==3){
            discard(pile, temp); // Return the played card to the original card pile
            if (start->card[0].rank==0 && start->card[0].suit==0) {
                game = win(start, user, game, fp);  result[3] = game;
            } // Judge the winning condition
            draw = draw + temp[1].rank; attack = 1;
        }
        else{
            discard(pile, temp); // Return the played card to the original card pile
            if (start->card[0].rank==0 && start->card[0].suit==0) {
                game = win(start, user, game, fp); result[3] = game;
            } // Judge the winning condition
        }
    }
    else{
        if ((temp[0].rank==2 || temp[0].rank==3) && (temp[1].rank==2 || temp[1].rank==3)){
            discard(pile, temp); // Return the played card to the original card pile
            if (start->card[0].rank==0 && start->card[0].suit==0) {
                game = win(start, user, game, fp); result[3] = game;
            } // Judge the winning condition
            draw = draw + temp[0].rank + temp[1].rank; attack = 1;
        }
        else if (((temp[0].rank==2 || temp[0].rank==3) && (temp[1].rank==7))||
                 ((temp[0].rank==7) && (temp[1].rank==7))){
            discard(pile, temp); // Return the played card to the original card pile
            if (start->card[0].rank==0 && start->card[0].suit==0) {
                game = win(start, user, game, fp); result[3] = game;
            } // Judge the winning condition
            draw = 0; attack = 0;
        }
        else if ((temp[1].rank==2 || temp[1].rank==3) && (temp[0].rank==7)){
            discard(pile, temp); // Return the played card to the original card pile
            if (start->card[0].rank==0 && start->card[0].suit==0) {
                game = win(start, user, game, fp); result[3] = game;
            } // Judge the winning condition
            draw = temp[1].rank; attack = 1;
        }
        else if ((temp[0].rank==2 || temp[0].rank==3) && (temp[1].rank==QUEEN)){
            discard(pile, temp); // Return the played card to the original card pile
            if (start->card[0].rank==0 && start->card[0].suit==0) {
                game = win(start, user, game, fp); result[3] = game;
            } // Judge the winning condition
            draw = draw + temp[0].rank; attack = 1; reverse = 1 - reverse;
        }
        else if ((temp[1].rank==2 || temp[1].rank==3) && (temp[0].rank==QUEEN)){
            discard(pile, temp); // Return the played card to the original card pile
            if (start->card[0].rank==0 && start->card[0].suit==0) {
                game = win(start, user, game, fp); result[3] = game;
            } // Judge the winning condition
            draw = draw + temp[1].rank; attack = 1; reverse = 1 - reverse;
        }
        else if (((temp[0].rank==7) && (temp[1].rank==QUEEN))||
                 ((temp[1].rank==7) && (temp[0].rank==QUEEN))){
            discard(pile, temp); // Return the played card to the original card pile
            if (start->card[0].rank==0 && start->card[0].suit==0) {
                game = win(start, user, game, fp); result[3] = game;
            } // Judge the winning condition
            draw = 0; attack = 0; reverse = 1 - reverse;
        }
        else if ((temp[1].rank==QUEEN) && (temp[0].rank==QUEEN)){
            discard(pile, temp); // Return the played card to the original card pile
            if (start->card[0].rank==0 && start->card[0].suit==0) {
                game = win(start, user, game, fp); result[3] = game;
            } // Judge the winning condition
        }
    }
    result[0] = reverse; result[1] = draw; result[2] = attack; result[3] = game;
}

// Move to the next player
PLAYER *pass(CARD* temp, PLAYER* start, int reverse) {
    if (reverse == 0) {
        if ((temp[0].rank == JACK && temp[1].rank != JACK) || (temp[1].rank == JACK && temp[0].rank != JACK)) {
            start = start->next;
        } else if (temp[0].rank == JACK && temp[1].rank == JACK) {
            start = start->next;
            start = start->next;
            start = start->next;
        }
    } else {
        if ((temp[0].rank == JACK && temp[1].rank != JACK) || (temp[1].rank == JACK && temp[0].rank != JACK)) {
            start = start->prev;
        } else if (temp[0].rank == JACK && temp[1].rank == JACK) {
            start = start->prev;
            start = start->prev;
            start = start->prev;
        }
    }
    if (reverse == 0) {
        start = start->next;
    } else {
        start = start->prev;
    }

    return start;
}

// Sort cards
PLAYER *sort(PLAYER* start) {
    for (int j = 0; j < start->length; j++) {
        for (int i = 0; i < (start->length-1); i++) {
            if ((start->card[i].rank + start->card[i].suit*13) > (start->card[i+1].rank + start->card[i+1].suit*13)) {
                CARD temp;
                temp = start->card[i];
                start->card[i] = start->card[i+1];
                start->card[i+1] = temp;
            }
        }
    }
    return start;
}

// Take several cards from the original card pile to the player's card pile
void take(CARD* pile, PLAYER* start, int draw, FILE * fp){
    if(draw == 0) {
        draw = 1;
    }
    printf("Player %d draws: ", start->id);
    fprintf(fp,"Player %d draws: ", start->id);
    for (int j = 0; j < draw; j++) {
        int i = 1;
        int k = 0;
        while (pile[i].rank!=0||pile[i].suit!=0){
            i++;
        }
        while (start->card[k].rank!=0||start->card[k].suit!=0){
            k++;
        }
        start->card[k].rank = pile[i-1].rank;
        start->card[k].suit = pile[i-1].suit;
        if (start->card[k].rank == 0) {
            printf("Pile exhausted, now all the cards are in players' hands and the game requires manual restart\n");
            getchar();
        }
        display(start->card[k].rank, start->card[k].suit, fp);
        pile[i-1].rank = 0;
        pile[i-1].suit = 0;
        start->length = start->length + 1;
        randomize(pile, (i-1));
    }
    printf("\n\n");
    fprintf(fp,"\n\n");
}

// Return the played card to the original pile then shuffle
void discard(CARD* pile, CARD * temp){
    int i = 0;
    while (pile[i].rank!=0 || pile[i].suit!=0){
        i++;
    }
    if (temp[0].rank != 0) {
        for (int k=(i-1); k>=0; k--){
            pile[k+1] = pile[k];
        }
        pile[0] = temp[0];
    }
    i = 0;
    if (temp[1].rank != 0) {
        while (pile[i].rank!=0 || pile[i].suit!=0){
            i++;
        }
        for (int k=(i-1); k>=0; k--){
            pile[k+1] = pile[k];
        }
        pile[0] = temp[1];
    }
}
