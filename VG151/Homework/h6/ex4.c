#include "assignment.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// ex. 4 function: disptach work to other functions for exercise 4
void ex4() {
	FILE *myin=fopen("matrices.txt","r");
	int a[505][505],an=1,am=1,cnt=1;
	int b[505][505],bn=1,bm=1;
	char c='.';
//	printf("IN\n");
	while (an!=am+1){
//		printf("%c\n",c);
		fscanf(myin,"%d",&a[an][cnt++]);
//		printf("%d %f\n",a[an][cnt-1],ceil(log10(abs(a[an][cnt-1]))));
		c=(char)getc(myin);
//		printf("%d,%c\n",a[an][am-1],c);
		if (c=='\n') an++,am=cnt-1,cnt=1;
	}
	an--;
//	printf("%c\n",c);
	c='.'; cnt=1;
	while (bn!=bm+1){
		fscanf(myin,"%d",&b[bn][cnt++]);
		c=(char)getc(myin);
		if (c=='\n'||c==EOF) bn++,bm=cnt-1,cnt=1;
	}
	bn--;
//	printf("%d %d %d %d\n",an,am,bn,bm);
	FILE *myout=fopen("result.txt","w");
	for (int i=1;i<=an;i++){
		for (int j=1;j<=am;j++) fprintf(myout,"%d ",a[i][j]+b[i][j]);
		fprintf(myout,"\n");
	}
	fprintf(myout,"\n");
	int C[505][505];
	for (int i=1;i<505;i++){
		for (int j=1;j<505;j++) C[i][j]=0;
	}
	for (int i=1;i<=an;i++){
		for (int j=1;j<=bm;j++){
			for (int k=1;k<=am;k++) C[i][j]+=a[i][k]*b[k][j];
		}
	}
	for (int i=1;i<=an;i++){
		for (int j=1;j<=bm;j++) fprintf(myout,"%d ",C[i][j]);
		fprintf(myout,"\n");
	}
	fprintf(myout,"\n");
/*	for (int i=1;i<=an;i++){
		for (int j=1;j<=am;j++) C[j][i]=a[i][j];
	}
	for (int i=1;i<=am;i++){
		for (int j=1;j<=an;j++) a[i][j]=C[i][j];
	}
	for (int i=1;i<=bn;i++){
		for (int j=1;j<=bm;j++) C[j][i]=b[i][j];
	}
	for (int i=1;i<=bm;i++){
		for (int j=1;j<=bn;j++) b[i][j]=C[i][j];
	}
	for (int i=1;i<=am;i++){
		for (int j=1;j<=an;j++) printf("%d ",a[i][j]);
		printf("\n");
	}
	for (int i=1;i<=bm;i++){
		for (int j=1;j<=bn;j++) printf("%d ",b[i][j]);
		printf("\n");
	}
*/	for (int i=1;i<505;i++){
		for (int j=1;j<505;j++) C[i][j]=0;
	}
	for (int i=1;i<=am;i++){
		for (int j=1;j<=bn;j++){
			for (int k=1;k<=an;k++){
//				printf("%d %d %d %d\n",i,j,a[i][k],b[k][j]);
				C[i][j]+=a[k][i]*b[j][k];
			}
		}
	}
//	fprintf(myout,"%d\n",bn);
	for (int i=1;i<=am;i++){
		for (int j=1;j<=bn;j++) fprintf(myout,"%d ",C[i][j]);
		fprintf(myout,"\n");
	}
	fprintf(myout,"\n");
	fclose(myin);
	fclose(myout);
}

#ifndef JOJ
int main(){
    ex4();
    return 0;
}
#endif
