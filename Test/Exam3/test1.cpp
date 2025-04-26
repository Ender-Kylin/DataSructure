#include <iostream>
#include <stdlib.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

using namespace std;

typedef int SElemType;
typedef int Status;

typedef struct
{
    SElemType *base; // 栈底指针
    SElemType *top;  // 栈顶指针
    int StackSize;   // 栈最大容量
} SqStack;

// 顺序栈的初始化
Status InitStack(SqStack &S);

// 入栈
Status Push(SqStack &S, SElemType e);

// 出栈
Status Pop(SqStack &S, SElemType &e);

// 判断是否为空
Status Judge(SqStack S);

// 打印
void Print(SqStack S);

int main()
{
    int n, e;
    SqStack A;
    InitStack(A);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        Push(A, e);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Pop(A, e);
    }
    if (Judge(A))
    {
        cout << "N" << endl
             << *(A.top - 1) << endl;
        Print(A);
    }
    else
    {
        cout << "Y";
    }
    return 0;
}

Status InitStack(SqStack &S)
{
    S.base = new SElemType[MAXSIZE];
    if (!S.base)
    {
        exit(OVERFLOW); // 分配失败
    }
    S.top = S.base;        // top初始化为base,空栈
    S.StackSize = MAXSIZE; // 最大容量
    return OK;
}

Status Push(SqStack &S, SElemType e)
{
    if (S.top - S.base == S.StackSize)
    {
        return ERROR;
    }
    *S.top++ = e;
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

Status Judge(SqStack S)
{
    if (S.top != S.base)
    {
        return 1;
    }
    return 0;
}

void Print(SqStack S)
{
    if (S.top != S.base)
    {
        for (int i = 0; S.top != S.base + i; i++)
        {
            cout << *(S.base + i) << " ";
        }
    }
}