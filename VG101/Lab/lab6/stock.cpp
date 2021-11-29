#include"stock.h"
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

stock::stock(){

}

stock::~stock(){

} 

void stock::update(int timestamp, int price){
	int pos=-1;
	for (int i=0;i<Stock.size();i++){
		if (Stock[i].first==timestamp){
			pos=i;
			break;
		}
	}
	if (pos==-1){
		Stock.push_back(make_pair(timestamp,price));
		sort(Stock.begin(),Stock.end(),cmp_first);
	}
	else Stock[pos].second=price;
}

int stock::current(){
	return Stock[Stock.size()-1].second;
}

int stock::maximum(){
	sort(Stock.begin(),Stock.end(),cmp_second);
	int ret=Stock[Stock.size()-1].second;
	sort(Stock.begin(),Stock.end(),cmp_first);
	return ret;
}

int stock::minimum(){
	sort(Stock.begin(),Stock.end(),cmp_second);
	int ret=Stock[0].second;
	sort(Stock.begin(),Stock.end(),cmp_first);
	return ret;
}

void stock::show(){
	for (int i=0;i<Stock.size();i++){
		printf("%d %d\n",Stock[i].first,Stock[i].second);
	}
}

int main(){
    //write your main function to accept user input and give output
    stock data;
	while (1){
		char s[15]; cin>>s;
		switch (s[0]){
			case 'u': int x; cin>>x;
					  for (int i=1;i<=x;i++){
						  int t,p; cin>>t>>p;
						  data.update(t,p);
					  }
					  break;
			case 's': char t[15]; cin>>t;
					  switch (t[1]){
						  case 'l': data.show(); break;
						  case 'a': printf("%d\n",data.current()); break;
						  case 'i': printf("%d\n",data.maximum()); break;
						  case 'o': printf("%d\n",data.minimum()); break;
					  }
					  break;
			case 'e': return 0;
		}
	}
    return 0;
}
