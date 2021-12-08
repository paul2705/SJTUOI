#ifndef _SYS_H_
	#define _SYS_H_

	#ifdef _WIN32
		#include<windows.h>
	#else
		#include<unistd.h>
	#endif

	void PauseScreen(int _thisSecond);

#endif
