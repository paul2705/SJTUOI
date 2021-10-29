#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	double a,b,c; 
	scanf("%lf%lf%lf",&a,&b,&c);
	printf("%.5lf\n",(-b+sqrt(b*b-4.0*a*c))/(2.0*a));
	printf("%.5lf\n",(-b-sqrt(b*b-4.0*a*c))/(2.0*a));
	return 0;
}
