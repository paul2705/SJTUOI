#ifndef _CARD_H_
	#define _CARD_H_
	
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
	int IsCardMatch(Card *_former,Card *_later);
	int IsCardEmpty(Card *_thisCard);
	int CardOrder(Card *_thisCard);
	Card *CreateNewCard(int _thisCardSuit,int _thisCardRank);
	void DisplayCard(Card *_thisCard);
	void ClearCard(Card *_thisCard);
	void DeleteCard(Card *_thisCard);

#endif
