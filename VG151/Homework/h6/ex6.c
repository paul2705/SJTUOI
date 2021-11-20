#include "assignment.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ex. 6 function: disptach work to other functions for exercise 2
void ex6() {
	char s[1100005];
	char c1,c2;
	printf("Input a string: ");
	if (scanf("%[^\n]%*c",s)){}
	printf("* Choose 1 to replace a character or 2 to delete a character: ");
	int n=(int)strlen(s);
	int opt; scanf("%d",&opt);
	if (opt==1){
		printf("  Replace character: ");
		scanf("\n%c",&c1);
		printf("  with: ");
		scanf("\n%c",&c2);
		printf("New string: ");
		for (int i=0;i<n;i++){
			if (s[i]==c1) printf("%c",c2);
			else printf("%c",s[i]);
		}
	}
	else {
		printf("  Delete character: ");
		scanf("\n%c",&c1);
		printf("New string: ");
		for (int i=0;i<n;i++){
			if (s[i]!=c1) printf("%c",s[i]);
		}
	}
	printf("\n");
}

#ifdef JOJ
int main(){
    ex6();
    return 0;
}
#endif
