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
		UIPrint(0,"DrawPlayer: %d\n",i);
		FPrint(_thisGame->LogFile,"DrawPlayer: %d; ",i);
		DrawCardFromPile(_thisGame->LogFile,_thisGame->Player[i]->HandCard,_thisGame->StockPile,_thisGame->DiscardPile,_thisGame->InitialCardNumber);
	}
}

void OptPlayerDrawCard(char *LogFile,User *_thisPlayer,Pile *_formerPile,Pile *_laterPile,int _thisDrawCardNumber){
	UIPrint(500,"Draw %d Card(s).\n",_thisDrawCardNumber);
	FPrint(LogFile,"Draw %d Card(s).\n",_thisDrawCardNumber);
	DrawCardFromPile(LogFile,_thisPlayer->HandCard,_formerPile,_laterPile,_thisDrawCardNumber);
}

Card *OptPlayerPlayCard(char *LogFile,User *_thisPlayer,Card *_laterCard,Pile *_laterPile,int _laterOption,int _thisAuto){
	int _thisCardNumber=CanPlayerPlay(_thisPlayer,_laterCard,_laterOption);
	Card *_formerCard=_laterCard;
	if (_thisCardNumber==-1){
		UIPrint(0,"Oops! You Can't Play Any Card! Enter Any Number To Acknowledge Such Situation And Draw Card(s):\n");
		FPrint(LogFile,"Oops! He/She Can't Play Any Card! Enter Any Number To Acknowledge Such Situation And Draw Card(s):\n");
		if (_thisAuto){
			UIPrint(1000,"UI Automatically Passes.\n");
			FPrint(LogFile,"UI Automatically Passes.\n");
			return _laterCard;
		}
		while (!scanf("%d",&_thisCardNumber));
		FPrint(LogFile,"He/She Enters This Number: %d\n",_thisCardNumber);
		return _laterCard;
	}
	if (_thisAuto){
		_formerCard=_thisPlayer->HandCard->thisPile[_thisCardNumber];
		UIPrint(1000,"UI Plays this Card: %d\n",_thisCardNumber);
		FPrint(LogFile,"UI Plays this Card: "); DisplayCard(LogFile,_formerCard,0); FPrint(LogFile,"\n\n");
		InsertCardToPile(_laterPile,_formerCard);
		WithdrawCardFromPile(_thisPlayer->HandCard,_thisCardNumber);
		return _formerCard;
	}
	UIPrint(0,"Please Play A Card Or Enter -1 To Give Up This Turn And Draw One More Card: \n");
	FPrint(LogFile,"He/She Should Play A Card Or Enter -1 To Give Up This Turn And Draw One More Card: \n");
	while (1){
		while (!scanf("%d",&_thisCardNumber));
		if (_thisCardNumber==-1) break;
		if (IsCardMatch(_thisPlayer->HandCard->thisPile[_thisCardNumber],_laterCard,_laterOption)) break;
		else{
			UIPrint(0,"Your Choice Didn't Match The Rank Or Suit Of The Last Card! Please Choose again!\n");
			FPrint(LogFile,"He/She Chooces This Card: "); 
			DisplayCard(LogFile,_thisPlayer->HandCard->thisPile[_thisCardNumber],0); 
			FPrint(LogFile,"; His/Her Choice Didn't Match The Rank Or Suit Of The Last Card!\n");
		}
	}
	if (_thisCardNumber==-1) return _formerCard;
	_formerCard=_thisPlayer->HandCard->thisPile[_thisCardNumber];
	FPrint(LogFile,"He/She Plays this Card: "); DisplayCard(LogFile,_formerCard,0); FPrint(LogFile,"\n\n");
	InsertCardToPile(_laterPile,_formerCard);
	WithdrawCardFromPile(_thisPlayer->HandCard,_thisCardNumber);
	return _formerCard;
}

void OptShiftPile(Pile *_formerPile,Pile *_laterPile){
	Card **tmp=_formerPile->thisPile;
	_formerPile->thisPile=_laterPile->thisPile;
	_laterPile->thisPile=tmp;
	int tmpNumber=_formerPile->PileSize;
	_formerPile->PileSize=_laterPile->PileSize;
	_laterPile->PileSize=tmpNumber;
}
