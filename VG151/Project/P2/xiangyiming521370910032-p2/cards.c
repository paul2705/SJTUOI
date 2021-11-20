#include "cards.h"
#include "game.h"
#include "player.h"
#include <stdlib.h>

void cards_init(game *me) //Init struct variables
{
    me->cards.cardsRemain = malloc(sizeof(int) * 53 * (unsigned long)me->constant.decknum);
    me->cards.cardsQuit = malloc(sizeof(int) * 53 * (unsigned long)me->constant.decknum);
    me->cards.cardOnDesk = -1;
    me->cards.cardsQuit[0] = 0;
    me->cards.cardsRemain[0] = 0;
}

void cards_reinit(game *me)
{
    me->cards.cardOnDesk = -1;
    me->cards.cardsQuit[0] = 0;
    me->cards.cardsRemain[0] = 0;
}

void cards_joinDesk(game *me, int cardid) //Join cardid to cardondesk
{
    cards_quitDesk(me); //Quit this card
    me->cards.cardOnDesk = cardid;
}

void cards_quitDesk(game *me)
{
    if (me->cards.cardOnDesk == -1)
    { //No card on desk
        return;
    }
    me->cards.cardsQuit[0]++;
    me->cards.cardsQuit[me->cards.cardsQuit[0]] = me->cards.cardOnDesk;
    me->cards.cardOnDesk = -1;
}

void cards_reset(game *me) //Reset stock pile
{
    game_fprint(me, "Stock pile exhausted. Shuffling the discard pile and restore the stock pile\n");
    me->cards.cardsRemain[0] = me->cards.cardsQuit[0];
    for (int i = 1; i <= me->cards.cardsQuit[0]; i++)
    {
        me->cards.cardsRemain[i] = me->cards.cardsQuit[i];
        me->cards.cardsQuit[i] = 0;
    }
    //Randomize
    cards_shuffle(me, me->cards.cardsRemain, me->cards.cardsRemain[0]);
    me->cards.cardsQuit[0] = 0;
}

int cards_draw(game *me, player *plr, int n) //Draw player n cards
{

    int getcard;
    for (int i = 1; i <= n; ++i)
    {
        //Judge if cardsreamin=0
        getcard = cards_getCard(me);
        cards_insertCard(plr, getcard);
    }
    if (n == 1)
        return getcard;
    else
        return -1;
}

int cards_getCard(game *me) //Get one card from Remain Cards
{
    if (me->cards.cardsRemain[0] == 0)
        cards_reset(me);
    int res = me->cards.cardsRemain[me->cards.cardsRemain[0]];
    me->cards.cardsRemain[0]--;
    return res;
}

void cards_startTurn(game *me)
{
    int getcard = cards_getCard(me); //Draw one card from remaincard
    cards_joinDesk(me, getcard);     //Put it on the desk
    me->round.cardoverlay = 0;
    game_fprint(me, "---- New turn ----\n");
    char *tmp = game_getCardName(me, getcard);
    game_fprint(me, "Start card: %s\n", tmp);
    free(tmp);
}

void cards_shuffle(game *me, int *arr, int size)
{
    //From arr[1] to arr[size] shuffle
    game_fprint(me, "Shuffling cards...\nShuffle result:\n");
    if (me->constant.demomode)
        game_print("Shuffling cards...\nShuffle result:\n");
    for (int i = 1; i <= size; ++i)
    {
        int cx = (rand() % size) + 1;
        int temp = arr[cx];
        arr[cx] = arr[i];
        arr[i] = temp;
    }
    for (int i = 1; i < size; ++i)
    {
        char *tmp = game_getCardName(me, arr[i]);
        game_fprint(me, "%s, ", tmp);
        if (me->constant.demomode)
            game_print("%s, ", tmp);
        free(tmp);
    }
    char *tmp = game_getCardName(me, arr[size]);
    game_fprint(me, "%s\n\n", tmp);
    if (me->constant.demomode)
        game_print("%s\n\n", tmp);
    free(tmp);
}

void cards_insertCard(player *plr, int cardid)
{
    int totalcard = plr->cardsinhand[0];
    int putin = totalcard + 1;
    for (int i = 1; i <= totalcard; ++i)
    {
        if (cardid <= plr->cardsinhand[i])
        {
            putin = i;
            break;
        }
    }
    //Put cardid here and move all
    for (int i = totalcard; i >= putin; --i)
    {
        plr->cardsinhand[i + 1] = plr->cardsinhand[i];
    }
    plr->cardsinhand[putin] = cardid;
    plr->cardsinhand[0]++;
}

int cards_currentCard(game *me)
{
    return me->cards.cardOnDesk;
}

void cards_deleteCard(player *plr, int cardABSid)
{
    int totalcard = plr->cardsinhand[0];
    for (int i = cardABSid; i < totalcard; ++i)
    {
        plr->cardsinhand[i] = plr->cardsinhand[i + 1];
    }
    plr->cardsinhand[totalcard] = 0;
    plr->cardsinhand[0]--;
}
