#ifndef _PILE_H_
	#define _PILE_H_

	#include"Card.h"
	#include<stdio.h>
	#include<stdlib.h>
	#include<stddef.h>

	typedef struct _Pile{
		Card **thisPile;
		int PileSize;
	} Pile;

	void InitializePile(Pile *_thisPile);
	void CreatePile(Pile *_thisPile);
	void InsertCardToPile(Pile *_thisPile,Card *_thisCard);
	Card *OutputCardFromPile(Pile *_thisPile);
	void WithdrawCardFromPile(Pile *_thisPile,int _thisCardNumber);
	void DisplayPile(char *LogFile,Pile *_thisPile,int _thisOption);
	void EmptyPile(Pile *_thisPile);
	void DeletePile(char *LogFile,Pile *_thisPile);

#endif
