#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
class stk{
	private:
		vector<int> st;
	public:
		bool empty(){ return st.size()==0; }
		void push(int x){ st.push_back(x); }
		void pop(int x){ st.pop_back(); }
		int top(){ return st[st.size()-1]; }
		int size() const { return st.size(); }
		bool operator < (const stk &a) const {
			return size()<a.size(); 
		}
};
priority_queue<stk> q;
int main(){
	stk a; a.push(1); a.push(3); cout<<a.top()<<endl;
	stk b; b.push(5);
	q.push(a); q.push(b);
	cout<<q.top().size()<<endl;
	return 0;
}
