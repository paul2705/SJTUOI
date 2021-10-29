#include "assignment.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
  

// ex. 3 function: disptach work to other functions for exercise 3
void ex3() {
	double a,b,c; 
	if (scanf("%lf%lf%lf",&a,&b,&c)){}
	if (b*b-4.0*a*c<0){
		printf("%.5lf-%.5lfi\n",-b/(2.0*a),(sqrt(-b*b+4.0*a*c))/(2.0*a));
		printf("%.5lf+%.5lfi\n",-b/(2.0*a),(sqrt(-b*b+4.0*a*c))/(2.0*a));
	}
	else if (b*b-4.0*a*c==0){
		printf("%.5lf\n",(-b-sqrt(b*b-4.0*a*c))/(2.0*a));
	}
	else {
		printf("%.5lf\n",(-b-sqrt(b*b-4.0*a*c))/(2.0*a));
		printf("%.5lf\n",(-b+sqrt(b*b-4.0*a*c))/(2.0*a));
	}
}

#ifdef JOJ
int main(){
    ex3();
    return 0;
}
#endif
