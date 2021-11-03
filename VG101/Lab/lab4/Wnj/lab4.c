#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void delspace(char *str)
{
    char *p=str;
    char *t=p;
    while (*p!='\0') 
    {
        if (*p==' ')  
        {
            t++;
            if (*t!=' ') 
            {
                *p=*t;
                *t=' ';
            }
        }
        else
        {
            p++;
            t=p;
        }
    }
}

double calc(char *str)
{
    char new[800]={0.0};
    int l=strlen(str);
    double stack[120]={0.0};
    int top=0; 
    char s, t;
    for (int i=0;i<l;i++)
    {
        if ((i==0||str[i-1]<'0'||str[i-1]>'9')&&str[i]=='-'&&str[i+1]>='0'&&str[i+1]<='9'){
			printf("IN\n");
			sprintf(new,"%s -",new);
		}
        if (str[i]>='0'&&str[i]<='9') 
        {
            if (str[i+1]=='('||str[i+1]==')'||str[i+1]=='+'||str[i+1]=='-'||str[i+1]=='*'||str[i+1]=='/'||str[i+1]=='^') 
                sprintf(new,"%s%c ",new,str[i]); 
            else if (str[i-1]=='.')
                sprintf(new,"%s%c",new,str[i]); 
            else if (str[i-1]=='-')
                sprintf(new,"%s%c",new,str[i]);
			else sprintf(new,"%s %c",new,str[i]);
        }
        if (str[i]=='.') sprintf(new,"%s%c",new,str[i]);
        if (str[i]=='(') stack[top++]=str[i];
        if (str[i]=='^') stack[top++]=str[i];
        if (str[i]=='*'||str[i]=='/')
        {
            if (stack[top-1]=='^') sprintf(new,"%s %c ",new,(char)stack[--top]);
            stack[top++]=str[i];
        }
        if (str[i]=='+')
        {
            if (stack[top-1]=='^') sprintf(new,"%s %c ",new,(char)stack[--top]);
            if (stack[top-1]=='*'||stack[top-1]=='/') sprintf(new,"%s %c ",new,(char)stack[--top]);
            stack[top++]=str[i];
//			printf("IN\n");
		}
        if ((i>0&&str[i-1]>='0'&&str[i-1]<='9')&&str[i]=='-'&&str[i+1]>='0'&&str[i+1]<='9')
        {
            if (stack[top-1]=='^') sprintf(new,"%s %c ",new,(char)stack[--top]);
            if (stack[top-1]=='*'||stack[top-1]=='/') sprintf(new,"%s %c ",new,(char)stack[--top]);
            stack[top++]=str[i];
        }
        if (str[i]==')')
        {
            for (int i=0;i<120;i++) 
            {
                sprintf(new,"%s %c ",new,(char)stack[--top]);
                if (stack[top-1]=='(')
                {
                    stack[--top];
                    break;
                }  
            }
        }
    }
    while (top>0)
    {
        sprintf(new,"%s %c",new,(char)stack[--top]);
    }
	printf("%s\n",new);
	int l1=strlen(new);
    int helper[800]={0};
    for (int i=0;i<l1;i++)
    {
        if (new[i]=='+'||new[i]=='-'||new[i]=='*'||new[i]=='/'||new[i]=='^') helper[i]=2;
        else if (new[i]==' ') continue;
        else helper[i]=1;
		if (new[i]=='-'&&new[i+1]>='0'&&new[i+1]<='9') helper[i]=1;
	}
    double stack1[800]={0.0};
    int top1=0;
    char op[5];
    char tmp[20];
    double a,b,ans=0;
    for (int i=0;i<l1;i++)
    {
        if (helper[i]==0) continue;
        if (helper[i]==1) 
        {
            sprintf(tmp,"%s%c",tmp,new[i]);
            if (helper[i+1]==0)
            {
                stack1[top++]=atof(tmp);
                int lt=strlen(tmp);
                for (int i=0;i<lt;i++) tmp[i]=0;
                continue;
            } 
        }
        if (helper[i]==2)
        {
            sprintf(op,"%c",new[i]);
            a=stack1[--top];
            b=stack1[--top];
           
            if (op[0]=='+') ans=a+b;
            if (op[0]=='-') ans=b-a;
            if (op[0]=='*') ans=a*b;
            if (op[0]=='/') ans=b/a;
            if (op[0]=='^') ans=pow(b,a);
            stack1[top++]=ans;
        }
    }
    return stack1[--top];
}

int main()
{
    FILE *fp;
    char str[120];
//    fp=fopen("C:\\UM-SJTU JI\\VG101\\Lab\\Lab4\\commands.txt","r");
    while(gets(str) != NULL)
    {
        delspace(str);
        printf("%lf\n",calc(str));
    }
    fclose(fp);
    return 0;  
}
