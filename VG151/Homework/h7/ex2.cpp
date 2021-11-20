#include "homework.h"
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

void ex2(){
	int x,y; double a;
	if (scanf("%d%lf%d",&x,&a,&y)){}
//	printf("%d %lf %d\n",x,a,y);
	cout.setf(ios::showpoint);
	if (x==1) cout<<setprecision(y)<<a*6.20350<<endl;
	else cout<<setprecision(y)<<a/6.20350<<endl;
}

#ifdef JOJ
int main(){
    ex2();
    return 0;
}
#endif
