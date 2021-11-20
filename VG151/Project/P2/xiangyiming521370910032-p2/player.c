#include "player.h"
#include "cards.h"
#include "game.h"
#include "round.h"
#include <stdio.h>
#include <stdlib.h>

void player_init(game *me) //Initialize player
{
    player *head = (player *)malloc(sizeof(player));
    if (head == NULL)
        exit(-1);
    head->prior = NULL;
    head->next = NULL;
    head->player_id = 0;
    head->current_penalty = 0;
    head->total_penalty = 0;
    head->cardsinhand = malloc(sizeof(int) * 53 * (unsigned long)me->constant.decknum);
    head->cardsinhand[0] = 0;
    head->isOutCard = 0;
    player *list = head;
    for (int i = 1; i < me->constant.playernum; ++i)
    {
        player *newplayer = (player *)malloc(sizeof(player));
        newplayer->prior = list;
        list->next = newplayer;
        newplayer->player_id = i;
        newplayer->current_penalty = 0;
        newplayer->total_penalty = 0;
        newplayer->cardsinhand = malloc(sizeof(int) * 53 * (unsigned long)me->constant.decknum);
        newplayer->cardsinhand[0] = 0;
        newplayer->isOutCard = 0;
        list = list->next; //Next
    }
    list->next = head;
    head->prior = list;
    list = head;
    int firstPlayer = player_random(me);
    while (list->player_id != firstPlayer)
        list = list->next;
    me->round.currentPlayer = list;
}

player *player_nextPlayer(player *plr, int nextnum, int oclock)
{
    if (oclock > 0)
        for (int i = 1; i <= nextnum; ++i)
            plr = plr->next;
    else
        for (int i = 1; i <= nextnum; ++i)
            plr = plr->prior;
    return plr;
}

int player_judgevalid(int input, int output)
{
    //Judge if output card is valid
    if (output / 13 == input / 13)
        return 1;
    if (output % 13 == input % 13)
        return 1;
    return 0;
}

int player_judgevalid_F(game *me, int input, int output)
{
    //Judge if output card is valid(Full)
    if (me->round.cardoverlay > 0)
    {
        //Attack
        if (game_isSkillCard(output))
            return 1;
        else
            return 0;
    }
    if (!player_judgevalid(input, output))
        return 0;
    else
        return 1;
}

int player_random(game *me)
{
    //Random one player
    //Deal an extra card to determine
    int lowrank = 53;
    int dplayer = 0;
    game_fprint(me, "Determining the playing order...\n");
    for (int i = 0; i < me->constant.playernum; ++i)
    {
        int choosecard = rand() % 52;
        char *tmp = game_getCardName(me, choosecard);
        game_fprint(me, "Player %d: %s\n", i + 1, tmp);
        free(tmp);
        if (choosecard < lowrank)
        {
            lowrank = choosecard;
            dplayer = i;
        }
    }
    game_fprint(me, "The game will start with player %d\n\n", dplayer + 1);
    return dplayer;
}

player *player_prevPlayer(game *me)
{
    //Get previous player
    int oc = me->round.oclock;
    oc = (oc > 0) ? -1 : 1;
    int cc = me->cards.cardOnDesk;
    if (cc % 13 == 9)
        return player_nextPlayer(me->round.currentPlayer, 2, oc);
    else
        return player_nextPlayer(me->round.currentPlayer, 1, oc);
}

