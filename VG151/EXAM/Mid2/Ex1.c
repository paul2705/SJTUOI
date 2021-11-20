#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "Ex1.h"
char *Interpret(int x,int y){
	if (x==1){
		switch (y){
			case 1: return "Butcher";
			case 2: return "Hairdresser";
			case 3: return "Salesman";
			case 4: return "Banker";
			case 5: return "Student";
		}
	}
	else if (x==2){
		switch (y){
			case 1: return "Lounge";
			case 2: return "Lobby";
			case 3: return "Reception";
			case 4: return "Restaurant";
			case 5: return "Coffee shop";
		}
	}
	else {
		switch (y){
			case 1: return "Hammer";
			case 2: return "Fork";
			case 3: return "Knife";
			case 4: return "Poison";
			case 5: return "Candlestick";
		}
	}
	return "~";
}
int check(Murderer x,Murderer y){
	int cnt=(x.Suspects==y.Suspects);
	cnt+=(x.Locations==y.Locations);
	cnt+=(x.Weapons==y.Weapons);
	return cnt;
}
int main(){
	srand((time_t)time(NULL));
	Murderer Ans={rand()%5+1,rand()%5+1,rand()%5+1};
	Murderer *Guess=malloc(1*sizeof(Murderer));
	printf("Lady Janis has been killed at the Carlton Mansion. Will you discover the murderer?\n");
	int i=1;
	for (;i<=10;i++){
		printf("* Round %d\n",i);
		printf("  Suspects: 1. Butcher 2. Hairdresser 3. Salesman 4. Banker 5. Student\n");
		printf("  Locations: 1. Lounge 2. Lobby 3. Reception 4. Restaurant 5. Coffee shop\n");
		printf("  Weapons: 1. Hammer 2. Fork 3. Knife 4. Poison 5. Candlestick\n");
		printf("  Select a suspect, a location, and a weapon: ");
		Murderer tmp; if (scanf("%d%d%d",&tmp.Suspects,&tmp.Locations,&tmp.Weapons)){}
		printf("  You suspect the %s to have killed Janis in the %s using a %s\n",Interpret(1,tmp.Suspects),Interpret(2,tmp.Locations),Interpret(3,tmp.Weapons));
		int cnt=check(tmp,Ans);
		printf("  You made %d correct guess(es)\n",cnt);
		Guess=realloc(Guess,(size_t)i*sizeof(Murderer));
		Guess[i-1]=tmp;
		if (cnt==3){
			printf("Congratulations, you solved the case using the following sequence:\n");
			break;
		}
	}
	if (i>10) printf("Game over, you failed to solve the case using the following sequence:\n");
	for (int j=0;j<fmin(i,10);j++) printf("  %d. You suspect the %s to have killed Janis in the %s using a %s\n",j+1,Interpret(1,Guess[j].Suspects),Interpret(2,Guess[j].Locations),Interpret(3,Guess[j].Weapons));
	printf("Conclusion: the %s to have killed Janis in the %s using a %s\n",Interpret(1,Ans.Suspects),Interpret(2,Ans.Locations),Interpret(3,Ans.Weapons));
	free(Guess);
	return 0;
}
