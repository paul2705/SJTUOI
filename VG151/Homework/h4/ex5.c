#include "assignment.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"sum.h"
#include"prod.h"
#include"quorem.h"
#include"exp.h"
int ex5(){
	int a, b;
	printf("Enter two integers: "); 
	scanf("%d %d",&a, &b); 
	printf("Quotient: %d\n",quo(a,b)); 
	printf("Remainder: %d\n",rem(a,b)); 
	printf("Sum: %d\n",sum(a,b)); 
	printf("Product: %d\n",prod(a,b)); 
	printf("Exponent: %ld\n",mpow(a,b)); 
	return 0;
}

#ifdef JOJ
int main(){
    ex5();
    return 0;
}
#endif