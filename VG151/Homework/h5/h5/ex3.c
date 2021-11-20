#include "assignment.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ex. 3 function: disptach work to other functions for exercise 3
void ex3() {
	char s[10005];
	char cmp[10005];
	int cnt=0;
	if (scanf("%[^\n]%*c",s)){}
	if (scanf("%s",cmp)){}
	int n=(int)strlen(s),m=(int)strlen(cmp);
	for (int i=0;i<n;i++){
		int fg=0;
		for (int j=i;j<i+m;j++){
			if (s[j]!=cmp[j-i]) fg=1;
		}
		if (!fg) cnt++;
	}
	printf("The string '%s' occurs %d times\n",cmp,cnt);
}
//#define JOJ
#ifdef JOJ
int main(){
    ex3();
    return 0;
}
#endif
