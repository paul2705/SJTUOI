#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char str[120];
    char new[800]={0.0};
    scanf("%s",str);
    int l=strlen(str);
    double stack[120]={0.0};
    int top=0; 
    char s, t;
    for (int i=0;i<l;i++)
    {
        if (str[i]>='0'&&str[i]<='9') 
        { 
            if (str[i+1]=='('||str[i+1]==')'||str[i+1]=='+'||str[i+1]=='-'||str[i+1]=='*'||str[i+1]=='/'||str[i+1]=='^') 
                sprintf(new,"%s%c ",new,str[i]); 
            else if (str[i-1]=='.')
                sprintf(new,"%s%c",new,str[i]); 
            else 
                sprintf(new,"%s %c",new,str[i]);
        }
        if (str[i]=='.') sprintf(new,"%s%c",new,str[i]);
        if (str[i]=='(') stack[top++]=str[i];
        if (str[i]=='^') stack[top++]=str[i];
        if (str[i]=='*'||str[i]=='/')
        {
            if (stack[top-1]=='^') sprintf(new,"%s %c ",new,(char)stack[--top]);
            stack[top++]=str[i];
        }
        if (str[i]=='+'||str[i]=='-')
        {
            if (stack[top-1]=='^') sprintf(new,"%s %c ",new,(char)stack[--top]);
            if (stack[top-1]=='*'||stack[top-1]=='/') sprintf(new,"%s %c ",new,(char)stack[--top]);
            stack[top++]=str[i];
        }
        if (str[i]==')')
        {
            for (int i=0;i<120;i++) 
            {
                sprintf(new,"%s %c",new,(char)stack[--top]);
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
    for (int i=0;i<l1;i++) //获得helper数组
    {
        if (new[i]=='+'||new[i]=='-'||new[i]=='*'||new[i]=='/'||new[i]=='^') helper[i]=2;
        else if (new[i]==' ') continue;
        else helper[i]=1;
    }
    for (int i=0;i<l1;i++) printf("%d",helper[i]);
    printf("\n");
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
            //printf("%s\n",tmp);
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
            //printf("%f %f\n",a,b);
            if (op[0]=='+') ans=b+a;
            if (op[0]=='-') ans=b-a;
            if (op[0]=='*') ans=b*a;
            if (op[0]=='/') ans=b/a;
            if (op[0]=='^') ans=pow(b,a);
            stack1[top++]=ans;
        }
    }
    printf("%lf",stack1[--top]);

    
    


    return 0;
}
