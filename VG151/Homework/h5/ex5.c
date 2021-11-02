#include"assignment.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *InterpretC(int x){
	switch (x){
		case 1: return "Spades";
		case 2: return "Hearts";
		case 3: return "Diamonds";
		case 4: return "Clubs";
	}
	return "-1";
}

char *InterpretN(int x){
	switch (x){
		case 1: return "Ace";
		case 11: return "Jack";
		case 12: return "Queen";
		case 13: return "King";
		case 10: return "10";
		case 2: return "2";
		case 3: return "3";
		case 4: return "4";
		case 5: return "5";
		case 6: return "6";
		case 7: return "7";
		case 8: return "8";
		case 9: return "9";
	}
	return "-1";
}

void ex5(){
	struct rec{
		int x,y;
	} a[53];
	int cnt=0;
	for (int i=1;i<=4;i++){
		for (int j=1;j<=13;j++){
			a[++cnt].x=i;
			a[cnt].y=j;
		}
	}
	for (int k=1;k<=3;k++){
		for (int i=1;i<=10000;i++){
			int tmp1=rand()%52+1,tmp2=rand()%52+1;
			struct rec tmp=a[tmp1]; a[tmp1]=a[tmp2]; a[tmp2]=tmp;
		}
		for (int i=1;i<=52;i++){
			printf("%s %s\n",InterpretC(a[i].x),InterpretN(a[i].y));
		}
		while (!getchar()){}
	}
}

#ifdef JOJ
int main(){
	ex5();
	return 0;
}
#endif
