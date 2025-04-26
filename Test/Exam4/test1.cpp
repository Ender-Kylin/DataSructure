#include <iostream>
#include <stdlib.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

using namespace std;

typedef int QElemType;
typedef int Status;

typedef struct QNode
{
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

// 初始化
Status InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = new QNode;
    Q.front->next = nullptr;
    return OK;
}

// 入队
Status EnQueue(LinkQueue &Q, QElemType e)
{
    QNode *p = new QNode;
    p->data = e;
    p->next = nullptr;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

// 出队
Status DeQueue(LinkQueue &Q, QElemType &e)
{
    if (Q.front == Q.rear)
    {
        return ERROR;
    }
    QNode *p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    delete p;
    return OK;
}

// 取队头
QElemType GetHead(LinkQueue Q)
{

    return Q.front->next->data;
}

// 非空判断
Status JudegQueue(LinkQueue Q)
{
    if (!Q.front->next)
        return 0;
    return 1;
}

// 遍历
void PrintQueue(LinkQueue Q)
{
    for (QNode *i = Q.front->next; i; i = i->next)
    {
        cout << i->data << " ";
    }
}

int main()
{
    int n, i;
    LinkQueue Q;
    InitQueue(Q);
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        int e;
        cin >> e;
        EnQueue(Q, e);
    }
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        int e;
        DeQueue(Q, e);
    }
    if (JudegQueue(Q))
    {
        cout << "N" << endl;
        int e = GetHead(Q);
        cout << e << endl;
        PrintQueue(Q);
    }
    else
    {
        cout << "Y" << endl;
    }
    return 0;
}