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
	int _laterWinner=0;
	FILE *Fout=fopen(_thisGame->LogFile,"w");
	fclose(Fout);
	for (int i=1;i<=_thisGame->RoundNumber;i++){
		OptInitialize(_thisGame);
		
		int _thisPlayer;
		if (i==1) _thisPlayer=rand()%_thisGame->PlayerNumber;
		else _thisPlayer=_laterWinner;
		int _thisDrawCardNumber=0;
		int _thisIfInit=1;
		int _thisPlayOrder=1;

		Card *LastTurnCard=OutputCardFromPile(_thisGame->StockPile);
		InsertCardToPile(_thisGame->DiscardPile,LastTurnCard);
		int _thisCardLatest=0;

		while (!IsGameEnd(_thisGame->LogFile,_thisGame,&_laterWinner)){
			ClearScreen();

			DisplayGame(_thisGame->LogFile,_thisGame,_thisGame->Debug);
			UIPrint(100,"Round: %d , StockPile: %d , DiscardPile: %d\n",i,_thisGame->StockPile->PileSize,_thisGame->DiscardPile->PileSize);
			FPrint(_thisGame->LogFile,"Round: %d , StockPile: %d , DiscardPile: %d\n",i,_thisGame->StockPile->PileSize,_thisGame->DiscardPile->PileSize);
			
			DetermineDrawCardNumber(&_thisDrawCardNumber,LastTurnCard,_thisIfInit,_thisCardLatest);
			DetermineNextPlayer(&_thisPlayer,_thisGame->PlayerNumber,&_thisPlayOrder,LastTurnCard,_thisIfInit,_thisCardLatest);
			
			UIPrint(50,"Player: %d\n",_thisPlayer);
			FPrint(_thisGame->LogFile,"Player: %d\n",_thisPlayer);
			UIPrint(50,"You Are Supposed To Draw %d Card(s).\n",_thisDrawCardNumber);
			FPrint(_thisGame->LogFile,"You Are Supposed To Draw %d Card(s).\n",_thisDrawCardNumber);
			UIPrint(50,"Last Card: "); 
			FPrint(_thisGame->LogFile,"Last Card: "); DisplayCard(_thisGame->LogFile,LastTurnCard,1);
			UIPrint(500,"\n\n"); FPrint(_thisGame->LogFile,"\n\n");

			UIPrint(50,"Your Current HandCard: \n"); FPrint(_thisGame->LogFile,"Your Current HandCard: \n");
			DisplayPile(_thisGame->LogFile,_thisGame->Player[_thisPlayer]->HandCard,1);
			Card* _tmpCard=LastTurnCard;
			LastTurnCard=OptPlayerPlayCard(_thisGame->LogFile,_thisGame->Player[_thisPlayer],LastTurnCard,_thisGame->DiscardPile,!_thisCardLatest);					

			if (_thisIfInit>0) _thisIfInit=0;
			
			_thisCardLatest=(LastTurnCard!=_tmpCard);
			if (!_thisCardLatest&&_thisDrawCardNumber==0) _thisDrawCardNumber++;
			if ((_thisCardLatest)&&(LastTurnCard->Rank==7||LastTurnCard->Rank==2||LastTurnCard->Rank==3||LastTurnCard->Rank==11||LastTurnCard->Rank==12))
				OptPlayerDrawCard(_thisGame->LogFile,_thisGame->Player[_thisPlayer],_thisGame->StockPile,_thisGame->DiscardPile,0);
			else OptPlayerDrawCard(_thisGame->LogFile,_thisGame->Player[_thisPlayer],_thisGame->StockPile,_thisGame->DiscardPile,_thisDrawCardNumber);

			if (_thisGame->StockPile->PileSize==0){ 
				UIPrint(200,"StockPile Is Empty! \n"); FPrint(_thisGame->LogFile,"StockPile Is Empty! \n");
				UIPrint(500,"Refresh The StockPile...."); FPrint(_thisGame->LogFile,"Refresh The StockPile....");
				OptShiftPile(_thisGame->StockPile,_thisGame->DiscardPile);
				UIPrint(200,"Success!\n"); FPrint(_thisGame->LogFile,"Success!\n");
			}

		}
	}
	DeleteGame(_thisGame);
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

