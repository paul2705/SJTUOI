#ifndef _OPERATION_H_
	#define _OPERATION_H_

	#include"Card.h"
	#include"Pile.h"
	#include"User.h"
	#include"Game.h"
	#include<stdio.h>
	#include<stdlib.h>
	#include<stddef.h>

	void OptInitialize(Game *_thisGame);
	void OptPlayerDrawCard(char *LogFile,User *_thisPlayer,Pile *_formerPile,Pile *_laterPile,int _thisDrawCardNumber);
	Card *OptPlayerPlayCard(char *LogFile,User *_thisPlayer,Card *_laterCard,Pile *_laterPile,int _laterOption,int _thisAuto);
	void OptShiftPile(Pile *_formerPile,Pile *_laterPile);

#endif
