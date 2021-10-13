#ifndef _GAME_H_
	#define _GAME_H_

	#include"Card.h"
	#include"Pile.h"
	#include"User.h"

	typedef struct _Game{
		int PlayerNumber,InitialCardNumber,DeckNumber,RoundNumber;
		int Debug;
		User **Player;
		Pile *StockPile,*DiscardPile;
	} Game;
	
	void StartGame(Game *_thisGame);
	void InitializeGame(Game *_thisGame);
	void DisplayGame(Game *_thisGame);
	int IsGameEnd(Game *_thisGame);
	void DetermineDrawCardNumber(int *_thisNumber,Card *_thisCard,int _thisIfInit,int _thisCardLatest);
	void DetermineNextPlayer(int *_thisPlayer,int _thisPlayerNumber,int *_thisPlayOrder,Card *_thisCard,int _thisIfInit,int _thisCardLatest);
	void DeleteGame(Game* _thisGame);

#endif
