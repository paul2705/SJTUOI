#include"Card.h"
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

char *InterpretCardName(Card _this){
	char *Name=malloc(15*sizeof(char));
	switch (_this.Suit){
		case 1: Name="Spades"; break;
		case 2: Name="Hearts"; break;
		case 3: Name="Diamonds"; break;
		case 4: Name="Clubs"; break;
	}
	return Name;
}

int IsCardMatch(Card _former,Card _later){
	return (_former.Rank==_later.Rank||_former.Suit==_later.Rank);
}

Card *CreateNewCard(int _thisCardSuit,int _thisCardRank){
//	printf("3001\n");
	Card *_thisNewCard=malloc(sizeof(Card));
	_thisNewCard->Suit=_thisCardSuit;
	_thisNewCard->Rank=_thisCardRank;
//	printf("3002\n");
	return _thisNewCard;
}

void ClearCard(Card *_thisCard){
	printf("5001\n");
	_thisCard->Rank=0; _thisCard->Suit=0;
	printf("5002\n");
}
