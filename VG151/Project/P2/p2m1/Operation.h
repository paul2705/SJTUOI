#ifndef _OPERATION_H_
	#define _OPERATION_H_

	#include"Card.h"
	#include"Pile.h"
	#include"User.h"
	#include"Game.h"

	void OptInitialize(Game *_thisGame);
	void OptPlayerDrawCard(User *_thisPlayer,Pile *_thisPile,int DrawCardNumber);
	Card *OptPlayerPlayCard(User *_thisPlayer,Card *_laterCard,Pile *_laterPile);
	void OptReFillStockPile(Game *_thisGame);

#endif
