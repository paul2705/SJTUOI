#include"Game.h"

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#include"Operation.h"
#include"Pile.h"
#include"Card.h"

void StartGame(Game *_thisGame){
	OptInitialize(_thisGame);
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
