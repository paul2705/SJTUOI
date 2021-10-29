#include "assignment.h"
#include<stdio.h>
#include<stdlib.h>
  

// ex. 2 function: disptach work to other functions for exercise 2
int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
void ex2() {
	int a,b;
	if (scanf("%d%d",&a,&b)){}
	printf("%d\n",gcd(a,b));
}

#ifdef JOJ
int main(){
    ex2();
    return 0;
}
#endif
