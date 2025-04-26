#include <iostream>
#include <stdbool.h>

using namespace std;

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} LNode, *LinkList;

// 创建
void CreateList(LinkList &L);

// 打印
void ListPrint(LinkList L);

// 求并集
LinkList ListUnion(LinkList &A, LinkList &B);

int main()
{
    LinkList A, B;
    CreateList(A);
    CreateList(B);
    LinkList C = ListUnion(A, B);
    ListPrint(C);

    return 0;
}

void CreateList(LinkList &L)
{
    L = new LNode;
    L->next = nullptr;
    LinkList p = L;
    int data = 0;
    cin >> data;
    while (data != -1)
    {
        LNode *q = new LNode;
        q->data = data;
        p->next = q;
        p = q;
        cin >> data;
    }
    p->next = nullptr;
}

LinkList ListUnion(LinkList &A, LinkList &B)
{
    LinkList C = new LNode, p = A->next, q = B->next;
    LinkList t = C;
    while (p && q)
    {
        if (p->data < q->data)
        {
            C->next = p;
            p = p->next;
        }
        else if (p->data > q->data)
        {
            C->next = q;
            q = q->next;
        }
        else
        {
            C->next = q;
            p = p->next;
            q = q->next;
        }
        C = C->next;
    }
    if (p)
    {
        C->next = p;
    }
    else
    {
        C->next = q;
    }
    return t;
}

void ListPrint(LinkList L)
{
    LinkList p = L;
    while (p->next != nullptr)
    {
        cout << p->next->data << " ";
        p = p->next;
    }
    cout << endl;
}
