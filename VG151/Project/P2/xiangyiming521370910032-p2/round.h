#ifndef ROUND_H
#define ROUND_H
#include "structure.h"

void round_init(game *me);
void round_printGeneralInfo(game *me);
void round_nextPlayer(game *me);
void round_beforeNext(game *me);
void round_endTurn(game *me);
void round_nextRound(game *me);
int round_calcPenalty(player *plr);

#endif
