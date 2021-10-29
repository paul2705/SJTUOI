#include<stdio.h>
#include<stdlib.h>
int main(){
	char a[100],b[100],opt;
	scanf("%s %s %c",a,b,&opt);
	double a1,a2,b1,b2;
	char c1,c2;
	double a3,b3;
	printf("\n%s\n%s\n",a,b);
	sscanf(a,"%lf%c%lfi",&a1,&c1,&a2); if (c1=='-') a2*=-1;
	sscanf(b,"%lf%c%lfi",&b1,&c2,&b2); if (c2=='-') b2*=-1;
	printf("%.2lf %.2lf\n%.2lf %.2lf\n",a1,a2,b1,b2);
	if (opt=='+') a3=a1+b1,b3=a2+b2;
	else if (opt=='-') a3=a1-b1,b3=a2-b2;
	else a3=a1*b1-a2*b2,b3=a1*b2+a2*b1;
	if (b3<0) printf("%.lf-%.lfi\n",a3,-b3);
	else printf("%.lf+%.lfi\n",a3,b3);
	return 0;
}
