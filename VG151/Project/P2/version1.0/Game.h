#ifndef _GAME_H_
	#define _GAME_H_

	#include"Card.h"
	#include"Pile.h"
	#include"User.h"

	typedef struct _Game{
		int PlayerNumber,InitialCardNumber,DeckNumber,RoundNumber;
		User **Player;
		Pile *StockPile,*DiscardPile;
	} Game;
	
	void StartGame(Game *_thisGame);
	void InitializeGame(Game *_thisGame);
#endif
