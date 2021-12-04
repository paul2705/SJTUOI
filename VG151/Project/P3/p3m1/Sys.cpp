#include"Sys.h"

#ifdef _WIN32
	#include<windows.h>
#else 
	#include<unistd.h>
#endif

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
