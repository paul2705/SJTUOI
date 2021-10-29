#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double evaluate(int a,char opt,int b){
	switch (opt){
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return (double)a/b;
		case '^': { 
				  int tmp=1;
				  for (int i=1;i<=b;i++) tmp*=a;
				  return tmp; }
		case 'l': return log(b)/log(a);
		case 'm': return a%b;
	}
	return -1;
}

