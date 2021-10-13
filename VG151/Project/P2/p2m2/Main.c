#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stddef.h>

#include"Card.h"
#include"Pile.h"
#include"User.h"
#include"Operation.h"
#include"Game.h"

int OptionType(char *_thisOption){
//	printf("%s\n",_thisOption);
	return (_thisOption[0]=='-'?
			_thisOption[1]=='-'?
			_thisOption[2]=='-'? 0:2:1:0);
}

int main(int Argc,char *Argv[]){
	srand((unsigned int)time(NULL));
	Game _thisGame; InitializeGame(&_thisGame);
	_thisGame.PlayerNumber=4;
	_thisGame.InitialCardNumber=5;
	_thisGame.DeckNumber=2;
	_thisGame.RoundNumber=1;
	_thisGame.Debug=0;
	char _thisChar;
//	printf("%d %s\n",Argc,Argv[1]);
	for (int i=1;i<Argc;i++){
		char *Option=Argv[i];
		int Type=OptionType(Option);
		if (Type==0){
			if (i==0){
				printf("ERROR!");
				return 0;
			}
		}
		else {
			int _thisNumber=0;
			if (Type==1&&Option[1]!='h'&&Option[1]!='g'){
				char *Parameter=Argv[i+1];
				int ParaType=OptionType(Parameter);
				if (ParaType>0){
					printf("ERROR!");
					return 0;
				}
				sscanf(Parameter,"%d",&_thisNumber);
			}
			switch (Option[Type]){
				case 'h': printf("-h|--help             print this help message \n");
						printf("--log filename          write the logs in filename (default: onecard.log) \n"); 
						printf("-n n|--player-number=n  n players, n must be larger than 2 (default: 4) \n"); 
						printf("-c c|--initial-cards=c  deal c cards per player, c must be at least 2 (default: 5) \n"); 
						printf("-d d|--decks=d          use d decks 52 cards each, d must be at least 2 (default: 2) \n"); 
						printf("-r r|--rounds=r         play r rounds, r must be at least 1 (default: 1) \n");
						printf("-a|--auto               run in demo mode \n"); 
						printf("-g|--debug              run in debug mode \n");
						printf("Enter Any Word To StartGame Or Enter ? To Shut Down\n");
						while (!scanf("%c",&_thisChar)); 
						break;
				case 'n': _thisGame.PlayerNumber=_thisNumber; break;
				case 'c': _thisGame.InitialCardNumber=_thisNumber; break;
				case 'd': _thisGame.DeckNumber=_thisNumber; break;
				case 'r': _thisGame.RoundNumber=_thisNumber; break;
				case 'g': _thisGame.Debug=1; break;
			}
		}
	}
	if (_thisChar!='?') StartGame(&_thisGame);
	else OptInitialize(&_thisGame);
	return 0;
}
