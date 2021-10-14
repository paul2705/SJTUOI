#include"User.h"

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#include"Operation.h"
#include"Card.h"
#include"Pile.h"
#include"UIScreen.h"

void DrawCardFromPile(Pile *_formerPile,Pile *_laterPile,Pile *_alterPile,int DrawCardNumber){
	for (int i=1;i<=DrawCardNumber;i++){
		if (_laterPile->PileSize+_formerPile->PileSize==0){
			UIPrint(500,"Hey! You Are Lucky! StockPile and DiscardPile Are All Empty!\n");
			break;
		}
		if (_laterPile->PileSize==0){
			UIPrint(200,"StockPile Is Empty! \n");
			UIPrint(500,"Refresh The StockPile....");
			OptShiftPile(_laterPile,_alterPile);
			UIPrint(200,"Success!\n");
		}
		Card *_thisCard=OutputCardFromPile(_laterPile);
		InsertCardToPile(_formerPile,_thisCard);
//		DisplayPile(_formerPile);
		UIPrint(200,"Draw Card No:%d, ",i); DisplayCard(_thisCard);
	}
}

void InitializePlayer(User **_thisPlayers,int _thisPlayerNumber){
	for (int i=0;i<_thisPlayerNumber;i++){
//		printf("Player: %d\n",i);
		_thisPlayers[i]->HandCard=(Pile*)malloc(sizeof(Pile));
		InitializePile(_thisPlayers[i]->HandCard);
		_thisPlayers[i]->Penalty=0;
	}
}

int CanPlayerPlay(User *_thisPlayer,Card *_laterCard,int _thisOption){
	int _tmpCanCardCount=0;
	for (int i=0;i<_thisPlayer->HandCard->PileSize;i++){
		Card *_formerCard=_thisPlayer->HandCard->thisPile[i];
		_tmpCanCardCount+=IsCardMatch(_formerCard,_laterCard,_thisOption);
	}
	return _tmpCanCardCount>0;
}

void DisplayPlayer(User *_thisPlayer){
	UIPrint(0,"Player: %s\n",_thisPlayer->PlayerName);
	DisplayPile(_thisPlayer->HandCard);
	UIPrint(0,"\n");
}

void DeletePlayer(int _thisPlayerNumber,User **_thisPlayer){
	for (int i=0;i<_thisPlayerNumber;i++){
		DeletePile(_thisPlayer[i]->HandCard);
		free(_thisPlayer[i]);
	}
}
