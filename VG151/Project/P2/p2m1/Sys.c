#include"Sys.h"

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#ifdef _WIN32
	#include<windows.h>
#else 
	#include<unistd.h>
#endif

void ClearScreen(){
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void PauseScreen(int _thisSecond){
	#ifdef _WIN32
		Sleep((unsigned int)_thisSecond);
	#else
//		printf("%d\n",_thisSecond*1000);
		usleep((unsigned int)_thisSecond*1000);
	#endif
}
