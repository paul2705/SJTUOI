#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<fstream>
#include<string>
using namespace std;
char s[505];
string ss;
int main(){
	ifstream myin("a.in");
	ofstream myout("a.out");
	while (getline(myin,ss)){
		cout<<ss<<endl;
		myout<<ss<<endl;
	}
	myin.close(); myout.close();
	return 0;
}
