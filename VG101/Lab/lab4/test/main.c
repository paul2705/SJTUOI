#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "calculate.h"
// Stack exercise

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
    char temp[22] = {};
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
    stg t;
    strcpy(t.s, expr);
    return getvalue(t);
}

int main()
{
    setbuf(stdout, NULL);
    var myVar[22];
    int varTop = -1;

    //Initialize
    for (int i = 0; i <= 21; ++i)
    {
        myVar[i].name = (char *)malloc(sizeof(char) * 12);
    }

    while (1)
    {
        char command[120]={};
        char c;
        int cindex=0;
        do{
            c=getchar();
            command[cindex++]=c;
        }while(c!='\n');
        command[cindex-1]='\0';
        if(cindex==1) continue;
        //Decide sentence type
        char *p = command;
        int type = 0;
        int epos = 0;
        int ifoutput = 1;
        char temp[10] = {};
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
            char cvarname[11] = {};
            char optpar[120] = {};
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
            char optpar[120] = {};
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
                char expr[120] = {};
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
    return 0;
}