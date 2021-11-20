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
		int Debug,Auto;
		int Penalty[20];
		char LogFile[20];
		User **Player;
		Pile *StockPile,*DiscardPile;
	} Game;
	
	void StartGame(Game *_thisGame);
	void InitializeGame(Game *_thisGame);
	void DisplayGame(char *LogFile,Game *_thisGame,int _thisOption);
	int IsGameEnd(char *LogFile,Game *_thisGame,User **_laterWinner);
	void DetermineDrawCardNumber(int *_thisNumber,Card *_thisCard,int _thisIfInit,int _thisCardLatest);
	void DetermineNextPlayer(User **_thisPlayer,int _thisPlayerNumber,int *_thisPlayOrder,Card *_thisCard,int _thisIfInit,int _thisCardLatest);
	void ShiftPlayer(User **_thisPlayer,int _thisNumber);
	void DeleteGame(Game* _thisGame);

#endif
