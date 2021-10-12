#include"Card.h"
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

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
//		default: Function="Regular Card"; break;
	}
	return Function;
}

int IsCardMatch(Card *_former,Card *_later){
	return (_former->Rank==_later->Rank||_former->Suit==_later->Suit);
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

void DisplayCard(Card *_thisCard){
	char *_thisName=InterpretCardName(_thisCard);
	char *_thisFunction=InterpretCardFunction(_thisCard);
	printf("%s %d (%s)\n",_thisName,_thisCard->Rank,_thisFunction);
//	free(_thisName); free(_thisFunction);
}

void ClearCard(Card *_thisCard){
	_thisCard->Rank=0; _thisCard->Suit=0;
}
