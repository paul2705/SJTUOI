#include "assignment.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// ex. 1 function: disptach work to other functions for exercise 1
void ex1() {
	int n; if (scanf("%d",&n)){}
	int *fg=(int*)malloc((long unsigned int)(n/32+1)*sizeof(int));
	for (int i=0;i<(n/32)+1;i++) fg[i]=0;
	int *pri=(int*)malloc((long unsigned int)(sqrt(n)+5)*sizeof(int));
//	for (int i=0;i<n;i++) pri[i]=0;
	pri[0]=0;
	for (int i=2;i<n;i++){
		if (((fg[i/32]>>(i%32))&1)==0){
			printf("%d ",i);
			if (i<=sqrt(n)) pri[++pri[0]]=i;
		}
//		printf("%d %d\n",pri[pri[0]],pri[0]);
		for (int j=1;j<=pri[0]&&pri[j]*i<n;j++){
//			printf("%d\n",pri[j]*i);
			fg[pri[j]*i/32]|=(1<<((pri[j]*i)%32));
//			printf("%d %d %d\n",pri[j]*i,pri[j]*i/32,(pri[j]*i)%32);
			if (i%pri[j]==0) break;
		}
	}
//	for (int i=1;i<=pri[0];i++) printf("%d ",pri[i]);
	printf("\n");
}
//#define JOJ
#ifdef JOJ
int main(){
    ex1();
    return 0;
}
#endif
