#include"UIScreen.h"

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<stdarg.h>
#include<ncurses.h>

#include"Card.h"
#include"Pile.h"
#include"User.h"
#include"Operation.h"
#include"Game.h"
#include"Sys.h"

void UIPrint(int _thisPauseTime,char *_thisFormat,...){
	va_list ap;
	va_start(ap,_thisFormat);
	for (char *c=_thisFormat;*c;c++){
		if (*c!='%') printf("%c",*c);
		else switch (*++c){
			case 'd': printf("%d",va_arg(ap,int)); break;
			case 'c': printf("%c",(char)va_arg(ap,int)); break;
			case 's': printf("%s",(char*)va_arg(ap,char*)); break;
			default : 	
				if (*c=='2'){
					printf("%2d",va_arg(ap,int));
					c++;
				}
				else printf("%c",*c); 
				break;
		}
	}
	va_end(ap);
	fflush(stdout);
	PauseScreen(_thisPauseTime);
}

//void UIHelpStart(){

void FPrint(char *LogFile,char *_thisFormat,...){
	FILE *Fout=fopen(LogFile,"a");
	va_list ap;
	va_start(ap,_thisFormat);
	for (char *c=_thisFormat;*c;c++){
		if (*c!='%') fprintf(Fout,"%c",*c);
		else switch (*++c){
			case 'd': fprintf(Fout,"%d",va_arg(ap,int)); break;
			case 'c': fprintf(Fout,"%c",(char)va_arg(ap,int)); break;
			case 's': fprintf(Fout,"%s",(char*)va_arg(ap,char*)); break;
			default : 	
				if (*c=='2'){
					fprintf(Fout,"%2d",va_arg(ap,int));
					c++;
				}
				else fprintf(Fout,"%c",*c); 
				break;
		}
	}
	fclose(Fout);
	va_end(ap);
}

WINDOW *AddLogWin(char *LogFile){
	WINDOW *LogWin=newwin(50,15,1,50);
	box(LogWin,ACS_VLINE,ACS_HLINE);
	printf("%s\n",LogFile);
	return LogWin;
}
