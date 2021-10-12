#ifndef _PILE_H_
	#define _PILE_H_

	#include"Card.h"

	typedef struct _Pile{
		Card **thisPile;
		int PileSize;
	} Pile;

	void InitializePile(Pile *_thisPile);
	void CreatePile(Pile *_thisPile);
	void InsertCardToPile(Pile *_thisPile,Card *_thisCard);
	Card *OutputCardFromPile(Pile *_thisPile);
	void DisplayPile(Pile *_thisPile);
	void EmptyPile(Pile *_thisPile);

#endif
