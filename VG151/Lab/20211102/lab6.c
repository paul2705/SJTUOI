#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
int get_winner(int x,int y,double rate){
	double tmp1=rand()%1000;
	double tmp2=rand()%(1000-(int)tmp1)+tmp1+1;
	return tmp1/tmp2<rate?x:y;
}
int main(){
	struct rec{
		double rate;
		int survive;
		char country[5];
	} a[50];
	for (int i=1;i<=16;i++){
		scanf("%s%lf",a[i].country,&a[i].rate);
		a[i].survive=1;
	}
	srand((unsigned)time(NULL));
	for (int i=1;i<=10000;i++){
		int x=rand()%16+1,y=rand()%16+1;
		struct rec tmp=a[x]; a[x]=a[y]; a[y]=tmp;	
	}
	for (int i=1;i<=4;i++){
		int pre=0;
		for (int j=1;j<=16;j++){
			if (a[j].survive<i) continue;
			if (pre==0) pre=j;
			else {
				double tmp=rand()%50;
				double rt=(a[j].rate+tmp)/(a[j].rate+a[pre].rate+2*tmp);
				int win=get_winner(pre,j,rt);
				int los=pre+j-win;
				a[win].survive=i+1; a[los].survive=i;
				printf("%s WIN %s\n",a[win].country,a[los].country);
				pre=0;
			}
		}
		printf("\n");
	}
	for (int i=1;i<=5;i++){
		char blank[35]={};
		switch (i){
			case 1: 
				printf("First: "); 
				strcpy(blank,""); 
				break;
			case 2: 
				printf("Quart: "); 
				strcpy(blank,"  "); 
				break;
			case 3: 
				printf("Half : "); 
				strcpy(blank,"      "); 
				break;
			case 4: 
				printf("Final: "); 
				strcpy(blank,"              "); 
				break;
			case 5: 
				printf("WINNER: "); 
				strcpy(blank,"                             "); 
				break;
		}
		for (int j=1;j<=16;j++){
			if (a[j].survive<i) continue;
			printf("%s%s%s ",blank,a[j].country,blank);
		}
		printf("\n");
	}
	
	return 0;
}
