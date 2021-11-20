#include "assignment.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
// ex. 1 function: disptach work to other functions for exercise 1
void ex1() {
	int a[1005],n;
	srand(time(NULL));
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int x=rand()%100;
	printf("Larger Than %d:\n",x);
	for (int i=1;i<=n;i++){
		if (a[i]>x) printf("%d ",a[i]);
	}
	printf("\n");
}
//#define JOJ
#ifdef JOJ
int main(){
    ex1();
    return 0;
}
#endif
