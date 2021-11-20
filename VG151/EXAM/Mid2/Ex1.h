#ifndef _EX1_H_
	#define _EX1_H_
	
	typedef struct _Murderer{
		int Suspects,Locations,Weapons;
	} Murderer;

	char *Interpret(int x,int y);
	int check(Murderer x,Murderer y);

#endif
