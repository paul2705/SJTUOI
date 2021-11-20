#include "assignment.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
// ex. 3 function: disptach work to other functions for exercise 3
void ex3() {
//	printf("%d %s\n",cnts,s);
	FILE *myin=fopen("word.txt","r+");
	char *w=(char*)malloc(10005*sizeof(char));
	for (int i=0;i<10005;i++) w[i]='\0';
	int cnt=0;
	if (fscanf(myin,"%s",w)==EOF) return;
//	printf("%d %s\n",cntw,w);
	fclose(myin);
	myin=fopen("sentence.txt","r+");
	char *s=(char*)malloc(10005*sizeof(char));
	for (int i=0;i<10005;i++) s[i]='\0';
	while (fscanf(myin,"%s",s)!=EOF){
//		printf("%s\n",s);
		int ns=(int)strlen(s),nw=(int)strlen(w);
		if (ns!=nw) continue;
		int fg=1;
		for (int i=0;i<ns;i++){
			if (s[i]!=w[i]) fg=0;
		}
		if (fg) cnt++;
	}
	FILE *myout=fopen("count.txt","w+");
	fprintf(myout,"%d\n",cnt);
	fclose(myin);
	fclose(myout);
	free(w); free(s);
}
//#define JOJ
#ifndef JOJ
int main(){
    ex3();
    return 0;
}
#endif
