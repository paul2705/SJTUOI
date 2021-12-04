#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<ctime>

#include"Parklot.h"
#include"Slot.h"
#include"Ticket.h"

#include"Van.h"
#include"Vehicle.h"

#include"System.h"
#include"Sys.h"
using namespace std;

int main(){
	srand((unsigned int)time(NULL));
	System my;
	while (!my.IsEmpty()){
		int opt=rand()%5;
		if (opt<3) my.AskVehIn(my.TimeFlow());
		else my.AskVehOut(my.TimeFlow());
		PauseScreen(100);
	}
	return 0;
}
