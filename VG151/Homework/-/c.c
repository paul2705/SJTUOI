#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void change(int *a){
	*a=6;
}
int main(){
	int a=5;
	change(&a);
	printf("%d\n",a);
	return 0;
}
