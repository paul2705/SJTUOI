#include"Operation.h"

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#include"Card.h"
#include"Pile.h"
#include"Game.h"

void OptInitialize(Game *_thisGame){
	InitializePile(_thisGame->StockPile);
	InitializePile(_thisGame->DiscardPile);
	CreatePile(_thisGame->StockPile);
	InitializePlayer(_thisGame->Player,_thisGame->PlayerNumber);
	for (int i=0;i<_thisGame->PlayerNumber;i++){
//		printf("DrawPlayer: %d\n",i);
		DrawCardFromPile(_thisGame->Player[i]->HandCard,_thisGame->StockPile,_thisGame->InitialCardNumber);
	}
}

