#include "round.h"
#include "game.h"
#include "cards.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>

void round_init(game *me)
{
    me->round.oclock = (rand() % 2 == 1) ? 1 : -1;
    me->round.cardoverlay = 0;
    me->round.turnnum = 0;
    me->round.roundnum = 0;
    game_fprint(me, "---- Game start ----\n");
    char *tmp = game_getCardName(me, me->cards.cardOnDesk);
    game_fprint(me, "Start card: %s\n", tmp);
    free(tmp);
}

void round_printGeneralInfo(game *me)
{
    //Print genral information on screen
    int currentCard = cards_currentCard(me);
    player *currentPlayer = me->round.currentPlayer;
    player *nextPlayer = player_nextPlayer(currentPlayer, 1, me->round.oclock);
    char *str = game_getCardName(me, currentCard);
    int cov = me->round.cardoverlay;
    game_print("Card on the desk: %s\n", str);
    game_print("You are player %d.\n", currentPlayer->player_id + 1);
    game_print("Next player shall be: Player %d\n", nextPlayer->player_id + 1);
    free(str);
    if (cov != 0)
        game_print("Under attack: %d Cards\n", cov);
}

void round_beforeNext(game *me)
{
    //Current player
    int flag = 0;
    player *curPlayer = me->round.currentPlayer;
    player *prevPlayer = player_prevPlayer(me);
    int hiscard = cards_currentCard(me);
    int playnew; //New card he plays

    round_printGeneralInfo(me); //Print general information
    if (me->round.turnnum == 0)
    {
        //New turn, only consider suits(should already init new turn)
        if (player_printPossible(me) == -1)
        {
            //He draws one card
            int tca = cards_draw(me, curPlayer, 1);
            char *tmp = game_getCardName(me, tca);
            game_fprint(me, "Player %d draws 1 card: %s\n", curPlayer->player_id + 1, tmp);
            free(tmp);
        }
        return;
    }

    if (prevPlayer->isOutCard) //Judge if previous player pushed cards
    {
        if (me->round.cardoverlay > 0)
        {
            //+2/+3 Card
            for (int i = 1; i <= curPlayer->cardsinhand[0]; ++i)
            {
                int thisc = curPlayer->cardsinhand[i];
                if (game_isSkillCard(thisc))
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                //Add cards directly
                game_print("You have no card to play, pass!\n");
                round_endTurn(me);
                return;
            }
        }
    }
    playnew = player_printPossible(me);
    if (flag)
    {
        //He may defends
        if (playnew == -1)
        {
            //He draws cards(many cards)
            //Add cards directly
            round_endTurn(me);
            return;
        }
        else //He use skills so push card
        {
            if (playnew % 13 == 5) //Cancel attack
                me->round.cardoverlay = 0;
        }
    }
    else
    {
        if (playnew == -1)
        {
            //He draws card
            int condraw = 1;
            int tc = cards_draw(me, curPlayer, 1); //Draw one card
            char *tmp = game_getCardName(me, tc);
            game_fprint(me, "Player %d draws 1 card: %s\n", curPlayer->player_id + 1, tmp);
            free(tmp);
            if (player_judgevalid(hiscard, tc))
            {
                char *info = game_getCardName(me, tc);
                game_print("You have got card:%s, which can be used. Do you want to use this card?(1/0)\n", info);
                free(info);
                int ans;
                if (me->constant.demomode){
                    game_print("Yes, use this card\n");
                    ans = 1;
                }
                else
                {
                    if (scanf("%d", &ans))
                        getchar();
                }
                if (ans == 1)
                {
                    condraw = 0; //Cancel draw
                    player_pushCard(me, curPlayer, tc);
                }
                else
                {
                    if (ans != 0)
                        game_print("Invalid, defult no");
                }
            }
            if (condraw)
            {
                //Confirm he draws
                curPlayer->isOutCard = 0;
            }
        }
    }
}

void round_endTurn(game *me)
{
    cards_quitDesk(me);
    player *curPlayer = me->round.currentPlayer;
    cards_draw(me, curPlayer, me->round.cardoverlay);
    //DisPlay TODO
    game_fprint(me, "Player %d draws %d cards\n", curPlayer->player_id + 1, me->round.cardoverlay);
    //Next turn

    me->round.cardoverlay = 0;
    me->round.currentPlayer->isOutCard = 0;
    me->round.turnnum = 0;
    cards_startTurn(me); //Start a new turn
    return;
}

