#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>

void delspace(char *str)
{
    char *p = str; 
    char *t = p;
    while (*p != '\0')
    {
        if (*p == ' ')
        {
            t++;
            if (*t != ' ')
            {
                *p = *t;
                *t = ' ';
            }
        }
        else
        {
            p++;
            t = p;
        }
    }
}

double calc(char *str)
{
    delspace(str);
    char new[800] = {'\0'};
    int l = strlen(str);
    double stack[120] = {0.0};
    int top = 0;
    char s, t;
    for (int i = 0; i < l; i++)
    {
        if ((i == 0 || str[i - 1] < '0' || str[i - 1] > '9') && str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
        {
            sprintf(new, "%s -", new);
        }
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (str[i + 1] == '(' || str[i + 1] == ')' || str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == '^')
                sprintf(new, "%s%c ", new, str[i]);
            else if (str[i - 1] == '.')
                sprintf(new, "%s%c", new, str[i]);
            else if (str[i - 1] == '-')
                sprintf(new, "%s%c", new, str[i]);
            else
                sprintf(new, "%s%c", new, str[i]);
        }
        if (str[i] == '.')
            sprintf(new, "%s%c", new, str[i]);
        if (str[i] == '(')
            stack[top++] = str[i];
        if (str[i] == '^'){
            if (stack[top - 1] == '^')
                sprintf(new, "%s %c ", new, (char)stack[--top]);
            stack[top++] = str[i];
        }    
        if (str[i] == '*' || str[i] == '/')
        {
            if (stack[top - 1] == '^')
                sprintf(new, "%s %c ", new, (char)stack[--top]);
            if (stack[top - 1] == '*' || stack[top - 1] == '/')
                sprintf(new, "%s %c ", new, (char)stack[--top]);
            stack[top++] = str[i];
        }
        if (str[i] == '+')
        {
            if (stack[top - 1] == '^')
                sprintf(new, "%s %c ", new, (char)stack[--top]);
            if (stack[top - 1] == '*' || stack[top - 1] == '/')
                sprintf(new, "%s %c ", new, (char)stack[--top]);
            if (stack[top - 1] == '+' || stack[top - 1] == '-')
                sprintf(new, "%s %c ", new, (char)stack[--top]);
            stack[top++] = str[i];
            //			printf("IN\n");
        }
        if (((i > 0 && str[i - 1] >= '0' && str[i - 1] <= '9') || (str[i-1]==')')) && str[i] == '-')
        {
            if (stack[top - 1] == '^')
                sprintf(new, "%s %c ", new, (char)stack[--top]);
            if (stack[top - 1] == '*' || stack[top - 1] == '/')
                sprintf(new, "%s %c ", new, (char)stack[--top]);
            if (stack[top - 1] == '+' || stack[top - 1] == '-')
                sprintf(new, "%s %c ", new, (char)stack[--top]);
            stack[top++] = str[i];
        }
        if (str[i] == ')')
        {
            for (int i = 0; i < 120; i++)
            {
                if (stack[top - 1] == '(')
                {
                    stack[--top];
                    break;
                }
                sprintf(new, "%s %c ", new, (char)stack[--top]);    
            }
        }
    }
    while (top > 0)
    {
        sprintf(new, "%s %c", new, (char)stack[--top]);
    }
    //printf("%s\n",new);


    int l1 = strlen(new);
    int helper[800] = {0};
    for (int i = 0; i < l1; i++)
    {
        if (new[i] == '+' || new[i] == '-' || new[i] == '*' || new[i] == '/' || new[i] == '^')
            helper[i] = 2;
        else if (new[i] == ' ')
            continue;
        else
            helper[i] = 1;
        if (new[i] == '-' && new[i + 1] >= '0' && new[i + 1] <= '9')
            helper[i] = 1;
    }
    //for (int i=0;i<l1;i++) printf("%d",helper[i]);
    //printf("\n");
    double stack1[800] = {0.0};
    int top1 = 0;
    char op[5]={'\0'};
    char tmp[20]={'\0'};
    double a, b, ans = 0;
    for (int i = 0; i < l1; i++)
    {
        if (helper[i] == 0)
            continue;
        if (helper[i] == 1)
        {
            sprintf(tmp, "%s%c", tmp, new[i]);
            if (helper[i + 1] == 0)
            {
                stack1[top1++] = atof(tmp);
                int lt = strlen(tmp);
                for (int i = 0; i < lt; i++)
                    tmp[i] = 0;
                continue;
            }
        }
        if (helper[i] == 2)
        {
            sprintf(op, "%c", new[i]);
            a = stack1[--top1];
            b = stack1[--top1];

            if (op[0] == '+')
                ans = a + b;
            if (op[0] == '-')
                ans = b - a;
            if (op[0] == '*')
                ans = a * b;
            if (op[0] == '/')
                ans = b / a;
            if (op[0] == '^')
                ans = pow(b, a);
                //printf("%f %f %f\n",b,a,ans);
            stack1[top1++] = ans;
        }
    }
    return stack1[--top1];
}

typedef struct _var
{
    char *name;
    double value;
} var;

