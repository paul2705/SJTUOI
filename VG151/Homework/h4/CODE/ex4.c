#include<stdio.h>
#include<stdlib.h>
void q2(char *s){
	if (s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u') printf("vowel\n");
	else printf("consonant\n");
}
void q3(char *s){
	if (s[0]=='1') printf("char\nunsigned char\nsigned char\n");
	if (s[0]=='2') printf("short\nunsigned short\n");
	if (s[0]=='4') printf("int\nunsigned int\nfloat\n");
	if (s[0]=='8') printf("long long\nunsigned long long\ndouble\n");
}
int main(){
	char s[15];
	scanf("%s",s);
	if (s[0]>='a'&&s[0]<='z') q2(s);
	else q3(s);
	return 0;
}
