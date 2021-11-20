#include "assignment.h"
#include"uset.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// ex. 5 function: disptach work to other functions for exercise 2
elem* newElem(double x,char type){
	elem *E=(elem*)malloc(sizeof(elem));
	E->type=type;
	E->data=(double*)malloc(sizeof(double));
	*(E->data)=x;
	return E;
}

void deletElem(elem *E){
	free(E->data);
	free(E);
}

uset* newSet(char type){
	uset *S=(uset*)malloc(sizeof(uset));
	S->set=(elem**)malloc(INITSETSIZE*sizeof(elem*));
	S->card=0; S->lim=INITSETSIZE;
//	for (int i=0;i<S->lim;i++) S->set[i]=(elem*)malloc(sizeof(elem));
	S->type=type;
	return S;
}

void deletSet(uset *S){
	for (int i=0;i<S->card;i++) deletElem(S->set[i]);
	free(S->set);
	free(S);
}

int addElem(double x,uset *S){
	int pos=-1;
	for (int i=0;i<S->card;i++){
		if (*(S->set[i]->data)==x){
			pos=i;
			break;
		}
	}
	if (pos!=-1) return 0;
	if (S->card==S->lim){
		S->lim+=INITSETSIZE;
		S->set=(elem**)realloc(S->set,(unsigned long)S->lim*sizeof(elem*));
//		for (int i=S->lim-INITSETSIZE;i<S->lim;i++)
//			S->set[i]=(elem*)malloc(sizeof(elem));
	}
//	printf("%lf\n",x);
	S->set[S->card++]=newElem(x,S->type);
	return 1;
}

int remElem(double x,uset *S){
	int pos=-1;
	for (int i=0;i<S->card;i++){
		if (*(S->set[i]->data)==x){
			pos=i;
			break;
		}
	}
//	printf("%d\n",pos);
	if (pos==-1) return 0;
	deletElem(S->set[pos]); S->card--;
	for (int i=pos;i<S->card;i++) S->set[i]=S->set[i+1];
	if (S->card-1==S->lim-INITSETSIZE){
		S->lim-=INITSETSIZE;
		S->set=(elem**)realloc(S->set,(unsigned long)S->lim*sizeof(elem*));
	}
	return 1;
}

void prtSet(uset *S){
	for (int i=0;i<S->card;i++){
		if (S->type=='c') printf("%c ",(char)*(S->set[i]->data));
		if (S->type=='i') printf("%d ",(int)*(S->set[i]->data));
		if (S->type=='d') printf("%.2lf ",(double)*(S->set[i]->data));
	}
	printf("\n");
}


void ex5() {
/*	char s[60]; int n;
	scanf("%s%d",s,&n);
	uset *S=newSet(s[0]);
	deletSet(S);
	for (int i=1;i<=n;i++){
		scanf("%s",s);
		printf("%d\n",i);
		if (s[0]=='a'){
			if (S->type=='c'){
				char x; scanf(" %c",&x);
				addElem((double)x,S);
			}
			if (S->type=='d'){
				double x; scanf("%lf",&x);
				addElem(x,S);
			}
			if (S->type=='i'){
				int x; scanf("%d",&x);
				addElem((double)x,S);
			}
		}
		if (s[0]=='r'){
			if (S->type=='c'){
				char x; scanf(" %c",&x);
				remElem((double)x,S);
			}
			if (S->type=='d'){
				double x; scanf("%lf",&x);
				remElem(x,S);
			}
			if (S->type=='i'){
				int x; scanf("%d",&x);
				remElem((double)x,S);
			}
		}
		prtSet(S);
	}
	deletSet(S);
*/}

#ifndef JOJ
int main(){
    ex5();
    return 0;
}
#endif