void round_nextPlayer(game *me) //According to oclock and cards push to next player
{
    //Next player
    player *curPlayer = me->round.currentPlayer;
    if (curPlayer->cardsinhand[0] == 0) //Judge if should go next round
    {
        //Deal with final card
        if (me->cards.cardOnDesk % 13 == 0 || me->cards.cardOnDesk % 13 == 1)
        {
            //He attacks
            me->round.cardoverlay += me->cards.cardOnDesk % 13 + 2;
        }
        if (game_isSkillCard(me->cards.cardOnDesk % 13) && me->cards.cardOnDesk % 13 != 5)
        {
            if (me->cards.cardOnDesk % 13 == 9)
            {
                //Skip
                player *tp = player_nextPlayer(curPlayer, 2, me->round.oclock);
                cards_draw(me, tp, me->round.cardoverlay);
            }
            else if (me->cards.cardOnDesk % 13 == 10)
            {
                //Reverse
                player *tp = player_prevPlayer(me);
                cards_draw(me, tp, me->round.cardoverlay);
            }
            else
            {
                //Attacks
                player *tp = player_nextPlayer(curPlayer, 1, me->round.oclock);
                cards_draw(me, tp, me->round.cardoverlay);
            }
        }

        game_fprint(me, "Player %d wins!\n\n", curPlayer->player_id + 1);
        round_nextRound(me);
        return;
    }

    game_fprint(me, "Player %d cards: ", curPlayer->player_id + 1);
    for (int i = 1; i < curPlayer->cardsinhand[0]; ++i)
    {
        char *tmp = game_getCardName(me, curPlayer->cardsinhand[i]);
        game_fprint(me, "%s, ", tmp);
        free(tmp);
    }
    char *tmp = game_getCardName(me, curPlayer->cardsinhand[curPlayer->cardsinhand[0]]);
    game_fprint(me, "%s\n", tmp);
    free(tmp);

    int clockadd = me->round.oclock;
    if (curPlayer->isOutCard)
    {
        //He puts some card(of course it's valid)
        int hiscard = me->cards.cardOnDesk;         // Top card on the desk, must be his card
        if (hiscard % 13 == 0 || hiscard % 13 == 1) //Attack
            me->round.cardoverlay += (hiscard % 13) + 2;
        me->round.turnnum++; //Only in this case add
        if (game_isSkillCard(hiscard))
        {
            //Skill card
            if (hiscard % 13 == 9)
            { //Skip
                me->round.currentPlayer = player_nextPlayer(curPlayer, 2, clockadd);
                return;
            }
            if (hiscard % 13 == 10)
            { //Reverse
                me->round.oclock = (clockadd == 1) ? -1 : 1;
                clockadd = me->round.oclock;
                me->round.currentPlayer = player_nextPlayer(curPlayer, 1, clockadd);
                return;
            }
            me->round.currentPlayer = player_nextPlayer(curPlayer, 1, clockadd);
        }
        else
        {
            //Regular Card
            me->round.currentPlayer = player_nextPlayer(curPlayer, 1, clockadd);
        }
    }
    else
    {
        //He draws a card(s)
        me->round.currentPlayer = player_nextPlayer(curPlayer, 1, clockadd); //Only need to move to the next player
    }
}

void round_nextRound(game *me)
{
    //Next round, calculate penalty
    player *plr = me->round.currentPlayer;
    player *list = plr;
    do
    {
        int pen = round_calcPenalty(list);
        list->current_penalty += pen;
        list->total_penalty += pen;
        list->cardsinhand[0] = 0;
        list->isOutCard = 0;
        list = list->next;
    } while (list != plr); //Add penalty

    game_fprint(me, "---- Stats ----\n");
    game_fprint(me, "Round %d result:\n", me->round.roundnum + 1);
    for (int i = 0; i < me->constant.playernum; ++i)
    {
        player *cur = player_getPlayer(me, i);
        game_fprint(me, "Player %d: %d, total: %d\n", cur->player_id + 1, cur->current_penalty, cur->total_penalty);
    }
    game_fprint(me, "Round %d ends\n\n", me->round.roundnum + 1);

    me->round.roundnum++;
    if (me->round.roundnum == me->constant.roundnum)
    {
        //Finish the game
        game_cls(me);
        game_print("Current round penaulty:\n");
        for (int i = 0; i < me->constant.playernum; ++i)
        {
            player *cur = player_getPlayer(me, i);
            game_print("Player %d has got %d penalty in this round, %d in total.\n", cur->player_id + 1, cur->current_penalty, cur->total_penalty);
        }
        game_print("Game Over!\nWinner(s): ");
        game_fprint(me, "Winner(s): ");
        int minp = RAND_MAX;
        int winnernum = 1;
        int *winner;
        winner = (int *)calloc(1, sizeof(int) * (unsigned long)me->constant.playernum + 1);
        for (int i = 0; i < me->constant.playernum; ++i)
        {
            player *cur = player_getPlayer(me, i);
            if (cur->total_penalty < minp)
            {
                minp = cur->total_penalty;
                winnernum = 1;
                winner[0] = i;
                continue;
            }
            if (cur->total_penalty == minp)
            {
                winner[++winnernum] = i;
            }
        }
        for (int i = 1; i <= winnernum - 1; ++i)
        {
            game_print("Player %d, ", 1 + winner[i - 1]);
            game_fprint(me, "Player %d, ", 1 + winner[i - 1]);
        }
        game_print("Player %d", 1 + winner[winnernum - 1]);
        game_fprint(me, "Player %d", 1 + winner[winnernum - 1]);
        free(winner);
        game_print("\n");
        game_fprint(me, "\n");
        game_exit(me);
    }

    me->round.oclock = (rand() % 2 == 1) ? 1 : -1;
    me->round.cardoverlay = 0;
    me->round.turnnum = 0; //Can't use round_init
    cards_reinit(me);
    game_setCards(me);
    game_cls(me);
    game_print("Current round penaulty:\n");
    for (int i = 0; i < me->constant.playernum; ++i)
    {
        player *cur = player_getPlayer(me, i);
        game_print("Player %d has got %d penalty in this round, %d in total.\n", cur->player_id + 1, cur->current_penalty, cur->total_penalty);
        cur->current_penalty = 0;
    }
    if (!me->constant.demomode)
        getchar();
}

int round_calcPenalty(player *plr)
{
    int totalCards = plr->cardsinhand[0];
    int totalPenalty = 0;
    for (int i = 1; i <= totalCards; ++i)
    {
        if (game_isSkillCard(plr->cardsinhand[i]))
        {
            totalPenalty += 20;
        }
        else
        {
            totalPenalty += (game_getCardNum(plr->cardsinhand[i]));
        }
    }
    return totalPenalty;
}
