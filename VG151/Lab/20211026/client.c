#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"calculator.h"

int main(){
	int a,b; char opt;
	while (1){
		printf("var1 opt var2\n");
		scanf("%d %c %d",&a,&opt,&b);
		printf("%lf\n",evaluate(a,opt,b));
	}
	return 0;
}
