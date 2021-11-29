#include"assignment.h"
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

void ex1_ordered_array(){
	string arr[100005];
	int cnt=0;
	string s;
	while (cin>>s) arr[cnt++]=s;
	for (int i=0;i<cnt;i++) cout<<arr[i]<<" ";
	printf("\n");
}
void ex1_ordered_vector(){
	vector<string> arr;
	string s;
	while (cin>>s) arr.push_back(s);
	for (vector<string>::iterator it=arr.begin();it!=arr.end();it++) cout<<(*it)<<" ";
	printf("\n");
}
void ex1_ordered_queue(){
	queue<string> arr;
	string s;
	while (cin>>s) arr.push(s);
	while (!arr.empty()){
		cout<<arr.front()<<" ";
		arr.pop();
	}
	printf("\n");
}
void ex1_reverse_array(){
	string arr[100005];
	int cnt=0;
	string s;
	while (cin>>s) arr[cnt++]=s;
	for (int i=cnt-1;i>=0;i--) cout<<arr[i]<<" ";
	printf("\n");
}
void ex1_reverse_vector(){
	vector<string> arr;
	string s;
	while (cin>>s) arr.push_back(s);
	for (vector<string>::reverse_iterator it=arr.rbegin();it!=arr.rend();it++) cout<<(*it)<<" ";
	printf("\n");
}
void ex1_reverse_stack(){
	stack<string> arr;
	string s;
	while (cin>>s) arr.push(s);
	while (!arr.empty()){
		cout<<arr.top()<<" ";
		arr.pop();
	}
	printf("\n");
}

#ifndef JOJ
int main(){
//	ex1_ordered_array();
//	ex1_reverse_array();
//	ex1_ordered_vector();
	ex1_reverse_vector();
//	ex1_ordered_queue();
//	ex1_reverse_stack();
	return 0;
}
#endif
