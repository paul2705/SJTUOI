#include "game.h"
#include "cards.h"
#include "player.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

char *game_getCardName(game *me, int id)
{
    int d = (id) % 13;
    int s = (id) / 13;
    char *mix = game_str_join(me->constant.suit[s], me->constant.mcards[d]);
    return mix;
}

int game_getCardNum(int i)
{
    //Transform
    int p = i % 13 + 2;
    if (p == 14)
        p = 1;
    return p;
}

char *game_str_join(char *s1, char *s2)
{
    char *s, *t;
    t = s = (char *)malloc(strlen(s1) + strlen(s2) + 2);
    while (*s1 != '\0')
        *s++ = *s1++;
    *s++ = ' ';
    while (*s2 != '\0')
        *s++ = *s2++;
    *s = '\0';
    return t;
}

int game_isSkillCard(int input)
{
    if (input % 13 == 0 || input % 13 == 1 || input % 13 == 5 || input % 13 == 9 || input % 13 == 10)
        return 1;
    return 0;
}

void game_print(char *fmt, ...)
{
    char *str;
    int i;
    va_list arg;
    va_start(arg, fmt);
    for (str = fmt; *str != '\0'; str++)
    {
        while (*str != '%')
        {
            if (*str == '\0')
            { //If end
                va_end(arg);
                return;
            }
            putchar(*str); //Print this char
            str++;
        }
        str++;
        switch (*str)
        {         //Different types
        case 'd': //Integer
            i = va_arg(arg, int);
            printf("%d", i);
            break;

        case 's': //String
            printf("%s", va_arg(arg, char *));
            break;
        }
    }
    va_end(arg);
}

void game_init(game *me)
{
    me->constant.suit[0] = (char *)"Spades";
    me->constant.suit[1] = (char *)"Hearts";
    me->constant.suit[2] = (char *)"Diamonds";
    me->constant.suit[3] = (char *)"Clubs";
    me->constant.mcards[0] = (char *)"2";
    me->constant.mcards[1] = (char *)"3";
    me->constant.mcards[2] = (char *)"4";
    me->constant.mcards[3] = (char *)"5";
    me->constant.mcards[4] = (char *)"6";
    me->constant.mcards[5] = (char *)"7";
    me->constant.mcards[6] = (char *)"8";
    me->constant.mcards[7] = (char *)"9";
    me->constant.mcards[8] = (char *)"10";
    me->constant.mcards[9] = (char *)"Jack";
    me->constant.mcards[10] = (char *)"Queen";
    me->constant.mcards[11] = (char *)"King";
    me->constant.mcards[12] = (char *)"Ace";

    //Other constant(default)
    me->constant.playernum = 4;
    me->constant.decknum = 2;
    me->constant.cardperplayer = 5;
    me->constant.roundnum = 1;
    strcpy(me->constant.logname, "onecard.log");
    me->constant.demomode = 0;
}

void game_setCards(game *me)
{
    //Initialize cards
    int j = 1;
    for (int i = 1; i <= me->constant.decknum; ++i)
    {
        //Every deck
        for (int k = 0; k <= 51; ++k)
        {
            me->cards.cardsRemain[j] = k;
            j++;
        }
    }
    me->cards.cardsRemain[0] = j - 1;
    cards_shuffle(me, me->cards.cardsRemain, j - 1);
    cards_startTurn(me);
    player *cplr = me->round.currentPlayer;
    player *ilist = cplr;
    do
    {
        cards_draw(me, ilist, me->constant.cardperplayer);
        ilist = ilist->next;
    } while (ilist != cplr);

    game_fprint(me, "Dealing cards...\n");
    if (me->constant.demomode)
        game_print("Dealing cards...\n");
    for (int i = 0; i < me->constant.playernum; ++i)
    {
        game_fprint(me, "Player %d: ", i + 1);
        if (me->constant.demomode)
            game_print("Player %d: ", i + 1);
        player *cur = player_getPlayer(me, i);
        for (int j = 1; j < cur->cardsinhand[0]; ++j)
        {
            char *tmp = game_getCardName(me, cur->cardsinhand[j]);
            game_fprint(me, "%s, ", tmp);
            if (me->constant.demomode)
                game_print("%s, ", tmp);
            free(tmp);
        }
        char *tmp = game_getCardName(me, cur->cardsinhand[cur->cardsinhand[0]]);
        game_fprint(me, "%s\n", tmp);
        if (me->constant.demomode)
            game_print("%s\n", tmp);
        free(tmp);
    }
    game_fprint(me, "\n");
}

void game_fprint(game *me, char *fmt, ...)
{
    char *str;
    int i;
    va_list arg;
    va_start(arg, fmt);
    FILE *fp = NULL;
    fp = fopen(me->constant.logname, "a");
    for (str = fmt; *str != '\0'; str++)
    {
        while (*str != '%')
        {
            if (*str == '\0')
            { //If end
                va_end(arg);
                fclose(fp);
                return;
            }
            fprintf(fp, "%c", *str);
            str++;
        }
        str++;
        switch (*str)
        {         //Different types
        case 'd': //Integer
            i = va_arg(arg, int);
            fprintf(fp, "%d", i);
            break;

        case 's': //String
            fprintf(fp, "%s", va_arg(arg, char *));
            break;
        }
    }
    va_end(arg);
    fclose(fp);
}