void s_print(char *fmt, ...)
{
    char *str;
    double i;
    va_list arg;
    va_start(arg, fmt);
    for (str = fmt; *str != '\0'; str++)
    {
        while (*str != '%')
        {
            if (*str == '\0')
            {
                va_end(arg);
                return;
            }
            if (*str == '\\')
            {
                while (*str == '\\')
                {
                    str += 2;
                    putchar('\n');
                }
            }
            else
            {
                putchar(*str); //Print this char
                str++;
            }
        }
        str++;
        switch (*str)
        {         //Different types
        case 'f': //float
            i = va_arg(arg, double);
            printf("%lf", i);
            break;
        }
    }
    va_end(arg);
}

void strReplace(char *str, char *strin, char *strout, char *out)
{
    char *p;
    int insize = strlen(strin);
    int outsize = strlen(strout);
    int len = 0;
    do
    {
        p = strstr(str, strin);
        if (p == 0)
        {
            strcpy(out, str);
            return;
        }
        len = p - str;
        memcpy(out, str, len);
        memcpy(out + len, strout, outsize);
        str = p + insize;
        out = out + len + outsize;

    } while (p);
}

double calcExp(var *myvar, int vartop, char *expr)
{
    char *p = expr;
    int isVarscan = 0;
    char temp[22] = {0};
    int curpos = 0;
    while (*p != '\0')
    {
        if ((*p >= 48 && *p <= 57) || (*p >= 65 && *p <= 90) || (*p >= 97 && *p <= 122))
        {
            //Valid
            isVarscan = 1;
            temp[curpos] = *p;
            curpos++;
        }
        else
        {
            if (isVarscan)
            {
                for (int i = 0; i <= vartop; ++i)
                    if (strcmp(myvar[i].name, temp) == 0)
                    {
                        char extemp[120];
                        char tt[120];
                        sprintf(extemp, "%lf", myvar[i].value);
                        //printf("-%s-\n",extemp);
                        strReplace(expr, temp, extemp, tt);
                        strcpy(expr, tt);
                        break;
                    }
            }
            memset(temp, 0, sizeof(temp));
            curpos = 0;
            isVarscan = 0;
        }
        p++;
    }
    if (isVarscan)
    {
        for (int i = 0; i <= vartop; ++i)
            if (strcmp(myvar[i].name, temp) == 0)
            {
                char extemp[120];
                char tt[120];
                sprintf(extemp, "%lf", myvar[i].value);
                strReplace(expr, temp, extemp, tt);
                strcpy(expr, tt);
                break;
            }
    }
    return calc(expr);
}

//double assg(char *str)

int main()
{
    FILE *fp;
    char str[120];
    //fp = fopen("C:\\UM-SJTU JI\\VG101\\Lab\\Lab4\\commands.txt", "r");
    fp = fopen("./commands.txt", "r");
    setbuf(stdout, NULL);
    var myVar[22];
    int varTop = -1;

    //Initialize
    for (int i = 0; i <= 21; ++i)
    {
        myVar[i].name = (char *)malloc(sizeof(char) * 12);
    }

    while (fgets(str, 120, fp) != NULL)
    {
        char command[120]={0};
        strcpy(command,str);
        char c;
        //Decide sentence type
        char *p = command;
        int type = 0;
        int epos = 0;
        int ifoutput = 1;
        char temp[10] = {0};
        /*
        Type:
        1.give =
        2.fprintf
        3.direct calculation
        */

        while (*p != '\0')
        {
            if (*p == '=')
            {
                type = 1;
                break;
            }
            p++;
            epos++;
        }
        p = command;
        while (*p != '\0')
        {
            if (*p == ';')
            {
                ifoutput = 0;
                break;
            }
            p++;
        }
        strncpy(temp, command, 8);
        if (strcmp(temp, "fprintf(") == 0)
            type = 2;
        if (type == 1)
        {
            //Give value to variables
            char cvarname[11] = {0};
            char optpar[120] = {0};
            int ifexist = 0;

            sscanf(command, "%[^=]=%[^=;]", cvarname, optpar);
            double res = calcExp(myVar, varTop, optpar);
            //Save variables
            for (int i = 0; i <= varTop; ++i)
            {
                //Check if it exists
                if (strcmp(myVar[i].name, cvarname) == 0)
                {
                    ifexist = 1;
                    myVar[i].value = res;
                }
            }
            if (!ifexist)
            {
                //New one
                varTop++;
                strcpy(myVar[varTop].name, cvarname);
                myVar[varTop].value = res;
            }
            if (ifoutput)
            {
                //Output this
                printf("%lf\n", res);
            }
        }
        if (type == 2)
        {
            //fprintf
            char optpar[120] = {0};
            p = command;
            int ifcomma = 0;
            sscanf(command, "%*[^\"]\"%[^\"]\"", optpar);
            while (*p != '\0')
            {
                if (*p == ',')
                    ifcomma = 1;
                p++;
            }
            if (ifcomma)
            {
                char expr[120] = {0};
                sscanf(command, "%*[^,],%[^)])", expr);
                s_print(optpar, calcExp(myVar, varTop, expr));
            }
            else
            {
                s_print(optpar);
            }
        }
        if (type == 0)
        {
            //Direct calculation
            if (ifoutput)
                printf("%lf\n", calcExp(myVar, varTop, command));
        }
    }
fclose(fp);
return 0;
}
