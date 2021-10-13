#ifndef _USER_H_
	#define _USER_H_
	
	#include"Card.h"
	#include"Pile.h"

	typedef struct _User{
		Pile *HandCard;
		char PlayerName[10];
	} User;
	
	void DrawCardFromPile(Pile *_formerPile,Pile *_laterPile,Pile *_alterPile,int DrawCardNumber);
	void InitializePlayer(User **_thisPlayers,int _thisPlayerNumber);
	void DisplayPlayer(User *_thisPlayer);
	void DeletePlayer(int _thisPlayerNumber,User **_thisPlayer);

#endif