void DisplayGame(char *LogFile,Game *_thisGame,int _thisOption){
	if (_thisOption) UIPrint(0,"PlayerNumber: %d\n",_thisGame->PlayerNumber);
	FPrint(LogFile,"PlayerNumber: %d\n",_thisGame->PlayerNumber);
	if (_thisOption) UIPrint(0,"InitialCardNuber: %d\n",_thisGame->InitialCardNumber);
	FPrint(LogFile,"InitialCardNuber: %d\n",_thisGame->InitialCardNumber);
	if (_thisOption) UIPrint(0,"DeckNumber: %d\n",_thisGame->DeckNumber);
	FPrint(LogFile,"DeckNumber: %d\n",_thisGame->DeckNumber);
	if (_thisOption) UIPrint(0,"RoundNumber: %d\n",_thisGame->RoundNumber);
	FPrint(LogFile,"RoundNumber: %d\n",_thisGame->RoundNumber);
	
	for (int i=0;i<_thisGame->PlayerNumber;i++)
		DisplayPlayer(LogFile,_thisGame->Player[i],_thisOption);
	
	if (_thisOption) UIPrint(0,"StockPile: \n");
	FPrint(LogFile,"StockPile: \n");
	DisplayPile(LogFile,_thisGame->StockPile,_thisOption);
	
	if (_thisOption) UIPrint(0,"DiscardPile: \n");
	FPrint(LogFile,"DiscardPile: \n");
	DisplayPile(LogFile,_thisGame->DiscardPile,_thisOption);
}

int IsGameEnd(char *LogFile,Game *_thisGame,int *_laterWinner){
	for (int i=0;i<_thisGame->PlayerNumber;i++){
		if (_thisGame->Player[i]->HandCard->PileSize==0){
			UIPrint(500,"Player:%d wins!\n",i);
			FPrint(LogFile,"Player:%d wins!\n",i);
			*_laterWinner=i;
			for (int j=0;j<_thisGame->PlayerNumber;j++){
				for (int k=0;k<_thisGame->Player[j]->HandCard->PileSize;k++){
					Card *_thisCard=_thisGame->Player[j]->HandCard->thisPile[k];
					_thisGame->Player[j]->Penalty+=
						((_thisCard->Rank==2||_thisCard->Rank==3)? 5:
						(_thisCard->Rank==11||_thisCard->Rank==12)?3:1)
						*10;
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

void DetermineNextPlayer(int *_thisPlayer,int _thisPlayerNumber,int *_thisPlayOrder,Card *_thisCard,int _thisIfInit,int _thisCardLatest){
	if (!_thisCardLatest){ *_thisPlayer=(*_thisPlayer+*_thisPlayOrder+_thisPlayerNumber)%_thisPlayerNumber; return; }
	if (_thisIfInit>0){ return; }
	switch (_thisCard->Rank){
		case 11: *_thisPlayer=(*_thisPlayer+2*(*_thisPlayOrder))%_thisPlayerNumber; break;
		case 12: *_thisPlayOrder*=-1; *_thisPlayer=(*_thisPlayer+*_thisPlayOrder+_thisPlayerNumber)%_thisPlayerNumber; break;
		default: *_thisPlayer=(*_thisPlayer+*_thisPlayOrder)%_thisPlayerNumber; break;
	}
	*_thisPlayer=(*_thisPlayer+_thisPlayerNumber)%_thisPlayerNumber;
}

void DeleteGame(Game* _thisGame){
	DeletePlayer(_thisGame->PlayerNumber,_thisGame->Player);
	DeletePile(_thisGame->StockPile);
	DeletePile(_thisGame->DiscardPile);
}
