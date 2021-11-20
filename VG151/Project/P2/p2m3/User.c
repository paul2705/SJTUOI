#include"User.h"

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#include"Operation.h"
#include"Card.h"
#include"Pile.h"
#include"UIScreen.h"

void DrawCardFromPile(char *LogFile,Pile *_formerPile,Pile *_laterPile,Pile *_alterPile,int DrawCardNumber){
	for (int i=1;i<=DrawCardNumber;i++){
		if (_laterPile->PileSize+_alterPile->PileSize==0){
			UIPrint(500,"Hey! You Are Lucky! StockPile and DiscardPile Are All Empty!\n");
			FPrint(LogFile,"Hey! You Are Lucky! StockPile and DiscardPile Are All Empty!\n");
			break;
		}
		if (_laterPile->PileSize==0){
			UIPrint(200,"StockPile Is Empty! \n");
			FPrint(LogFile,"StockPile Is Empty! \n");
			UIPrint(500,"Refresh The StockPile....");
			FPrint(LogFile,"Refresh The StockPile....");
			OptShiftPile(_laterPile,_alterPile);
			UIPrint(200,"Success!\n");
			FPrint(LogFile,"Success!\n");
		}
		Card *_thisCard=OutputCardFromPile(_laterPile);
		InsertCardToPile(_formerPile,_thisCard);
//		DisplayPile(_formerPile);
//		UIPrint(200,"Draw Card No:%d, ",i); 
		FPrint(LogFile,"Draw Card No:%d, ",i); DisplayCard(LogFile,_thisCard,0);
	}
	FPrint(LogFile,"\n");
}

void InitializePlayer(User **_thisPlayers,int _thisPlayerNumber){
	for (int i=0;i<_thisPlayerNumber;i++){
		_thisPlayers[i]->HandCard=(Pile*)malloc(sizeof(Pile));
		InitializePile(_thisPlayers[i]->HandCard);
		_thisPlayers[i]->PlayerNumber=i;
		_thisPlayers[i]->Nex[1]=_thisPlayers[(i+1)%_thisPlayerNumber];
		_thisPlayers[i]->Nex[0]=_thisPlayers[(i-1+_thisPlayerNumber)%_thisPlayerNumber];
	}
}

int CanPlayerPlay(User *_thisPlayer,Card *_laterCard,int _thisOption){
	int _tmpCanCardCount=-1;
	for (int i=0;i<_thisPlayer->HandCard->PileSize;i++){
		Card *_formerCard=_thisPlayer->HandCard->thisPile[i];
		if (IsCardMatch(_formerCard,_laterCard,_thisOption)) _tmpCanCardCount=i;
	}
	return _tmpCanCardCount;
}

void DisplayPlayer(char *LogFile,User *_thisPlayer,int _thisOption){
	if (_thisOption) UIPrint(0,"Player: %d\n",_thisPlayer->PlayerNumber);
	FPrint(LogFile,"Player: %d: \n",_thisPlayer->PlayerNumber);
	DisplayPile(LogFile,_thisPlayer->HandCard,_thisOption);
	if (_thisOption) UIPrint(0,"\n");
	FPrint(LogFile,"\n");
}

void DeletePlayer(char *LogFile,int _thisPlayerNumber,User **_thisPlayer){
	FPrint(LogFile,"Delete Players (AllPlayerNumber:%d) ...\n",_thisPlayerNumber);
	for (int i=0;i<_thisPlayerNumber;i++){
		FPrint(LogFile,"Delete Player: %d ...\n",i);
		DeletePile(LogFile,_thisPlayer[i]->HandCard);
		free(_thisPlayer[i]);
		FPrint(LogFile,"Delete Player: %d Success!\n",i);
	}
}
