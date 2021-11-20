#include "homework.h"
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iomanip>
using namespace std;

void ex3(){
	ifstream myin("matrices.txt");
	ofstream myout("result.txt");
	int a[505][505],an=1,am=1,cnt=0;
	int b[505][505],bn=1,bm=1;
	char c;
	myin>>noskipws;
	while (an!=am+1){
		if (myin>>a[an][++cnt]>>c){}
//		printf("%d c:%c\n",a[an][cnt],c);
		if (c=='\n') am=cnt,cnt=0,an++;
	}	
//	printf("IN %d\n",an-1);
	myin>>c;
	cnt=0; an--;
	while (bn!=bm+1){
		if (myin>>b[bn][++cnt]>>c){}
//		printf("%d c:%c\n",b[bn][cnt],c);
		if (c=='\n'||c==EOF) bm=cnt,cnt=0,bn++;
	}
	bn--;
//	printf("IN\n");
	int n=an;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			myout<<a[i][j]+b[i][j]<<" ";
		}
		myout<<"\n";
	}
	myout<<"\n";
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			int cnt=0;
			for (int k=1;k<=n;k++){
				cnt+=a[i][k]*b[k][j];
			}
			myout<<cnt<<" ";
		}
		myout<<"\n";
	}
	myout<<"\n";
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			int cnt=0;
			for (int k=1;k<=n;k++){
				cnt+=a[k][i]*b[j][k];
			}
			myout<<cnt<<" ";
		}
		myout<<"\n";
	}
	myout<<"\n";
	myin.close(); myout.close();
}

#ifdef MY 
int main(){
    ex3();
    return 0;
}
#endif
