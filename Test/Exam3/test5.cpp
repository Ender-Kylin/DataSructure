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
    char s;
    int StackSize; // 栈最大容量
} SqStack;

Status Push(SqStack &S, SElemType e);

Status Pop(SqStack &S, SElemType &e);

Status InitStack(SqStack &S);

void move(int n, SqStack &A, SqStack &B, SqStack &C);

int main()
{
    int n;
    SqStack A, B, C;
    cin >> n;
    InitStack(A);
    InitStack(B);
    InitStack(C);
    for (int i = 0; i < n; i++)
    {
        Push(A, 3 - i);
    }
    A.s = 'A';
    B.s = 'B';
    C.s = 'C';
    move(n, A, B, C);
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
Status Pop(SqStack &S, SElemType &e)
{
    if (S.top == S.base)
    {
        return ERROR;
    }
    e = *--S.top;
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

void move(int n, SqStack &A, SqStack &B, SqStack &C)
{
    static int num = 1;
    int e;
    if (n == 1)
    {
        Pop(A, e);
        Push(C, e);
        cout << num++ << ": " << e << " " << A.s << " " << C.s << endl;
        return;
    }
    else
    {
        move(n - 1, A, C, B); // 将 n-1 从 A 移到 B(借助 C)
        Pop(A, e);            // 移动当前层元素
        Push(C, e);
        cout << num++ << ": " << e << " " << A.s << " " << C.s << endl;
        move(n - 1, B, A, C); // 将 n-1 从 B 移到 C(借助 A)
        return;
    }
}