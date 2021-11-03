#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SWAP(a,b){ a^=b; b^=a; a^=b; }
unsigned long int mult(unsigned long int a, unsigned long int b); // claim the function mult
//#define TEST
int getnum(unsigned long int x,int l,int r);
int main(){
	unsigned long int a,b; // define input a,b
	srand(time(NULL)); // randomize
	#ifndef TEST
		a=rand(); b=rand(); // random the two numbers a,b
		printf("%ld*%ld=%ld %d\n",a,b,mult(a,b),RAND_MAX); // do the multiply and output the answer
	#endif
	#ifdef TEST
		// int i; Could delete this line and put i into for
		for (int i=0;i<1000000;i++){ // 对拍
			a=rand(); b=rand(); 
			if(mult(a,b)!=a*b){ // test if the algorithm is designed wrongly
				fprintf(stderr,"Error (%d): a=%ld, b=%ld, a*b=%ld, k(a,b)=%ld\n",i,a,b,a*b,mult(a,b)); // output the ERROR
				exit(-1); 
			}
		}
	#endif
}
int getnum(unsigned long int x,int l,int r){
	if (l==r) return l;
	if (l==r-1) return (x>>r)&1?r:l;
	int mid=(l+r)/2;
	if (x>=(1ll<<mid)) return getnum(x,mid,r);
	else return getnum(x,l,mid-1);
}

unsigned long int mult(unsigned long int a, unsigned long int b){ // the algorithm with two inputs
	int i,n,N;
	unsigned long int x0,y0,z0,z1=1;
	if (a<b) SWAP(a,b); // make sure a is greater than b
	if (b==0) return 0; // declare the end of the recursion
	//for (n=-1,i=1;i<=b;i<<=1,n++); /* not optimal */ 
	n=getnum(b,0,32); N=getnum(a,0,32);
	//for (N=n;i<=a;i<<=1,N++);
	y0=b&((1<<n)-1); // split the number b by approximately divided 2
	x0=a&((1<<N)-1); // split the number a by approximately divided 2
	z0=mult(x0,y0); // recall the function mult(a,b) with a smaller but similar problem
	i=N+n;
	return ((z1<<i)+(x0<<n)+(y0<<N)+z0); // calculate the answer
}
