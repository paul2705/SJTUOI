#ifndef PLAYER_H
#define PLAYER_H
#include "structure.h"

void player_init(game *me);
player *player_nextPlayer(player *plr, int nextnum, int oclock);
int player_judgevalid(int input, int output);
int player_judgevalid_F(game *me, int input, int output);
int player_printPossible(game *me);
int player_random(game *me);
player *player_prevPlayer(game *me);
void player_pushCard(game *me, player *plr, int cardid);
player *player_getPlayer(game *me, int num);

#endif
