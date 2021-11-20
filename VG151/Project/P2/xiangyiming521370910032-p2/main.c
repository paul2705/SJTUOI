#include "game.h"
#include "round.h"
#include "cards.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL)); //Random seed

    game *myGame;
    myGame = (game *)malloc(sizeof(game)); //Malloc myGame
    if (myGame == NULL)
        exit(-1);
    game_init(myGame);             //Initialize myGame
    game_para(argc, argv, myGame); //Deal with parameters

    game_layoutinit(myGame); //Print to logfile
    player_init(myGame);     //Initialize player
    cards_init(myGame);      //Initialize cards
    game_setCards(myGame);   //Deal cards
    round_init(myGame);      //Initialize round
    game_cls(myGame);        //Clear the screen

    while (1) //Start the game
    {
        game_print("Please let Player %d play\n", myGame->round.currentPlayer->player_id + 1);
        if (!myGame->constant.demomode)
            getchar(); //Demomode skip input
        game_cls(myGame);
        round_beforeNext(myGame); //Before one player ends his turn
        round_nextPlayer(myGame); //Change to the next player
        game_cls(myGame);
        if (myGame->constant.demomode)
        {
#ifdef _WIN32
            Sleep(1000);
#else   
            sleep(1);
#endif
        }
    }

    return 0;
}
