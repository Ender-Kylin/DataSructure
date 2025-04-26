#include <iostream>

using namespace std;

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} LNode, *LinkList;

void CreateList(LinkList &L);

void LJL(LinkList A, LinkList B, LinkList &C);

void ListPrint(LinkList L);

int main()
{
    LinkList A, B, C = new LNode;
    C->next = nullptr;
    CreateList(A);

    CreateList(B);
    LJL(A, B, C);
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

void LJL(LinkList A, LinkList B, LinkList &C)
{
    LinkList p = A->next, q = B->next, r = C;
    while (p && q)
    {
        if (p->data < q->data)
        {
            p = p->next;
        }
        else if (p->data > q->data)
        {
            q = q->next;
        }
        else
        {
            LNode *m = new LNode;
            m->data = p->data;
            m->next = nullptr;
            r->next = m;
            r = r->next;
            p = p->next;
            q = q->next;
        }
    }
}
