#include <stdlib.h>
#include "player.h"
#include "display.h"

// Generate USER players with DEFAULT cards and respective id, score
PLAYER *initlist(int user, int initial){
    // init the head player
    PLAYER* head = (PLAYER*) malloc(sizeof(PLAYER));
    if(head==NULL) {
        printf("Player initialization failed.\n");
        exit(0);
    }
    else{
        head->next=NULL;
        head->prev=NULL;
        head->id=1;
        head->score=0;
        head->length=initial;
    }
    // init the remaining players
    if (user < 2)
        printf("Serious? One card with only one player is meaningless.\n");
    else{
        PLAYER* temp = head;
        for(int i=0; i<user-1; ++i){
            PLAYER * new_player = (PLAYER*)malloc(sizeof(PLAYER));
            temp->next = new_player;
            new_player->prev = temp;
            new_player->score = 0;
            new_player->id = i + 2;
            new_player->length = initial;
            temp = new_player;
        }
        temp->next = head;
        head->prev = temp;
    }
    PLAYER* temp = head;
    for (int i = 0; i < user; i++) {
        for (int j = 0; j < 100; j++) {
            temp->card[j].rank = 0;
            temp->card[j].suit = 0;
        }
        temp = temp->next;
    }
    return head;
}

// Deal respective cards to each player
PLAYER *deal(PLAYER *head, CARD *card, int user, int initial, int deck) {
    PLAYER* temp = head;
    for (int i = 0; i < user; i++) {
        for (int j = 0; j < 100; j++) {
            temp->card[j].rank = 0;
            temp->card[j].suit = 0;
        }
        temp->length = initial;
        temp = temp->next;
    }
    for (int i=0; i < user; i++){
        for (int j = 0; j < initial; j++){
            temp->card[j] = card[deck*SUM-1-i*initial-j];
            card[deck*SUM-1-i*initial-j].suit = 0;
            card[deck*SUM-1-i*initial-j].rank = 0;
        }
        temp = temp->next;
    }
    return head;
}

// Decide the sequence of the players
PLAYER *sequence(PLAYER *head, int user, FILE * fp){
    // Each player draws a card and the holder of the card with biggest sum goes first
    int compare[user];
    int result = 0;
    PLAYER* temp = head;
    PLAYER* start = NULL;
    printf("Determining the playing order...\n");
    fprintf(fp,"Determining the playing order...\n");
    for (int i=0; i < user; i++) {
        printf("Player %d: ", temp->id);
        fprintf(fp,"Player %d: ", temp->id);
        display(temp->card[0].rank, temp->card[0].suit,fp);
        printf("\n");
        fprintf(fp,"\n");
        compare[i] = temp->card[0].rank;
        temp = temp->next;
    }
    for (int i=0, min=compare[0]; i<user; i++){
        if (compare[i]<min){
            min = compare[i];
            result = i;
        }
    }
    for (int i=0; i < user; i++){
        if (i==result) {
            printf("The game will start with player %d\n", temp->id);
            printf("\n");
            fprintf(fp,"The game will start with player %d\n", temp->id);
            fprintf(fp,"\n");
            start = temp;
        }
        temp = temp->next;
    }

    return start;
}

// Free memory usage
void free_player(PLAYER * player, int user){
    PLAYER* victim = player;
    for(int i=0; i<user; ++i){
        PLAYER* temp = victim->next;
        free(victim);
        victim = temp;
    }
}
