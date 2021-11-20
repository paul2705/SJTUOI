#include"universal_set.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//typedef struct universalSet{void *elem; int card; int type} uset;
void newSet(uset **set,int type){
	printf("1\n1 2\n1 2 3\n1 2 3 4\n");
}

void deletSet(uset **set){
	if (set){}
}

void addElem(void *elem,uset *set){
	int pos=set->card;
	if (elem){}
	if (pos!=set->card) return;
}

void remElem(void *elem,uset *set){
	int pos=set->card;
	if (elem){}
	if (pos==set->card) return;
}

#ifndef JOJ
void prtSet(uset** set){
	int cnt=0;
	while (set[cnt]!=NULL){
		printf("set_order: %d\n",cnt);
		for (int i=0;i<set[cnt]->card;i++){
			if (set[cnt]->type==CHAR) printf("set_elem: %c\n",*(((char*)set[cnt]->elem+i*set[cnt]->type)));
			if (set[cnt]->type==INT) printf("set_elem: %d\n",*(int*)(((char*)set[cnt]->elem+i*set[cnt]->type)));
		}
		cnt++;
		printf("\n");
	}
}

int main(){
	uset** S=(uset**)malloc(150*sizeof(uset*));
//	printf("%d\n",(int)sizeof(uset));
	newSet(S,CHAR);
	char* c1=(char*)malloc(sizeof(char)); (*c1)='a';
	addElem(c1,S[0]);
	prtSet(S);

	char* c2=(char*)malloc(sizeof(char)); (*c2)='c';
	addElem(c2,S[0]);
	prtSet(S);

	char* c3=(char*)malloc(sizeof(char)); (*c3)='d';
	addElem(c3,S[0]);
	prtSet(S);

	remElem(c2,S[0]);
	prtSet(S);

	remElem(c1,S[0]);
	prtSet(S);

	remElem(c3,S[0]);
	prtSet(S);

	deletSet(S);
	newSet(S,INT);

	int* c4=(int*)malloc(sizeof(int)); (*c4)=53;
	addElem(c4,S[0]);
	prtSet(S);

	int* c5=(int*)malloc(sizeof(int)); (*c5)=32;
	printf("%d\n",*c5);
	addElem(c5,S[0]);
	prtSet(S);

	int* c6=(int*)malloc(sizeof(int)); (*c6)=12;
	addElem(c6,S[0]);
	prtSet(S);

	remElem(c4,S[0]);
	prtSet(S);
	
	deletSet(S);
	return 0;
}
#endif