int player_printPossible(game *me)
{
    //Print all possible cards for current player
    game_print("Choose your card:\n[0]* - Draw card(s)\n");
    int currentCard = cards_currentCard(me);
    player *curPlayer = me->round.currentPlayer;
    int totalCards = curPlayer->cardsinhand[0];
    if (me->round.turnnum == 0)
    {
        //First turn, only consider suit
        int cardnum = curPlayer->cardsinhand[1];
        int cardtimes = 1;
        int reals = 0;
        for (int i = 1; i <= totalCards; ++i)
        {
            int thiscardid = curPlayer->cardsinhand[i];
            if (i == 1 && i < totalCards)
                continue;
            if (thiscardid == cardnum && i < totalCards)
                cardtimes++;
            else
            {
                reals++;
                int flag = 0;
                if (i == totalCards)
                {
                    if (thiscardid == cardnum)
                    {
                        if (totalCards > 1)
                            cardtimes++;
                    }
                    else
                        flag = 1; //Last card and single
                }
                if (currentCard / 13 == cardnum / 13)
                {
                    //Same suit
                    char *info = game_getCardName(me, cardnum);
                    if (cardtimes >= 2)
                        game_print("[%d]* - %s (You have %d this card)\n", reals, info, cardtimes);
                    else
                        game_print("[%d]* - %s\n", reals, info);
                    free(info);
                }
                else
                {
                    //Different suit
                    char *info = game_getCardName(me, cardnum);
                    if (cardtimes >= 2)
                        game_print("[%d] - %s (You have %d this card)\n", reals, info, cardtimes);
                    else
                        game_print("[%d] - %s\n", reals, info);
                    free(info);
                }
                if (flag)
                {
                    char *info = game_getCardName(me, thiscardid);
                    if (currentCard / 13 == thiscardid / 13)
                        game_print("[%d]* - %s\n", reals + 1, info);
                    else
                        game_print("[%d] - %s\n", reals + 1, info);
                    free(info);
                }
                cardtimes = 1;
                cardnum = thiscardid;
            }
        }

        int demooption = 0;
        while (1)
        {
            int inputcard = 0;
            int front = -1;
            if (me->constant.demomode)
            {
                demooption++;
                inputcard = demooption;
                if (demooption > curPlayer->cardsinhand[0])
                    inputcard = 0; //Choose many times
            }
            else
            {
                game_print("Please enter your choice:\n"); //loop
                if (scanf("%d", &inputcard))
                    getchar();
            }
            int fflag = 1;
            if (inputcard == 0)
            {
                curPlayer->isOutCard = 0;
                if (me->constant.demomode)
                    game_print("He draws card(s)\n");
                return -1; //He wants to draw cards
            }
            else
            {
                for (int i = 1; i <= totalCards; ++i)
                {
                    int thiscardid = curPlayer->cardsinhand[i];
                    if (thiscardid == front)
                        continue;
                    inputcard--;
                    if (inputcard == 0)
                    {
                        inputcard = thiscardid;
                        fflag = 0;
                        break;
                    }
                    front = thiscardid;
                }
                if (fflag)
                    continue; //Invalid parameter
                if (currentCard / 13 != inputcard / 13)
                    continue;

                if (me->constant.demomode)
                {
                    char *tmp = game_getCardName(me, inputcard);
                    game_print("He plays %s\n", tmp);
                    free(tmp);
                }
                player_pushCard(me, curPlayer, inputcard);
                return inputcard;
            }
        }
    }
    else
    {
        //turnnum>0
        //Consider other things
        int cardnum = curPlayer->cardsinhand[1];
        int cardtimes = 1;
        int reals = 0;
        for (int i = 1; i <= totalCards; ++i)
        {
            int thiscardid = curPlayer->cardsinhand[i];
            if (i == 1 && i < totalCards)
                continue;
            if (thiscardid == cardnum && i < totalCards)
                cardtimes++;
            else
            {
                reals++;
                int flag = 0;
                if (i == totalCards)
                {
                    if (thiscardid == cardnum)
                    {
                        if (totalCards > 1)
                            cardtimes++;
                    }
                    else
                        flag = 1; //Last card and single
                }
                if (player_judgevalid_F(me, currentCard, cardnum))
                {
                    //Same suit
                    char *info = game_getCardName(me, cardnum);
                    if (cardtimes >= 2)
                        game_print("[%d]* - %s (You have %d this card)\n", reals, info, cardtimes);
                    else
                        game_print("[%d]* - %s\n", reals, info);
                    free(info);
                }
                else
                {
                    //Different suit
                    char *info = game_getCardName(me, cardnum);
                    if (cardtimes >= 2)
                        game_print("[%d] - %s (You have %d this card)\n", reals, info, cardtimes);
                    else
                        game_print("[%d] - %s\n", reals, info);
                    free(info);
                }
                if (flag)
                {
                    char *info = game_getCardName(me, thiscardid);
                    if (player_judgevalid_F(me, currentCard, thiscardid))
                        game_print("[%d]* - %s\n", reals + 1, info);
                    else
                        game_print("[%d] - %s\n", reals + 1, info);
                    free(info);
                }
                cardtimes = 1;
                cardnum = thiscardid;
            }
        }
        int demooption = 0;
        while (1)
        {
            int inputcard;
            int front = -1;
            if (me->constant.demomode)
            {
                demooption++;
                inputcard = demooption;
                if (demooption > curPlayer->cardsinhand[0])
                    inputcard = 0; //Choose many times
            }
            else
            {
                game_print("Please enter your choice:\n"); //loop
                if (scanf("%d", &inputcard))
                    getchar();
            }
            int fflag = 1;
            if (inputcard == 0)
            {
                curPlayer->isOutCard = 0;
                if (me->constant.demomode)
                    game_print("He draws card(s)\n");
                return -1; //He wants to draw cards
            }
            else
            {
                for (int i = 1; i <= totalCards; ++i)
                {
                    int thiscardid = curPlayer->cardsinhand[i];
                    if (thiscardid == front)
                        continue;
                    inputcard--;
                    if (inputcard == 0)
                    {
                        inputcard = thiscardid;
                        fflag = 0;
                        break;
                    }
                    front = thiscardid;
                }
                if (fflag)
                    continue; //Invalid parameter
                if (!player_judgevalid_F(me, currentCard, inputcard))
                    continue;
                 if (me->constant.demomode)
                {
                    char *tmp = game_getCardName(me, inputcard);
                    game_print("He plays %s\n", tmp);
                    free(tmp);
                }
                player_pushCard(me, curPlayer, inputcard);
                return inputcard;
            }
        }
    }
}

void player_pushCard(game *me, player *plr, int cardid)
{
    //Push card cardid
    char *tmp = game_getCardName(me, cardid);
    game_fprint(me, "Player %d plays: %s\n", plr->player_id + 1, tmp);
    free(tmp);
    for (int i = 1; i <= plr->cardsinhand[0]; ++i)
        if (plr->cardsinhand[i] == cardid)
        {
            cards_deleteCard(plr, i);
            cards_joinDesk(me, cardid);
            break;
        }
    plr->isOutCard = 1;
}

player *player_getPlayer(game *me, int num)
{
    player *cur = me->round.currentPlayer;
    while (cur->player_id != num)
        cur = cur->next;
    return cur;
}
