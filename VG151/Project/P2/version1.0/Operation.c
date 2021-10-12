#include"Operation.h"

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#include"Card.h"
#include"Pile.h"
#include"Game.h"

void OptInitialize(Game *_thisGame){
	printf("0001\n");
	InitializePile(_thisGame->StockPile);
	printf("0011\n");
//	printf("%d\n",(int)sizeof(malloc(55*sizeof(Card))));
	printf("%d\n",(int)sizeof(_thisGame->StockPile)/(int)sizeof(Card));
	printf("0010\n");
	CreatePile(_thisGame->StockPile);
	printf("0002\n");
	InitializePlayer(_thisGame->Player,_thisGame->PlayerNumber);
	printf("0003\n");
	for (int i=0;i<_thisGame->PlayerNumber;i++){
		DrawCardFromPile(&_thisGame->Player[i]->HeadCard,_thisGame->StockPile,_thisGame->InitialCardNumber);
	}
	printf("0004\n");
	EmptyPile(_thisGame->DiscardPile);
}

