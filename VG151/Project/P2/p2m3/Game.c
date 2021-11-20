#include"Game.h"

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#include"Sys.h"
#include"UIScreen.h"
#include"Operation.h"
#include"User.h"
#include"Pile.h"
#include"Card.h"

void StartGame(Game *_thisGame){
	User *_laterWinner=NULL;
	for (int i=1;i<=_thisGame->RoundNumber;i++){
		OptInitialize(_thisGame);
		
		User *_thisPlayer;
		if (i==1) _thisPlayer=_thisGame->Player[rand()%_thisGame->PlayerNumber];
		else _thisPlayer=_laterWinner;
		int _thisDrawCardNumber=0;
		int _thisIfInit=1;
		int _thisPlayOrder=1;

		Card *LastTurnCard=OutputCardFromPile(_thisGame->StockPile);
		InsertCardToPile(_thisGame->DiscardPile,LastTurnCard);
		int _thisCardLatest=0;

		while (!IsGameEnd(_thisGame->LogFile,_thisGame,&_laterWinner)){
			ClearScreen();

			if (_thisGame->Debug) DisplayGame(_thisGame->LogFile,_thisGame,_thisGame->Debug);
			UIPrint(100,"Round: %d , StockPile: %d , DiscardPile: %d\n",i,_thisGame->StockPile->PileSize,_thisGame->DiscardPile->PileSize);
			FPrint(_thisGame->LogFile,"\n\n------------------------\nRound: %d , StockPile: %d , DiscardPile: %d\n",i,_thisGame->StockPile->PileSize,_thisGame->DiscardPile->PileSize);
			

			FPrint(_thisGame->LogFile,"Determine Draw Card Number ...\n\n");
			DetermineDrawCardNumber(&_thisDrawCardNumber,LastTurnCard,_thisIfInit,_thisCardLatest);

			FPrint(_thisGame->LogFile,"Determine Next Player ...\n\n");
			DetermineNextPlayer(&_thisPlayer,_thisGame->PlayerNumber,&_thisPlayOrder,LastTurnCard,_thisIfInit,_thisCardLatest);
			
			UIPrint(50,"Player: %d\n",_thisPlayer->PlayerNumber);
			FPrint(_thisGame->LogFile,"Player: %d; ",_thisPlayer->PlayerNumber);
			UIPrint(50,"You Are Supposed To Draw %d Card(s).\n",_thisDrawCardNumber);
			FPrint(_thisGame->LogFile,"He/She is Supposed To Draw %d Card(s).\n",_thisDrawCardNumber);
			UIPrint(50,"Last Card: "); 
			FPrint(_thisGame->LogFile,"Last Card: "); DisplayCard(_thisGame->LogFile,LastTurnCard,1);
			UIPrint(500,"\n\n"); FPrint(_thisGame->LogFile,"\n");

			UIPrint(50,"Your Current HandCard: \n"); FPrint(_thisGame->LogFile,"His/Her Current HandCard: ");
			DisplayPile(_thisGame->LogFile,_thisPlayer->HandCard,1);
			Card* _tmpCard=LastTurnCard;
			LastTurnCard=OptPlayerPlayCard(_thisGame->LogFile,_thisPlayer,LastTurnCard,_thisGame->DiscardPile,!_thisCardLatest,_thisGame->Auto);					

			if (_thisIfInit>0) _thisIfInit=0;
			
			_thisCardLatest=(LastTurnCard!=_tmpCard);
			if (!_thisCardLatest&&_thisDrawCardNumber==0) _thisDrawCardNumber++;
			if ((_thisCardLatest)&&(LastTurnCard->Rank==7||LastTurnCard->Rank==2||LastTurnCard->Rank==3||LastTurnCard->Rank==11||LastTurnCard->Rank==12))
				OptPlayerDrawCard(_thisGame->LogFile,_thisPlayer,_thisGame->StockPile,_thisGame->DiscardPile,0);
			else OptPlayerDrawCard(_thisGame->LogFile,_thisPlayer,_thisGame->StockPile,_thisGame->DiscardPile,_thisDrawCardNumber);

			if (_thisGame->StockPile->PileSize==0){ 
				UIPrint(200,"StockPile Is Empty! \n"); FPrint(_thisGame->LogFile,"StockPile Is Empty! \n");
				UIPrint(500,"Refresh The StockPile...."); FPrint(_thisGame->LogFile,"Refresh The StockPile....");
				OptShiftPile(_thisGame->StockPile,_thisGame->DiscardPile);
				UIPrint(200,"Success!\n"); FPrint(_thisGame->LogFile,"Success!\n");
			}

		}
	}
	DisplayGame(_thisGame->LogFile,_thisGame,1);
}

void InitializeGame(Game *_thisGame){
	FPrint(_thisGame->LogFile,"Initialize Game ...\n\n");
	FPrint(_thisGame->LogFile,"---- Initial setup ----\n");
	FPrint(_thisGame->LogFile,"Number of rounds: %d\n",_thisGame->RoundNumber);
	FPrint(_thisGame->LogFile,"Number of decks: %d\n",_thisGame->DeckNumber);
	FPrint(_thisGame->LogFile,"Number of players: %d\n\n",_thisGame->PlayerNumber);

	_thisGame->Player=malloc((unsigned long)_thisGame->PlayerNumber*sizeof(User*));
	for (int i=0;i<_thisGame->PlayerNumber;i++){
		_thisGame->Penalty[i]=0;
		_thisGame->Player[i]=malloc(sizeof(User));
	}

	_thisGame->StockPile=malloc(sizeof(Pile));
	InitializePile(_thisGame->StockPile);
	
	_thisGame->DiscardPile=malloc(sizeof(Pile));
	InitializePile(_thisGame->DiscardPile);
}

