#include "assignment.h"
#include<stdio.h>
#include<stdlib.h>
  
// ex. 1 function: disptach work to other functions for exercise 1
void ex1() {
	char a[505],b[505],opt;
	if (scanf("%s %s %c",a,b,&opt)){}
	int a1,a2,b1,b2;
	char c1,c2;
	int a3,b3;
	if (sscanf(a,"%d%c%di",&a1,&c1,&a2)){} if (c1=='-') a2*=-1;
	if (sscanf(b,"%d%c%di",&b1,&c2,&b2)){} if (c2=='-') b2*=-1;
	//printf("%d %d\n%d %d\n%c\n",a1,a2,b1,b2,opt);
	if (opt=='+') a3=a1+b1,b3=a2+b2;
	else if (opt=='-') a3=a1-b1,b3=a2-b2;
	else a3=a1*b1-a2*b2,b3=a1*b2+a2*b1;
	if (b3<0) printf("%d-%di\n",a3,-b3);
	else printf("%d+%di\n",a3,b3);
}

#ifdef JOJ
int main(){
    ex1();
    return 0;
}
#endif
