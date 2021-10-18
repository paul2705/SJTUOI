#ifndef _SYS_H_
	#define _SYS_H_

	#ifdef _WIN32
		#include<windows.h>
	#else
		#include<unistd.h>
	#endif
	#include<stdio.h>
	#include<stdlib.h>
	#include<stddef.h>

	void ClearScreen();
	void PauseScreen(int _thisSecond);

#endif