void DisplayGame(char *LogFile,Game *_thisGame,int _thisOption){
	FPrint(_thisGame->LogFile,"---- Display Game ----\n\n");
	UIPrint(0,"---- Display Game ----\n\n");
	if (_thisOption) UIPrint(0,"PlayerNumber: %d\n",_thisGame->PlayerNumber);
	FPrint(LogFile,"PlayerNumber: %d\n",_thisGame->PlayerNumber);
	if (_thisOption) UIPrint(0,"InitialCardNuber: %d\n",_thisGame->InitialCardNumber);
	FPrint(LogFile,"InitialCardNuber: %d\n",_thisGame->InitialCardNumber);
	if (_thisOption) UIPrint(0,"DeckNumber: %d\n",_thisGame->DeckNumber);
	FPrint(LogFile,"DeckNumber: %d\n",_thisGame->DeckNumber);
	if (_thisOption) UIPrint(0,"RoundNumber: %d\n",_thisGame->RoundNumber);
	FPrint(LogFile,"RoundNumber: %d\n",_thisGame->RoundNumber);
	
	for (int i=0;i<_thisGame->PlayerNumber;i++){
		if (_thisOption) UIPrint(0,"Player %d Penalty: %d\n",i,_thisGame->Penalty[i]);
		FPrint(LogFile,"Player %d Penalty: %d\n",i,_thisGame->Penalty[i]);
		DisplayPlayer(LogFile,_thisGame->Player[i],_thisOption);
	}
	
	if (_thisOption) UIPrint(0,"StockPile: \n");
	FPrint(LogFile,"StockPile: ");
	DisplayPile(LogFile,_thisGame->StockPile,_thisOption);
	
	if (_thisOption) UIPrint(0,"DiscardPile: \n");
	FPrint(LogFile,"DiscardPile: ");
	DisplayPile(LogFile,_thisGame->DiscardPile,_thisOption);
}

int IsGameEnd(char *LogFile,Game *_thisGame,User **_laterWinner){
	for (int i=0;i<_thisGame->PlayerNumber;i++){
		if (_thisGame->Player[i]->HandCard->PileSize==0){
			UIPrint(500,"Player:%d wins!\n",i);
			FPrint(LogFile,"Player:%d wins!\n",i);
			*_laterWinner=_thisGame->Player[i];
			for (int j=0;j<_thisGame->PlayerNumber;j++){
				for (int k=0;k<_thisGame->Player[j]->HandCard->PileSize;k++){
					Card *_thisCard=_thisGame->Player[j]->HandCard->thisPile[k];
					_thisGame->Penalty[j]+=
						((_thisCard->Rank==2||_thisCard->Rank==3)? 5:
						(_thisCard->Rank==11||_thisCard->Rank==12)?3:1)
						*-1;
				}
			}
			return 1;
		}
	}
	return 0;
}

void DetermineDrawCardNumber(int *_thisNumber,Card *_thisCard,int _thisIfInit,int _thisCardLatest){
	if (!_thisCardLatest){ *_thisNumber=0; return; }
	if (_thisIfInit>0){ *_thisNumber=0; return; }
	switch (_thisCard->Rank){
		case 2: *_thisNumber+=2; break;
		case 3: *_thisNumber+=3; break;
		case 7: *_thisNumber=0; break;
		default: *_thisNumber=0; break;
	}
}

void DetermineNextPlayer(User **_thisPlayer,int _thisPlayerNumber,int *_thisPlayOrder,Card *_thisCard,int _thisIfInit,int _thisCardLatest){
	if (_thisIfInit>0){ return; }
	if (!_thisCardLatest){ ShiftPlayer(_thisPlayer,(*_thisPlayOrder+_thisPlayerNumber)%_thisPlayerNumber); return; }
	switch (_thisCard->Rank){
		case 11: ShiftPlayer(_thisPlayer,2*(*_thisPlayOrder)%_thisPlayerNumber); break;
		case 12: *_thisPlayOrder*=-1; ShiftPlayer(_thisPlayer,(*_thisPlayOrder+_thisPlayerNumber)%_thisPlayerNumber); break;
		default: ShiftPlayer(_thisPlayer,(*_thisPlayOrder)%_thisPlayerNumber); break;
	}
//	ShiftPlayer(_thisPlayer,(*_thisPlayOrder)%_thisPlayerNumber);
}

void ShiftPlayer(User **_thisPlayer,int _thisNumber){
	if (_thisNumber==0) return;
	int _thisDirection=(_thisNumber>0);
	if (_thisNumber<0) _thisNumber*=-1;
	for (int i=1;i<=_thisNumber;i++){
		*_thisPlayer=(*_thisPlayer)->Nex[_thisDirection];
	}
}

void DeleteGame(Game* _thisGame){
	FPrint(_thisGame->LogFile,"Delete Game ...\n\n");
	DeletePlayer(_thisGame->LogFile,_thisGame->PlayerNumber,_thisGame->Player);
	DeletePile(_thisGame->LogFile,_thisGame->StockPile);
	DeletePile(_thisGame->LogFile,_thisGame->DiscardPile);
}
