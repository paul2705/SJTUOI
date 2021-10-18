#ifndef _USER_H_
	#define _USER_H_
	
	#include"Card.h"
	#include"Pile.h"
	#include<stdio.h>
	#include<stdlib.h>
	#include<stddef.h>

	typedef struct _User{
		Pile *HandCard;
		int Penalty;
		char PlayerName[10];
	} User;
	
	void DrawCardFromPile(char *LogFile,Pile *_formerPile,Pile *_laterPile,Pile *_alterPile,int DrawCardNumber);
	void InitializePlayer(User **_thisPlayers,int _thisPlayerNumber);
	int CanPlayerPlay(User *_thisPlayer,Card *_laterCard,int _laterOption);
	void DisplayPlayer(char *LogFile,User *_thisPlayer,int _thisOption);
	void DeletePlayer(int _thisPlayerNumber,User **_thisPlayer);

#endif
