#include "assignment.h"
#include<stdio.h>
#include<stdlib.h>
#include<float.h>
#include<math.h>

double f(double h,double v,double a,double x){
	return h+tan(a)*x-(9.81/(2*v*v*cos(a)*cos(a)))*x*x;
}

// ex. 4 function: disptach work to other functions for exercise 4
void ex4() {
	double h,v,a,l,r,mid;
	if (scanf("%lf%lf%lf%lf%lf",&v,&a,&h,&l,&r)){}
	a=a/180.0*acos(-1);
	while (fabs(r-l-FLT_EPSILON)>0.0000001){
		mid=(r+l)/2.0;
//		printf("%lf %lf\n",mid,f(h,v,a,mid));
		if (f(h,v,a,mid)*f(h,v,a,r)>0) r=mid;
		else l=mid;
	}
	printf("%lf\n",l);
}
//#define JOJ
#ifdef JOJ
int main(){
    ex4();
    return 0;
}
#endif
