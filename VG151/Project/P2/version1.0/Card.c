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
	return (_former.Rank==_later.Rank||_former.Suit==_later.Suit);
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
	switch (_thisCard->Suit){
		case 1: printf("Spades   "); break;
		case 2: printf("Hearts   "); break;
		case 3: printf("Diamonds "); break;
		case 4: printf("Clubs    "); break;
	}
	printf("%d\n",_thisCard->Rank);
}

void ClearCard(Card *_thisCard){
	_thisCard->Rank=0; _thisCard->Suit=0;
}
