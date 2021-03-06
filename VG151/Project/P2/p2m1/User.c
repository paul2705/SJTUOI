#include"User.h"

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#include"Card.h"
#include"Pile.h"
#include"UIScreen.h"

void DrawCardFromPile(Pile *_formerPile,Pile *_laterPile,int DrawCardNumber){
	for (int i=1;i<=DrawCardNumber;i++){
		InsertCardToPile(_formerPile,OutputCardFromPile(_laterPile));
//		DisplayPile(_formerPile);
	}
}

void InitializePlayer(User **_thisPlayers,int _thisPlayerNumber){
	for (int i=0;i<_thisPlayerNumber;i++){
//		printf("Player: %d\n",i);
		_thisPlayers[i]->HandCard=(Pile*)malloc(sizeof(Pile));
		InitializePile(_thisPlayers[i]->HandCard);
	}
}

void DisplayPlayer(User *_thisPlayer){
	UIPrint(0,"Player: %s\n",_thisPlayer->PlayerName);
	DisplayPile(_thisPlayer->HandCard);
	UIPrint(0,"\n");
}
