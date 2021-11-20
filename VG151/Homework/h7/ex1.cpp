#include "homework.h"
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

void ex1(){
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	y+=z-x;
	printf("%d\n",y);
}

#ifdef JOJ
int main(){
    ex1();
    return 0;
}
#endif
