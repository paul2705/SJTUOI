#ifndef _CARD_H_
	#define _CARD_H_

	#include<stdio.h>
	#include<stdlib.h>
	#include<stddef.h>
	
	typedef struct _Card{
		int Rank,Suit;
		// suit
		//  1: Spades
		//  2: Hearts
		//  3: Diamonds
		//  4: Clubs
	} Card;
	
	char *InterpretCardName(Card *_thisCard);
	char *InterpretCardFunction(Card *_thisCard);
	int IsCardMatch(Card *_former,Card *_later,int _laterOption);
	int IsCardEmpty(Card *_thisCard);
	int CardOrder(Card *_thisCard);
	Card *CreateNewCard(int _thisCardSuit,int _thisCardRank);
	void DisplayCard(char *LogFile,Card *_thisCard,int _thisOption);
	void ClearCard(Card *_thisCard);
	void DeleteCard(char *LogFile,Card *_thisCard);

#endif