void game_layoutinit(game *me)
{
    remove(me->constant.logname);
    game_fprint(me, "########################\n#\n#\n# Welcome to One Card! #\n#\n#\n########################\n\n");
    game_fprint(me, "---- Initial setup ----\n");
    game_fprint(me, "Number of rounds: %d\n", me->constant.roundnum);
    game_fprint(me, "Number of decks: %d\n", me->constant.decknum);
    game_fprint(me, "Number of players: %d\n\n", me->constant.playernum);
}

void game_cls(game *me)
{
    if (me->constant.demomode)
    {
        game_print("\n");
        return;
    }
    if (system("cls||clear"))
        return;
}

void game_para(int argc, char *argv[], game *me)
{
    if (argc == 1)
        return;
    for (int i = 1; i <= argc - 1; ++i)
    {
        if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help"))
        {
            game_print("-h|--help print this help message\n--log filename write the logs in filename (default: onecard.log)\n-n n|--player-number=n n players, n must be larger than 2 (default: 4)\n-c c|--initial-cards=c deal c cards per player, c must be at least 2 (default: 5)\n-d d|--decks=d use d decks 52 cards each, d must be at least 2 (default: 2)\n-r r|--rounds=r play r rounds, r must be at least 1 (default: 1)\n-a|--auto run in demo mode\n");
            free(me); //Help end
            exit(0);
        }
        if (!strcmp(argv[i], "-c"))
        {
            int n = atoi(argv[i + 1]);
            if (n < 2)
            {
                game_print("Initial cards must be at least 2!\n");
                free(me);
                exit(0);
            }
            me->constant.cardperplayer = n;
            i++;
            continue;
        }
        if (!strcmp(argv[i], "-n"))
        {
            int n = atoi(argv[i + 1]);
            if (n <= 2)
            {
                game_print("Player number must be larger than 2!\n");
                free(me);
                exit(0);
            }
            me->constant.playernum = n;
            i++;
            continue;
        }
        if (!strcmp(argv[i], "-d"))
        {
            int n = atoi(argv[i + 1]);
            if (n < 2)
            {
                game_print("Deck number must be at least 2!\n");
                free(me);
                exit(0);
            }
            me->constant.decknum = n;
            i++;
            continue;
        }
        if (!strcmp(argv[i], "-r"))
        {
            int n = atoi(argv[i + 1]);
            if (n < 1)
            {
                game_print("Round number must be at least 1!\n");
                free(me);
                exit(0);
            }
            me->constant.roundnum = n;
            i++;
            continue;
        }
        if (!strcmp(argv[i], "--log"))
        {
            strcpy(me->constant.logname, argv[i + 1]);
            i++;
            continue;
        }
        if ((!strcmp(argv[i], "-a")) || (!strcmp(argv[i], "--auto")))
        {
            me->constant.demomode = 1;
            continue;
        }
        char ctemp[20] = {0};
        strncpy(ctemp, argv[i], 16);
        if (!strcmp(ctemp, "--player-number="))
        {
            char *p = argv[i] + 16;
            int n = atoi(p);
            if (n <= 2)
            {
                game_print("Player number must be larger than 2!\n");
                free(me);
                exit(0);
            }
            me->constant.playernum = n;
            continue;
        }
        if (!strcmp(ctemp, "--initial-cards="))
        {
            char *p = argv[i] + 16;
            int n = atoi(p);
            if (n < 2)
            {
                game_print("Initial cards must be at least 2!\n");
                free(me);
                exit(0);
            }
            me->constant.cardperplayer = n;
            continue;
        }
        memset(ctemp, '\0', sizeof(ctemp));
        strncpy(ctemp, argv[i], 8);
        if (!strcmp(ctemp, "--decks="))
        {
            char *p = argv[i] + 8;
            int n = atoi(p);
            if (n < 2)
            {
                game_print("Deck number must be at least 2!\n");
                free(me);
                exit(0);
            }
            me->constant.decknum = n;
            continue;
        }
        memset(ctemp, '\0', sizeof(ctemp));
        strncpy(ctemp, argv[i], 9);
        if (!strcmp(ctemp, "--rounds="))
        {
            char *p = argv[i] + 9;
            int n = atoi(p);
            if (n < 1)
            {
                game_print("Round number must be at least 1!\n");
                free(me);
                exit(0);
            }
            me->constant.roundnum = n;
            continue;
        }
        printf("Invalid parameter!\n");
        exit(0);
    }
}

void game_exit(game *me)
{
    free(me->cards.cardsQuit);
    free(me->cards.cardsRemain);
    player *cpl = me->round.currentPlayer;
    do
    {
        free(cpl->cardsinhand);
        player *npl = cpl->next;
        free(cpl);
        cpl = npl;
    } while (cpl != me->round.currentPlayer);
    free(me);
    exit(0);
}
