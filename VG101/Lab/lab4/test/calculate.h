#ifndef _CALCULATE_H_
#define _CALCULATE_H_

typedef struct _stkc
{
    char c;
    int ord;
} stkc;
typedef struct _stkv
{
    double val;
} stkv;
typedef struct _stg
{
    char s[505];
} stg;

stg convert(stg s);
double getvalue(stg s);
double value(stg s);
int interpret(char c);

#endif
