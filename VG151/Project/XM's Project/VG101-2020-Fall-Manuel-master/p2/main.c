#include <stdlib.h>
#include "card.h"
#include "player.h"
#include "action.h"

int main(int argc, char *argv[]){
    // Scan values of variables from command line
    int deck = DECK, user = USER, initial = DEFAULT, round = ROUND, mode = 0; // For definition go to #DEFINE
    int parameter[6]; parameter[0] = deck; parameter[1] = user; parameter[2] = initial; parameter[3] = round; parameter[4] = mode; parameter[5] = 0;
    char *str = malloc(100); str[0] = '\0';  // contains filename
    initialize(argc, argv, str, parameter); // An array containing parameters from command line
    FILE * fp;
    if (parameter[5] == 0) {
        fp = fopen("onecard.log","w");
        if (fp == NULL) {exit(-1);}
    }
    else if (parameter[5] == 1){
       fp = fopen(str,"w");
       if (fp == NULL) {exit(-1);}
    }
    else {return -1;}
    deck = parameter[0];
    user = parameter[1];
    initial = parameter[2];
    round = parameter[3];
    mode = parameter[4]; // Pass parameters from function
    if (initial*user > deck*SUM) {printf("Not enough cards. Please manually restart the game.\n"); getchar();}
    welcome(deck, initial, user, round, fp); // Print welcome message

    // Initialize all parameters
    CARD* pile; // A pointer representing the initial card array
    PLAYER* head; PLAYER* start; // A pointer representing the first player
    int game; // Show that a game is running
    CARD flag;// A card structure providing judges for the next player
    CARD intermediate[2]; CARD * temp = intermediate; // A card pointer played by the previous player
    int draw; // The number of cards a player needs to draw in one round
    int attack; // To judge whether a player is under attack
    int reverse; // To judge the playing sequence
    head = initlist(user, initial); // Initialize player data

    // Run the game!
    for(int i = 0; i < round; i++) {
        // Generate a card pile and distribute cards to each player
        pile = initial_card(deck, mode, fp);
        head = deal(head, pile, user, initial, deck);
        game = 1; draw = 0; attack = 0; reverse = 0;
        // Initialize all parameters
        int result[4]; result[3] = game; result[1] = draw; result[2] = attack; result[0] = reverse;
        flag.rank = 2, flag.suit = HEARTS;
        temp[1].rank = 0, temp[1].suit = 0; temp[0] = flag;
        start = sequence(head, user, fp); // Decide a sequence
        while (game != 0) {
            if (temp[1].rank == 0 && temp[0].rank != 0) {flag = temp[0];}
            else if (temp[1].rank!=0) {flag = temp[1];} // Judge what card the next player should play
            status(user, start, fp);
            if (mode == 1) {
                printf("The previous card is: ");
                fprintf(fp,"The previous card is: ");
                display(flag.rank, flag.suit, fp); printf("\n"); fprintf(fp,"\n");
            }
            else {asciiart_demo(flag);} // Display the card the player should follow
            play(temp, start, flag, attack, mode, fp); // Judge if a card is played
            effect(result, temp, pile, start, draw, user, attack, game, reverse, fp); // implement special effect of cars
            reverse = result[0];
            draw = result[1];
            attack = result[2];
            game = result[3]; // Pass parameters from function to loop
            start = pass(temp, start, reverse); // Move to the next player
            if (mode == 0) {CLEAR();}
        } // Play a round!
        scoreboard(start, user, fp, i, round); // Print the result of the game
        free(pile);
        getchar();
    }

    fclose(fp);
    free_player(head, user);
    free(str);

    return 0;
}
