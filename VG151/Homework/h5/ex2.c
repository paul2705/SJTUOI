#include "assignment.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ex. 2 function: disptach work to other functions for exercise 2
int interpret(char *s){
	if (!strcmp(s,"Sun")) return 0;
	if (!strcmp(s,"Mon")) return 1;
	if (!strcmp(s,"Tue")) return 2;
	if (!strcmp(s,"Wed")) return 3;
	if (!strcmp(s,"Thu")) return 4;
	if (!strcmp(s,"Fri")) return 5;
	if (!strcmp(s,"Sat")) return 6;
	return -1;
}

void ex2() {
	int mon; char s[15];
	int days[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	char month[15][10]={"","January","February","March","April","May","June","July","August","September","October","November","December"};
	if (scanf("%d%s",&mon,s)){}
	int day=interpret(s);
	printf("%s\n",month[mon]);
	printf("Sun Mon Tue Wed Thu Fri Sat\n");
//	printf("%d\n",day);
	for (int i=0;i<day;i++){
		printf("    ");
	}
	for (int i=1;i<=days[mon];i++){
		printf("%3d ",i);
		day=(day+1)%7;
		if (day==0) printf("\n");
	}
}
//#define JOJ
#ifdef JOJ
int main(){
    ex2();
    return 0;
}
#endif
