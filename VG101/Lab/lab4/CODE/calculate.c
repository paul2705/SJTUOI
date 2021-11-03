#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"calculate.h"

int interpret(char c){
	switch (c){
		case '^': return 3;
		case '*': return 2;
		case '/': return 2;
		case '+': return 1;
		case '-': return 1;
		case '(': return 0;
		case ')': return 0;
//		case ' ': return 8;
	}
	return -1;
}

stg convert(stg s){
	stg ret,stp;
	strcpy(ret.s,"");
	strcpy(stp.s,"");
	stkc st[505];
	int top=0;
	for (int i=0;i<=500;i++) st[i].c='@',st[i].ord=0;
//	printf("%s\n",s.s);
	int n=strlen(s.s);
	int now=0;
	for (;now<n;){
		double tmp=0;
		int fg=0;
		int inv=1;
		if (s.s[now]=='-') now++,inv=-1;
		while (s.s[now]>='0'&&s.s[now]<='9'){
			tmp=tmp*10+s.s[now]-'0';
			now++;
			fg=1;
		}
		if (s.s[now]=='.'){
			now++; double tmp1=10;
			while (s.s[now]>='0'&&s.s[now]<='9'){
//				printf("%lf\n",tmp);
				tmp+=(double)(s.s[now]-'0')/tmp1;
				tmp1*=10; now++;
			}
		}
//		printf("now: %d %d\n",now,interpret(s.s[now]));
		if (fg){
			sprintf(stp.s,"%lf@",inv*tmp);
			strcat(ret.s,stp.s);
		}
		while (interpret(s.s[now])>=0){
//			printf("tmp: %c\n",s.s[now]);
			if ((s.s[now-1]<'0'||s.s[now-1]>'9')&&s.s[now]=='-'&&s.s[now+1]>='0'&&s.s[now+1]<='9') break;
			int ord=interpret(s.s[now]);
//			if (s.s[now]==' '){
//				now++;
//				continue;
//			}
			switch (s.s[now]){
				case '(': st[++top].c=s.s[now]; st[top].ord=ord; break;
				case ')': while (top>0&&st[top].c!='('){
							  sprintf(stp.s,"%c",st[top--].c);
							  strcat(ret.s,stp.s);
						  }
						  top--;
						  break;
				default:  while (top>0&&st[top].ord>=ord){
							  sprintf(stp.s,"%c",st[top--].c);
							  strcat(ret.s,stp.s);
						  }
						  st[++top].c=s.s[now]; st[top].ord=ord;
						  break;
			}
			now++;
		}
//		printf("FUCK\n");
	}
//	printf("FUCK\n");
	while (top>0){
		sprintf(stp.s,"%c",st[top--].c);
		strcat(ret.s,stp.s);
	}
	return ret;
}

double value(stg s){
	stkv st[505];
//	printf("%s\n",s.s);
	int top=0;
	int n=strlen(s.s);
	int now=0;
	for (;now<n;){
//		printf("now: %d\n",now);
		double tmp=0;
		int fg=0;
		int inv=1;
		if (s.s[now]=='-') now++,inv=-1;
		while (s.s[now]!='.'&&s.s[now]!='@'){
			tmp=tmp*10+s.s[now]-'0';
			now++; fg=1;
		}
		if (s.s[now]=='.'){
			double tmp1=10;
			now++;
			while (s.s[now]!='@'){
				tmp+=(double)(s.s[now]-'0')/tmp1;
				tmp1*=10; now++;
			}
		}
//		printf("%lf\n",tmp);
		if (fg){
			st[++top].val=inv*tmp;
			now++;
		}
		while (interpret(s.s[now])>0){
			if ((s.s[now-1]<'0'||s.s[now-1]>'9')&&s.s[now]=='-'&&s.s[now+1]>='0'&&s.s[now+1]<='9') break;
//			printf("%c %d\n",s.s[now],top);
//			if (s.s[now]==' '){
//				now++;
//				continue;
//			}
			switch (s.s[now]){
				case '+': st[top-1].val+=st[top].val; top--; break;
				case '-': st[top-1].val-=st[top].val; top--; break;
				case '*': st[top-1].val*=st[top].val; top--; break;
				case '^': st[top-1].val=pow(st[top-1].val,st[top].val); top--; break;
				case '/': st[top-1].val/=st[top].val; top--; break;
			}
			now++;
		}
	}
	//printf("%d\n",st[top].val);
	return st[top].val;
}

double getvalue(stg exp){
//	printf("FAQ\n");
	stg s;
	for (int i=0;i<200;i++) s.s[i]='\0';
	int cnt=0,n=strlen(exp.s);
	for (int i=0;i<n;i++){
		if (exp.s[i]==' ') continue;
		s.s[cnt++]=exp.s[i];
	}
	stg tmp=convert(s);
//	printf("FAQ\n");
	printf("%s\n",tmp.s);
	return value(convert(s));
}

int main(){
	stg s; scanf("%[^\n]%*c",s.s);
	printf("%lf\n",getvalue(s));
	return 0;
}
