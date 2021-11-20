#include"universal_set.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define ul unsigned long
//typedef struct universalSet{void *elem; int card; int type} uset;
void newSet(uset **set,int type){
//	int cnt=0;
//	while (set[cnt]!=NULL) cnt++;
//	printf("%d\n",(int)sizeof(uset**));
//	printf("ADD\n");
	(*set)=(uset*)malloc(sizeof(uset));
	if (type==CHAR) (*set)->elem=(char**)malloc(INITSETSIZE*sizeof(char*));
	if (type==INT) (*set)->elem=(int**)malloc(INITSETSIZE*sizeof(int*));
	if (type==DOUBLE) (*set)->elem=(double**)malloc(INITSETSIZE*sizeof(double*));
	(*set)->type=type;
	(*set)->card=0;
//	for (int i=1;i<2;i++){
//		set[i]=(uset*)malloc(sizeof(uset));
//		set[i]->elem=malloc(INITSETSIZE*(unsigned long)CHAR);
//		set[i]->card=0; set[i]->type=CHAR;
//	}
}

void addElem(void *elem,uset *set){
	int pos=set->card;
//	printf("add: %d %c\n",set->card,*((char*)elem));
	for (int i=0;i<set->card;i++){
		if (set->type==CHAR&&memcmp((char*)((char**)set->elem+(ul)i*sizeof(char*)),elem,(ul)set->type)==0){
			pos=i;
			break;
		}
	}
	if (pos!=set->card){
		free(elem);
		return;
	}
	if (set->card%INITSETSIZE==0&&set->card!=0){
		if (set->type==CHAR) set->elem=realloc(set->elem,(unsigned long)(set->card+INITSETSIZE)*(unsigned long)sizeof(char*));
		if (set->type==INT) set->elem=realloc(set->elem,(unsigned long)(set->card+INITSETSIZE)*(unsigned long)sizeof(int*));
		if (set->type==DOUBLE) set->elem=realloc(set->elem,(unsigned long)(set->card+INITSETSIZE)*(unsigned long)sizeof(double*));
	}
	if (set->type==CHAR) memcpy((char*)((char**)set->elem+(ul)set->card*sizeof(char*)),elem,sizeof(char*));
	set->card++;
//	if (elem){}
//	printf("iii: %p ? %p\n",*(int**)((char**)set->elem+sizeof(void*)*set->card),elem);
//	free((char*)set->elem+set->type*set->card);
}

void remElem(void *elem,uset *set){
	int pos=set->card;
//	printf("rem: %d %c\n",set->card,*((char*)elem));
	for (int i=0;i<set->card;i++){
		if (set->type==CHAR&&memcmp((char*)((char**)set->elem+(ul)i*sizeof(char*)),elem,(ul)set->type)==0){
			pos=i;
			break;
		}
	}
	if (pos==set->card) return;
	free(elem);
	set->card--;
//	if (elem){}
	for (int i=pos;i<set->card;i++){
		if (set->type==CHAR) memcpy((char*)((char**)set->elem+(ul)i*sizeof(char*)),(char*)((char**)set->elem+(ul)(i+1)*sizeof(char*)),sizeof(char*));
	}
	if (set->card%INITSETSIZE==0&&set->card>=INITSETSIZE){
		if (set->type==CHAR) set->elem=realloc(set->elem,(unsigned long)(set->card)*(unsigned long)sizeof(char*));
		if (set->type==INT) set->elem=realloc(set->elem,(unsigned long)(set->card)*(unsigned long)sizeof(int*));
		if (set->type==DOUBLE) set->elem=realloc(set->elem,(unsigned long)(set->card)*(unsigned long)sizeof(double*));
	}
}

void deletSet(uset **set){
//	printf("DEL\n");
//	int cnt=0;
//	while (set[cnt]!=NULL){
//		free(set[cnt]->elem);
//		cnt++;
//	}
	for (int i=(*set)->card-1;i>=0;i--){
		if ((*set)->type==CHAR) free((char*)((char**)(*set)->elem+(ul)i*sizeof(char*)));
	}
	free((*set)->elem);
//	free((*set)->elem);
//	for (int i=1;i<2;i++){
//		free(set[i]->elem);
//		free(set[i]);
//	}
	free((*set));
//	free(set);
//	(*set)->card=0;
}

#ifndef JOJ
void prtSet(uset** set){
	int cnt=0;
	while (set[cnt]!=NULL){
		printf("set_order: %d\n",cnt);
		for (int i=0;i<set[cnt]->card;i++){
			if (set[cnt]->type==CHAR) printf("set_elem: %c\n",*(char*)((char**)set[cnt]->elem+i*sizeof(char*)));
			// if (set[cnt]->type==INT) printf("set_elem: %d\n",*set[cnt]->elem[i]);
			// if (set[cnt]->type==DOUBLE) printf("set_elem: %.2lf\n",*set[cnt]->elem[i]);
		}
		cnt++;
		printf("\n");
	}
}

int main(){
	uset** S=(uset**)malloc(150*sizeof(uset*));
	newSet(S,CHAR);
	char* c1=(char*)malloc(sizeof(char)); (*c1)='a';
	printf("c1: %p\n",c1);
	addElem(c1,S[0]);
	prtSet(S);

	char* c2=(char*)malloc(sizeof(char)); (*c2)='a';
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
/*	newSet(S,INT);

	int* c4=(int*)malloc(sizeof(int)); (*c4)=53;
	addElem(c4,S[0]);
	prtSet(S);

	int* c5=(int*)malloc(sizeof(int)); (*c5)=32;
//	printf("%d\n",*c5);
	addElem(c5,S[0]);
//	printf("%d\n",*c5);
	prtSet(S);

	int* c6=(int*)malloc(sizeof(int)); (*c6)=12;
	addElem(c6,S[0]);
	prtSet(S);

	remElem(c4,S[0]);
	prtSet(S);
	
	deletSet(S);
*/	return 0;
}
#endif
