#include"Operation.h"

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#include"Card.h"
#include"Pile.h"
#include"User.h"
#include"Game.h"
#include"UIScreen.h"

void OptInitialize(Game *_thisGame){
	InitializePile(_thisGame->StockPile);
	InitializePile(_thisGame->DiscardPile);

	for (int i=1;i<=_thisGame->DeckNumber;i++)
		CreatePile(_thisGame->StockPile);

	InitializePlayer(_thisGame->Player,_thisGame->PlayerNumber);
	for (int i=0;i<_thisGame->PlayerNumber;i++){
//		printf("DrawPlayer: %d\n",i);
		DrawCardFromPile(_thisGame->Player[i]->HandCard,_thisGame->StockPile,_thisGame->InitialCardNumber);
	}
}

void OptPlayerDrawCard(User *_thisPlayer,Pile *_thisPile,int _thisDrawCardNumber){
	UIPrint(500,"Draw %d Card(s).\n",_thisDrawCardNumber);
	DrawCardFromPile(_thisPlayer->HandCard,_thisPile,_thisDrawCardNumber);
}

Card *OptPlayerPlayCard(User *_thisPlayer,Card *_laterCard,Pile *_laterPile){
	UIPrint(0,"Please Play A Card Or Enter -1 To Give Up This Turn: \n");
	int _thisCardNumber;
	while (1){
		while (!scanf("%d",&_thisCardNumber));
		if (_thisCardNumber==-1) break;
		if (IsCardMatch(_thisPlayer->HandCard->thisPile[_thisCardNumber],_laterCard)) break;
		else UIPrint(0,"Your Choice Didn't Match The Rank Or Suit Of The Last Card! Please Choose again!\n");
	}
	Card *_formerCard=_laterCard;
	if (_thisCardNumber==-1) return _formerCard;
	_formerCard=_thisPlayer->HandCard->thisPile[_thisCardNumber];
	InsertCardToPile(_laterPile,_formerCard);
	WithdrawCardFromPile(_thisPlayer->HandCard,_thisCardNumber);
	return _formerCard;
}

void OptReFillStockPile(Game *_thisGame){
	Pile *tmp=_thisGame->StockPile;
	_thisGame->StockPile=_thisGame->DiscardPile;
	_thisGame->DiscardPile=tmp;
}
