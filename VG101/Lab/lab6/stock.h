#ifndef STOCK_H_
#define STOCK_H_

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class stock{
	private:
	    vector<pair<int,int> > Stock;
	    static bool cmp_first(pair<int,int> &a,pair<int,int> &b){
			return a.first<b.first;
		}
		static bool cmp_second(pair<int,int> &a,pair<int,int> &b){
			return a.second<b.second;
		}
	public:
		stock();//constructor
		~stock();//destructor
		void update(int timestamp, int price);//Update or generate the price of the stock at a time stamp
		int current();//Find the Latest stock price in the data stream until now.
		int maximum();//Find the highest stock price in the data stream until now
		int minimum();//Find the lowest stock price in the data stream until now
		void show();//Print out all the records which is sorted by time
};
//please implement these functions and write main function at stock.cpp

#endif 
