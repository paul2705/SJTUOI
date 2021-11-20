#include"universal_set.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//typedef struct universalSet{void *elem; int card; int type} uset;
void newSet(uset **set,int type){
//	int cnt=0;
//	while (set[cnt]!=NULL) cnt++;
//	printf("ADD\n");
//	set[1]=(uset*)calloc(1,sizeof(uset));
//	(*set)=(uset*)calloc(10,sizeof(uset));
//	printf("%d %d\n",set[0][2].type,set[0][3].card);
	(*set)->elem=calloc(INITSETSIZE,(unsigned long)type);
	(*set)->type=type;
	(*set)->card=0;
}

void deletSet(uset **set){
//	printf("DEL\n");
//	int cnt=0;
//	while (set[cnt]!=NULL){
//		free(set[cnt]->elem);
//		cnt++;
//	}
	free((*set)->elem);
	free((*set));
//	if (set){}
}

void addElem(void *elem,uset *set){
	int pos=set->card;
//	printf("add: %d %c\n",set->card,*((char*)elem));
//	printf("%p %d\n",elem,(int)sizeof(elem));
	for (int i=0;i<set->card;i++){
		void *E=(char*)set->elem+i*set->type;
		if (memcmp(E,elem,(unsigned long)set->type)==0){
			pos=i;
			break;
		}
	}
//	if (elem){}
	if (pos!=set->card) return;
	if (set->card%INITSETSIZE==0&&set->card>0) set->elem=realloc(set->elem,(unsigned long)(set->card+INITSETSIZE)*(unsigned long)set->type);
	memcpy((void*)((char*)set->elem+set->type*set->card),elem,(unsigned long)set->type);
	set->card++;
}

void remElem(void *elem,uset *set){
	int pos=set->card;
//	printf("rem: %d %c\n",set->card,*((char*)elem));
//	printf("%p %d\n",elem,(int)sizeof(elem));
	for (int i=0;i<set->card;i++){
		void *E=(char*)set->elem+i*set->type;
		if (memcmp(E,elem,(unsigned long)set->type)==0){
			pos=i;
			break;
		}
	}
//	if (elem){}
	if (pos==set->card) return;
	set->card--;
	for (int i=pos;i<set->card;i++){
		void *E1=(char*)set->elem+i*set->type;
		void *E2=(char*)set->elem+(i+1)*set->type;
		memcpy(E1,E2,(unsigned long)set->type);
	}
	if (set->card%INITSETSIZE==0&&set->card>=INITSETSIZE) set->elem=realloc(set->elem,(unsigned long)(set->card)*(unsigned long)set->type);
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
