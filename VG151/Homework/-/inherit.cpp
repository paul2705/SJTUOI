#include<iostream>
using namespace std;
class Cow{
	public:
		Cow(int f=0){ grass=f; }
		void Speak(){ cout<<"Moo.\n"; }
		void Eat(){
			if (grass>0){ grass--; cout<<"Thanks I'm full.\n"; }
			else cout<<"I'm hungry.\n"; 
		}
	protected: 
		int grass;
};
class SickCow: public Cow{
	public:
		SickCow(int f=0,int m=0){ grass=f; med=m; }
		virtual void Speak(){ cout<<"Ahem... Moo.\n"; }
		void TakeMed(){
			if (med>0){
				med--; cout<<"I fell better.\n";
			}
			else cout<<"I'm dying.\n";
		}
	private:
		int med;
};
class SickSickCow{
	public:
		void Speak(){ cout<<"FUCK... Moo.\n"; }
};
int main(){
	Cow c1(1); SickCow c2; SickSickCow *c3=(SickSickCow*)&c2;
	((SickCow*)c3)->Speak();
	c1.Speak(); c1.Eat(); c1.Eat(); c2.Speak(); c2.TakeMed(); c2.TakeMed();
	return 0;
}
