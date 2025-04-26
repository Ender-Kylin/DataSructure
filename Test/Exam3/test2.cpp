#include <iostream>
#include <stdlib.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

using namespace std;

typedef int SElemType;
typedef int Status;

typedef struct StackNode{
    SElemType data; // 数据域
   struct StackNode *next;// 指针域
   }SNode,  *LinkStack;

void Push(LinkStack &S, SElemType e)
{
       SNode *p = new SNode;
       p->data = e;
       p->next = S;
       S = p;
}
Status Pop(LinkStack &S, SElemType &e)
{
    if (S == NULL)
        return ERROR; // 栈空
    e = S->data;
    LinkStack p = S; // 用p临时保存栈顶元素空间,以备释放
    S = S->next;     // 修改栈顶指针
    delete p;
    return OK;
}

Status Judge(LinkStack A)
{
    if(A)
    {return 0;}
    return 1;
}

Status GetTop(LinkStack &A, SElemType &e)
{
    e = A->data;
    return OK;
}

int main()
{
    int n, e;
    LinkStack A = new SNode;
    A = nullptr;
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
    if (!Judge(A))
    {
        cout << "N" << endl;
        GetTop(A, e);
        cout << e << endl;
        while (!Judge(A))
        {
            Pop(A, e);
            cout << e << " ";
        }
    }
    else
    {
        cout << "Y";
    }
    return 0;
}
