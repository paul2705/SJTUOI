#include"Game.h"

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#include"Operation.h"
#include"User.h"
#include"Pile.h"
#include"Card.h"

void StartGame(Game *_thisGame){
	for (int i=1;i<=_thisGame->RoundNumber;i++){
		OptInitialize(_thisGame);
		int _thisPlayer=0;
		int _thisDrawCardNumber=1;
		int _thisIfInit=1;
		Card *LastTurnCard=OutputCardFromPile(_thisGame->StockPile);
		while (!IsGameEnd(_thisGame)){
			system("clear");
			DetermineDrawCardNumber(&_thisDrawCardNumber,LastTurnCard,_thisIfInit);
			DetermineNextPlayer(&_thisPlayer,_thisGame->PlayerNumber,LastTurnCard,_thisIfInit);
			printf("Player: %d\n",_thisPlayer);
			printf("You Are Supposed To Draw %d Card(s).\n",_thisDrawCardNumber);
			printf("Last Card: "); DisplayCard(LastTurnCard);
			printf("Your current HandCard: \n");
			DisplayPile(_thisGame->Player[_thisPlayer]->HandCard);
			LastTurnCard=OptPlayerPlayCard(_thisGame->Player[_thisPlayer],LastTurnCard);
			if (_thisIfInit>0) _thisIfInit=0;
			if (LastTurnCard->Rank==7) _thisDrawCardNumber=1;
			OptPlayerDrawCard(_thisGame->Player[_thisPlayer],_thisGame->StockPile,_thisDrawCardNumber);
		}
	}
}

void InitializeGame(Game *_thisGame){
	_thisGame->Player=malloc(10*sizeof(User*));
	for (int i=0;i<10;i++){
		_thisGame->Player[i]=malloc(sizeof(User));
	}
	_thisGame->StockPile=malloc(sizeof(Pile));
	InitializePile(_thisGame->StockPile);
	_thisGame->DiscardPile=malloc(sizeof(Pile));
	InitializePile(_thisGame->DiscardPile);
}

void DisplayGame(Game *_thisGame){
	printf("PlayerNumber: %d\n",_thisGame->PlayerNumber);
	printf("InitialCardNuber: %d\n",_thisGame->InitialCardNumber);
	printf("DeckNumber: %d\n",_thisGame->DeckNumber);
	printf("RoundNumber: %d\n",_thisGame->RoundNumber);
	for (int i=0;i<_thisGame->PlayerNumber;i++)
		DisplayPlayer(_thisGame->Player[i]);
	printf("StockPile: \n");
	DisplayPile(_thisGame->StockPile);
	printf("DiscardPile: \n");
	DisplayPile(_thisGame->DiscardPile);
}

int IsGameEnd(Game *_thisGame){
	for (int i=0;i<_thisGame->PlayerNumber;i++){
		if (_thisGame->Player[i]->HandCard->PileSize==0){
			printf("%s wins!\n",_thisGame->Player[i]->PlayerName);
			return 1;
		}
	}
	return 0;
}

void DetermineDrawCardNumber(int *_thisNumber,Card *_thisCard,int _thisIfInit){
	*_thisNumber=1;
	if (_thisIfInit>0){ *_thisNumber=1; return; }
	switch (_thisCard->Rank){
		case 2: *_thisNumber+=2; break;
		case 3: *_thisNumber+=3; break;
		case 7: *_thisNumber=0; break;
	}
}

void DetermineNextPlayer(int *_thisPlayer,int _thisPlayerNumber,Card *_thisCard,int _thisIfInit){
	if (_thisIfInit>0){ return; }
	switch (_thisCard->Rank){
		case 11: *_thisPlayer=(*_thisPlayer+2)%_thisPlayerNumber; break;
		case 12: *_thisPlayer=(*_thisPlayer-1+_thisPlayerNumber)%_thisPlayerNumber; break;
		default: *_thisPlayer=(*_thisPlayer+1)%_thisPlayerNumber; break;
	}
}
