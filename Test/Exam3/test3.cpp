#include <iostream>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

using namespace std;

typedef int SElemType;
typedef int Status;

typedef struct
{
    SElemType *base;
    SElemType *top;
} SqStack;

Status Push(SqStack &S, int e);

Status Pop(SqStack &S, SElemType &e);

Status InitStack(SqStack &S);

Status Judge(SqStack S);

int main()
{
    int n, e;
    SqStack A;
    InitStack(A);
    cin >> n;
    while (n)
    {
        Push(A, n % 8);
        n /= 8;
    }
    while (Judge(A))
    {
        Pop(A, e);
        cout << e;
    }
    return 0;
}

Status InitStack(SqStack &S)
{
    S.base = new SElemType[MAXSIZE];
    if (!S.base)
    {
        exit(OVERFLOW);
    }
    S.top = S.base;
    return OK;
}

Status Pop(SqStack &S, SElemType &e)
{
    if (S.top == S.base)
    {
        return ERROR;
    }
    e = *--S.top;
    return OK;
}

Status Push(SqStack &S, int e)
{
    if (S.top - S.base == MAXSIZE)
    {
        return ERROR;
    }
    *S.top++ = e;
    return OK;
}

Status Judge(SqStack S)
{
    if (S.top != S.base)
    {
        return 1;
    }
    return 0;
}