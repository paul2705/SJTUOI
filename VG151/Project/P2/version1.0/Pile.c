#include"Pile.h"

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#include"Card.h"

void InitializePile(Pile *_thisPile){
	printf("Shit!\n");
	_thisPile->thisPile=(Card**)malloc(sizeof(Card*)*55);
	printf("FAQ!\n");
	for (int i=0;i<55;i++){
		_thisPile->thisPile[i]=(Card*)malloc(sizeof(Card));
	}
	printf("Fuck!\n");
}

void CreatePile(Pile *_thisPile){
	int _thisPileCount=0;
	printf("Fuck!!!!!\n");
	printf("Size:%d\n",(int)sizeof(_thisPile->thisPile));
	for (int i=1;i<=4;i++){
		for (int j=1;j<=13;j++){
			printf("%d %d %d\n",i,j,_thisPileCount);
			_thisPile->thisPile[_thisPileCount++]=CreateNewCard(i,j);
			printf("(%d,%d) (%d,%d)\n",i,j,_thisPile->thisPile[_thisPileCount-1]->Suit,_thisPile->thisPile[_thisPileCount-1]->Rank);
		}
	}
	printf("1002\n");
}

void InsertCardToPile(Pile *_thisPile,Card *_thisCard){
	int _thisPileSize=sizeof(_thisPile->thisPile)/sizeof(Card);
	printf("_Pile_InsertCardToPile_ PileSize: %d\n",_thisPileSize);
	for (int i=0;i<55;i++){
		if (_thisPile->thisPile[i]->Suit==_thisCard->Suit &&
				(_thisPile->thisPile[i]->Rank<=_thisCard->Rank && _thisPile->thisPile[i+1]->Rank>=_thisCard->Rank)){
			for (int j=54;j>i;j--) _thisPile->thisPile[j]=_thisPile->thisPile[j-1];
			_thisPile->thisPile[i]=_thisCard;
			break;
		}
	}
}

Card *OutputCardFromPile(Pile *_thisPile){
	int _thisPileSize=sizeof(_thisPile->thisPile);
	int Cardx=rand()%_thisPileSize+1;
	Card *_thisCard=_thisPile->thisPile[Cardx];
	for (int i=Cardx;i<54;i++) _thisPile->thisPile[i]=_thisPile->thisPile[i+1];
	return _thisCard;
}

void EmptyPile(Pile *_thisPile){
	printf("4001\n");
	int _thisPileSize=sizeof(_thisPile->thisPile)/sizeof(Card);
	printf("4002 PileSize:%d %d\n",_thisPileSize,(int)sizeof(Card));
	for (int i=0;i<55;i++){
		printf("4003\n");
		ClearCard(_thisPile->thisPile[i]);
	}
	printf("4004\n");
}
