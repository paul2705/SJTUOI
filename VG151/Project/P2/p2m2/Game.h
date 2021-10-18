#ifndef _GAME_H_
	#define _GAME_H_

	#include"Card.h"
	#include"Pile.h"
	#include"User.h"
	#include<stdio.h>
	#include<stdlib.h>
	#include<stddef.h>

	typedef struct _Game{
		int PlayerNumber,InitialCardNumber,DeckNumber,RoundNumber;
		int Debug;
		char LogFile[20];
		User **Player;
		Pile *StockPile,*DiscardPile;
	} Game;
	
	void StartGame(Game *_thisGame);
	void InitializeGame(Game *_thisGame);
	void DisplayGame(char *LogFile,Game *_thisGame,int _thisOption);
	int IsGameEnd(char *LogFile,Game *_thisGame,int *_laterWinner);
	void DetermineDrawCardNumber(int *_thisNumber,Card *_thisCard,int _thisIfInit,int _thisCardLatest);
	void DetermineNextPlayer(int *_thisPlayer,int _thisPlayerNumber,int *_thisPlayOrder,Card *_thisCard,int _thisIfInit,int _thisCardLatest);
	void DeleteGame(Game* _thisGame);

#endif
