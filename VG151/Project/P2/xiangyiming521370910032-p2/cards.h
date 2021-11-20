#ifndef CARDS_H
#define CARDS_H
#include "structure.h"

void cards_init(game *me);
void cards_reinit(game *me);
void cards_joinDesk(game *me, int cardid);
void cards_quitDesk(game *me);
void cards_reset(game *me);
int cards_draw(game *me, player *plr, int n);
void cards_insertCard(player *plr, int cardid);
void cards_shuffle(game *me, int *arr, int size);
void cards_deleteCard(player *plr, int cardABSid);
void cards_startTurn(game *me);
int cards_currentCard(game *me);
int cards_getCard(game *me);

#endif
