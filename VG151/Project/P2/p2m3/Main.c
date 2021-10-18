#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stddef.h>
#include<ncurses.h>

#include"UIScreen.h"
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
	sprintf(_thisGame.LogFile,"onecard.log");
//	initscr();
//	WINDOW *LogWin=AddLogWin(_thisGame.LogFile);
//	wprintw(LogWin,"ruriewriw\n");
//	wrefresh(LogWin);
	char _thisChar;
//	printf("%d %s\n",Argc,Argv[1]);
	for (int i=1;i<Argc;i++){
		char *Option=Argv[i];
		int Type=OptionType(Option);
		if (Type==0){
			if (i==0){
				UIPrint(0,"ERROR!");
				return 0;
			}
		}
		else {
			int _thisNumber=0;
			if (Type==1&&Option[1]!='h'&&Option[1]!='g'){
				char *Parameter=Argv[i+1];
				int ParaType=OptionType(Parameter);
				if (ParaType>0){
					UIPrint(0,"ERROR!");
					return 0;
				}
				sscanf(Parameter,"%d",&_thisNumber);
			}
			switch (Option[Type]){
				case 'h': UIPrint(0,"-h|--help             print this help message \n");
						UIPrint(0,"--log filename          write the logs in filename (default: onecard.log) \n"); 
						UIPrint(0,"-n n|--player-number=n  n players, n must be larger than 2 (default: 4) \n"); 
						UIPrint(0,"-c c|--initial-cards=c  deal c cards per player, c must be at least 2 (default: 5) \n"); 
						UIPrint(0,"-d d|--decks=d          use d decks 52 cards each, d must be at least 2 (default: 2) \n"); 
						UIPrint(0,"-r r|--rounds=r         play r rounds, r must be at least 1 (default: 1) \n");
						UIPrint(0,"-a|--auto               run in demo mode \n"); 
						UIPrint(0,"-g|--debug              run in debug mode \n");
						UIPrint(0,"Enter Any Word To StartGame Or Enter ? To Shut Down\n");
						while (!scanf("%c",&_thisChar)); 
						break;
				case 'n': _thisGame.PlayerNumber=_thisNumber; break;
				case 'c': _thisGame.InitialCardNumber=_thisNumber; break;
				case 'd': _thisGame.DeckNumber=_thisNumber; break;
				case 'r': _thisGame.RoundNumber=_thisNumber; break;
				case 'g': _thisGame.Debug=1; break;
				case 'l': sprintf(_thisGame.LogFile,"%s",Argv[i+1]);
			}
		}
	}
	if (_thisChar!='?') StartGame(&_thisGame);
	else OptInitialize(&_thisGame);
//	endwin();
	return 0;
}
