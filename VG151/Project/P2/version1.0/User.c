#include"User.h"

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#include"Card.h"
#include"Pile.h"

void DrawCardFromPile(Pile *_formerPile,Pile *_laterPile,int DrawCardNumber){
	printf("2001\n");
	for (int i=1;i<=DrawCardNumber;i++)
		InsertCardToPile(_formerPile,OutputCardFromPile(_laterPile));
	printf("2002\n");
}

void InitializePlayer(User **_thisPlayer,int _thisPlayerNumber){
	printf("1001\n");
	_thisPlayer=malloc(_thisPlayerNumber*sizeof(User*));
	printf("1002\n");
	for (int i=0;i<_thisPlayerNumber;i++){
		_thisPlayer[i]=malloc(sizeof(User));
		InitializePile(&_thisPlayer[i]->HeadCard);
	}
	printf("1003\n");
}
