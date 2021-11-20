#include"Card.h"
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#include"UIScreen.h"

char *InterpretCardName(Card *_thisCard){
	char *Name=malloc(15*sizeof(char));
	switch (_thisCard->Suit){
		case 1: Name="Spades   "; break;
		case 2: Name="Hearts   "; break;
		case 3: Name="Diamonds "; break;
		case 4: Name="Clubs    "; break;
	}
	return Name;
}

char *InterpretCardFunction(Card *_thisCard){
	char *Function=malloc(100*sizeof(char));
	switch (_thisCard->Rank){
		case 2: Function="Draws Two Cards"; break;
		case 3: Function="Draws Three Cards"; break;
		case 7: Function="Cancel An Attack"; break;
		case 11: Function="Skip The Next Player"; break;
		case 12: Function="Reverse The Playing Order"; break;
		default: Function="~"; break;
	}
	return Function;
}

int IsCardMatch(Card *_former,Card *_later,int _thisOption){
	if (_thisOption) return (_former->Rank==_later->Rank||_former->Suit==_later->Suit);
	if (_later->Rank==2||_later->Rank==3){
		return ((_former->Rank==_later->Rank)||(_former->Suit==_later->Suit&&((_former->Rank>=2&&_former->Rank<=3)||_former->Rank==7)));
	}
	else return (_former->Rank==_later->Rank||_former->Suit==_later->Suit);
}

int IsCardEmpty(Card *_thisCard){
//	printf("IsCardEmpty (%d,%d)\n",_thisCard->Rank,_thisCard->Suit);
	return (_thisCard->Rank==0&&_thisCard->Suit==0);
}

int CardOrder(Card *_thisCard){
	return _thisCard->Suit*15+_thisCard->Rank;
}

Card *CreateNewCard(int _thisCardSuit,int _thisCardRank){
	Card *_thisNewCard=malloc(sizeof(Card));
	_thisNewCard->Suit=_thisCardSuit;
	_thisNewCard->Rank=_thisCardRank;
	return _thisNewCard;
}

void DisplayCard(char *LogFile,Card *_thisCard,int _thisOption){
	char *_thisName=InterpretCardName(_thisCard);
	char *_thisFunction=InterpretCardFunction(_thisCard);
	if (_thisOption) UIPrint(0,"%s %2d (%s)\n",_thisName,_thisCard->Rank,_thisFunction);
	FPrint(LogFile,"%s %2d; ",_thisName,_thisCard->Rank);
//	free(_thisName); free(_thisFunction);
}

void ClearCard(Card *_thisCard){
	_thisCard->Rank=0; _thisCard->Suit=0;
}

void DeleteCard(char *LogFile,Card *_thisCard){
	FPrint(LogFile,"Delete Card (Rank:%d Suit:%d) ....",_thisCard->Rank,_thisCard->Suit);
	free(_thisCard);
	FPrint(LogFile,"Success!\n");
}
