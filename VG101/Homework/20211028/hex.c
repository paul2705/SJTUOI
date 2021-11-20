#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int interpret(char c){
	if (c>='0'&&c<='9') return c-'0';
	else if (c>='A'&&c<='G') return c-'A'+10;
	else return 0;
}
char convert(int x){
	if (x>=0&&x<=9) return x+'0';
	else if (x<=16) return x+'A'-10;
	else return ' ';
}
void reverse(char *s){
	for (int i=0,j=strlen(s)-1;i<j;i++,j--){
		char tmp=s[i];
		s[i]=s[j];
		s[j]=tmp;
	}
}
int main(){
	char s1[505]={'\0'},s2[505]={'\0'};
	printf("hexadecimal number 1: "); scanf("%s",s1);
	printf("hexadecimal number 2: "); scanf("%s",s2);
	int n=0;
	reverse(s1); reverse(s2);
	if (strlen(s1)>strlen(s2)) n=strlen(s1);
	else n=strlen(s2);
	for (int i=0;i<n;i++){
		int tmp=interpret(s1[i])+interpret(s2[i]);
		s1[i]=convert(tmp%16);
		s1[i+1]=convert(interpret(s1[i+1])+tmp/16);
	}
	reverse(s1);
	int now=0; n=strlen(s1);
	for (;now<n;now++){
		if (s1[now]!='0') break;
	}
	printf("Their sum is ");
	for (;now<n;now++) printf("%c",s1[now]);
	printf("\n");
	return 0;
}
