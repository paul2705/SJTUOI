#include <stdio.h>
#include <string.h>

char* strshift(char *str, int shift)
{/* TODO: complete this function as instructed */
    int len=strlen(str);
	shift=(shift+len)%len;
	for (int i=1;i<=shift;i++){
		char *p1=str+len-1;
		char *p2=p1-1;
		char tmp=str[len-1];
		for (;p1!=str;p1--,p2--) *p1=*p2;
		*p1=tmp;
	}
	return str;
} 

/* safe version of gets() */
char* vg101_gets(char *str, int count)
{
    int i = 0;
    char ch = getchar();
    while (ch != '\n' && i < count-1)
    {
        str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0'; /* add the null character */
    return str;
}

int main()
{
    int shift;
    char str[256]; /* suppose the length of string is less than 256 */
    char *pstr;
    printf("Please input a string: ");
    vg101_gets(str, 256);
    printf("Please input the shift: ");
    scanf("%d", &shift);
    pstr = strshift(str, shift);
    printf("str = %s\n", str);
    printf("*pstr = %s\n", pstr);
    return 0;
}
