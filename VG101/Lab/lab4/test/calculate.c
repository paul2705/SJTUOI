#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "calculate.h"

int interpret(char c)
{
    switch (c)
    {
    case '^':
        return 3;
    case '*':
        return 2;
    case '/':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    case '(':
        return 0;
    case ')':
        return 0;
    }
    return -1;
}

stg convert(stg s)
{
    stg ret, stp;
    strcpy(ret.s, "");
    strcpy(stp.s, "");
    stkc st[505];
    int top = 0;
    for (int i = 0; i <= 500; i++)
        st[i].c = '@', st[i].ord = 0;
    int n = strlen(s.s);
    int now = 0;
    for (; now < n;)
    {
        double tmp = 0;
        int fg = 0;
        while (s.s[now] >= '0' && s.s[now] <= '9')
        {
            tmp = tmp * 10 + s.s[now] - '0';
            now++;
            fg = 1;
        }
        if (s.s[now] == '.')
        {
            now++;
            double tmp1 = 10;
            while (s.s[now] >= '0' && s.s[now] <= '9')
            {
                tmp += (double)(s.s[now] - '0') / tmp1;
                tmp1 *= 10;
                now++;
            }
        }
        if (fg)
        {
            sprintf(stp.s, "%lf@", tmp);
            strcat(ret.s, stp.s);
        }
        while (interpret(s.s[now]) >= 0)
        {
            int ord = interpret(s.s[now]);
            switch (s.s[now])
            {
            case '(':
                st[++top].c = s.s[now];
                st[top].ord = ord;
                break;
            case ')':
                while (top > 0 && st[top].c != '(')
                {
                    sprintf(stp.s, "%c", st[top--].c);
                    strcat(ret.s, stp.s);
                }
                top--;
                break;
            default:
                while (top > 0 && st[top].ord >= ord)
                {
                    sprintf(stp.s, "%c", st[top--].c);
                    strcat(ret.s, stp.s);
                }
                st[++top].c = s.s[now];
                st[top].ord = ord;
                break;
            }
            now++;
        }
    }
    while (top > 0)
    {
        sprintf(stp.s, "%c", st[top--].c);
        strcat(ret.s, stp.s);
    }
    return ret;
}

double value(stg s)
{
    stkv st[505];
    int top = 0;
    int n = strlen(s.s);
    int now = 0;
    for (; now < n;)
    {
        double tmp = 0;
        int fg = 0;
        while (s.s[now] != '.' && s.s[now] != '@')
        {
            tmp = tmp * 10 + s.s[now] - '0';
            now++;
            fg = 1;
        }
        if (s.s[now] == '.')
        {
            double tmp1 = 10;
            now++;
            while (s.s[now] != '@')
            {
                tmp += (double)(s.s[now] - '0') / tmp1;
                tmp1 *= 10;
                now++;
            }
        }
        if (fg)
        {
            st[++top].val = tmp;
            now++;
        }
        while (interpret(s.s[now]) > 0)
        {
            switch (s.s[now])
            {
            case '+':
                st[top - 1].val += st[top].val;
                top--;
                break;
            case '-':
                st[top - 1].val -= st[top].val;
                top--;
                break;
            case '*':
                st[top - 1].val *= st[top].val;
                top--;
                break;
            case '^':
                st[top - 1].val = pow(st[top - 1].val, st[top].val);
                top--;
                break;
            case '/':
                st[top - 1].val /= st[top].val;
                top--;
                break;
            }
            now++;
        }
    }
    return st[top].val;
}

double getvalue(stg s)
{
    return value(convert(s));
}
