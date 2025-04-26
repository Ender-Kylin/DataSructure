#include <iostream>
#include <stdlib.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

using namespace std;

typedef int QElemType;
typedef int Status;

typedef struct
{
    QElemType *base;
    int front;
    int rear;
} SqQueue;

// 初始化
Status InitQueue(SqQueue &Q)
{
    Q.base = new QElemType[MAXSIZE];
    if (!Q.base)
        exit(OVERFLOW);
    Q.front = Q.rear = 0;
    return OK;
}

// 入队
Status EnQueue(SqQueue &Q, QElemType e)
{
    if ((Q.rear + 1) % MAXSIZE == Q.front)
        return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return OK;
}

// 出队
Status DeQueue(SqQueue &Q, QElemType &e)
{
    if (Q.front == Q.rear)
        return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return OK;
}

// 取队头
QElemType GetHead(SqQueue Q)
{

    return Q.base[Q.front];
}

// 盼复安是否空
Status Judge(SqQueue Q)
{
    return !(Q.front == Q.rear);
}

// 遍历
void PrintQueue(SqQueue Q)
{
    int i = Q.front;
    while (i != Q.rear)
    {
        cout << Q.base[i] << " ";
        i = (i + 1) % MAXSIZE;
    }
}

int main()
{
    int n, e;
    SqQueue Q;
    InitQueue(Q);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> e;
        EnQueue(Q, e);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        DeQueue(Q, e);
    }
    if (Judge(Q))
    {
        cout << "N" << endl;
        e = GetHead(Q);
        cout << e << endl;
        PrintQueue(Q);
    }
    else
    {
        cout << "Y";
    }
    return 0;
}