#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void change(int a[][5]){
	a[1][1]=5342;
}
int main(){
	int elem[5][5];
	int cnt=0;
	for (int i=0;i<5;i++){
		for (int j=0;j<5;j++) elem[i][j]=++cnt;
	}
	change(elem);
	for (int i=0;i<5;i++){
		for (int j=0;j<5;j++) printf("%d ",elem[i][j]);
		printf("\n");
	}
	return 0;
}
