#include"Sys.h"

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<time.h>
#ifdef _WIN32
	#include<windows.h>
#else 
	#include<unistd.h>
#endif

void ClearScreen(){
	#ifdef _WIN32
		system("cls");
	#elif __APPLE__
		system("clear");
	#elif __linux__
		system("clear");
	#elif __unix__
		system("clear");
	#endif
}

void PauseScreen(int _thisSecond){
	#ifdef _WIN32
		Sleep((unsigned int)_thisSecond);
	#elif __APPLE__
//		printf("%d\n",_thisSecond/150);
		usleep((unsigned int)_thisSecond*1000);
	#elif __linux__
		sleep((unsigned int)_thisSecond/150);
	#elif __unix__
		usleep((unsigned int)_thisSecond*1000);
	#endif
}
