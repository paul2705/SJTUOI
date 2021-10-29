#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	char s[105];
	stdin=fopen("cal.txt","r");
	while (~fscanf(stdin,"%s",s)){
		printf("%s\n",s);
	}
	return 0;
}
