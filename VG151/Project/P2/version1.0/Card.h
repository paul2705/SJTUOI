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
	
	char *InterpretCardName(Card _this);
	int IsCardMatch(Card _former,Card _later);
	Card *CreateNewCard(int _thisCardSuit,int _thisCardRank);
	void ClearCard(Card *_thisCard);

#endif
