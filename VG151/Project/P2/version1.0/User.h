#ifndef _USER_H_
	#define _USER_H_
	
	#include"Card.h"
	#include"Pile.h"

	typedef struct _User{
		Pile HeadCard;
		char UserName[10];
	} User;

	void DrawCardFromPile(Pile *_formerPile,Pile *_laterPile,int DrawCardNumber);
	void InitializePlayer(User **_thisPlayer,int _thisPlayerNumber);
#endif
