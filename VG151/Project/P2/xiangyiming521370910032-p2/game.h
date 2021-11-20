#ifndef GAME_H
#define GAME_H
#include "structure.h"

char *game_getCardName(game *me, int id);
char *game_str_join(char *s1, char *s2);
void game_init(game *me);
int game_isSkillCard(int input);
void game_print(char *format, ...);
void game_cls(game *me);
void game_setCards(game *me);
void game_layoutinit(game *me);
void game_para(int argc, char *argv[], game *me);
int game_getCardNum(int i);
void game_exit(game *me);
void game_fprint(game *me,char *fmt, ...);

#endif
