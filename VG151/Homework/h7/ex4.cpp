#include "homework.h"
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=(int)1e7+5;

void ex4(){
    ll x,y; if (scanf("%lld%lld",&x,&y)){}
	if (x==1){
		int cnt=0;
		for (;y!=1;){
			if (y%2==0) y/=2;
			else y=3*y+1;
			cnt++;
		}
		printf("%d\n",cnt);
	}
	else {
		int mx=0,ans=0;
		int* f=(int*)malloc((size_t)MAXN*sizeof(int));
		f[1]=0;
		for (int i=2;i<=y;i++){
			f[i]=0;
			ll tmp=i; 
			while (tmp>=i){
				if (tmp%2==0) tmp/=2;
				else tmp=tmp*3+1;
				f[i]++;
			}
			f[i]+=f[tmp];
//			printf("%d %d\n",i,f[i]);
			if (f[i]>mx) mx=f[i],ans=i;
		}
		free(f);
		printf("%d\n",ans);
	}
}

#ifdef JOJ
int main(){
    ex4();
    return 0;
}
#endif
