#include"Pile.h"

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#include"Card.h"

void InitializePile(Pile *_thisPile){
	_thisPile->thisPile=(Card**)malloc(sizeof(Card*)*55);
	for (int i=0;i<55;i++){
		_thisPile->thisPile[i]=(Card*)malloc(sizeof(Card));
	}
	EmptyPile(_thisPile);
}

void CreatePile(Pile *_thisPile){
	for (int i=1;i<=4;i++){
		for (int j=1;j<=13;j++){
//			printf("%d %d %d\n",i,j,_thisPileCount);
			_thisPile->thisPile[_thisPile->PileSize++]=CreateNewCard(i,j);
//			printf("(%d,%d) (%d,%d)\n",i,j,_thisPile->thisPile[_thisPileCount-1]->Suit,_thisPile->thisPile[_thisPileCount-1]->Rank);
		}
	}
}

void InsertCardToPile(Pile *_thisPile,Card *_thisCard){
	for (int i=0;i<=_thisPile->PileSize;i++){
//		printf("loop_step: %d\n",i);
		if (IsCardEmpty(_thisPile->thisPile[i])){
			_thisPile->thisPile[i]=_thisCard;
			break;
		}
		if (i==0&&CardOrder(_thisPile->thisPile[i])>=CardOrder(_thisCard)){
			for (int j=_thisPile->PileSize;j>0;j--) _thisPile->thisPile[j]=_thisPile->thisPile[j-1];
			_thisPile->thisPile[0]=_thisCard;
			break;
		}
		if (CardOrder(_thisPile->thisPile[i])<=CardOrder(_thisCard) &&
				CardOrder(_thisPile->thisPile[i+1])>=CardOrder(_thisCard)){
			for (int j=_thisPile->PileSize;j>i+1;j--) _thisPile->thisPile[j]=_thisPile->thisPile[j-1];
			_thisPile->thisPile[i+1]=_thisCard;
			break;
		}
	}
	_thisPile->PileSize++;
}

Card *OutputCardFromPile(Pile *_thisPile){
	int Cardx=rand()%_thisPile->PileSize;
	Card *_thisCard=_thisPile->thisPile[Cardx];
	WithdrawCardFromPile(_thisPile,Cardx);
	return _thisCard;
}

void WithdrawCardFromPile(Pile *_thisPile,int _thisCardNumber){
	for (int i=_thisCardNumber;i<_thisPile->PileSize-1;i++) _thisPile->thisPile[i]=_thisPile->thisPile[i+1];
	_thisPile->PileSize--;
}

void DisplayPile(Pile *_thisPile){
	printf("PileSize: %d\n",_thisPile->PileSize);
	for (int i=0;i<_thisPile->PileSize;i++){
//		if (IsCardEmpty(_thisPile->thisPile[i])) break;
		printf("%d: ",i);
		DisplayCard(_thisPile->thisPile[i]);
	}
	printf("\n");
}

void EmptyPile(Pile *_thisPile){
	for (int i=0;i<55;i++){
		ClearCard(_thisPile->thisPile[i]);
	}
	_thisPile->PileSize=0;
}