#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
//const int MAXN=1e5+5;
int main(){
	int *p=new int[10];
	for (int i=0;i<=10;i++) p[i]=0;
	cin>>p[0]>>p[10];
	for (int i=0;i<=10;i++) cout<<p[i]<<" ";
	cout<<endl;
	delete[] p;
	return 0;
}
