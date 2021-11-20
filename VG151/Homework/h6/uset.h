#ifndef _USET_H_
	#define _USET_H_

	#define INITSETSIZE 64
	#define CHAR 1
	#define INT sizeof(int)
	#define DOUBLE sizeof(double)
	
	typedef struct _elem{
		double *data;
		char type;
	} elem;
	typedef struct _uset{
		elem **set;
		int card,lim;
		char type;
	} uset;

	elem* newElem(double x,char type);
	void deletElem(elem *E);
	uset* newSet(char type);
	void deletSet(uset *set);
	int addElem(double x,uset *S);
	int remElem(double x,uset *S);
	void prtSet(uset *S);
#endif
