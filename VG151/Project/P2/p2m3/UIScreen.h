#ifndef _UISCREEN_H_
	#define _UISCREEN_H_

	#include<stdio.h>
	#include<stdlib.h>
	#include<stddef.h>
	#include<ncurses.h>	

	void UIPrint(int _thisPauseTime,char *_thisFormat,...);
	void FPrint(char *LogFile,char *_thisFormat,...);
	WINDOW *AddLogWin(char *LogFile);

#endif
