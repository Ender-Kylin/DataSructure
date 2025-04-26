#include <iostream>

using namespace std;

typedef struct Polynomial
{
    int factor;   // 系数
    int exponent; // 指数
    struct Polynomial *next;
} LNode, *LinkList;

void InputList(LinkList &L);

void ListAdd(LinkList L1, LinkList L2, LinkList &L3);

void copy(LinkList &L, LinkList &p);

void ListPrint(LinkList L);

int main()
{
    LinkList A, B, C;
    C = new LNode;
    C->next = nullptr;
    InputList(A);
    InputList(B);
    ListAdd(A, B, C);
    ListPrint(C);
    return 0;
}

void InputList(LinkList &L)
{
    L = new LNode;
    L->next = nullptr;
    LinkList q = L;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        LNode *p = new LNode;
        cin >> p->factor >> p->exponent;
        p->next = nullptr;
        q->next = p;
        q = p;
    }
}

void ListAdd(LinkList L1, LinkList L2, LinkList &L3)
{
    LinkList p = L3;
    L1 = L1->next;
    L2 = L2->next;
    while (L1 || L2)
    {
        if (L1 && L2)
        {
            if (L1->exponent > L2->exponent)
            {
                copy(p, L1);
            }
            else if (L1->exponent < L2->exponent)
            {
                copy(p, L2);
            }
            else
            {
                if (L1->factor + L2->factor)
                {
                    LNode *q = new LNode;
                    q->exponent = L1->exponent;
                    q->factor = L1->factor + L2->factor;
                    q->next = nullptr;
                    p->next = q;
                    p = p->next;
                    p->next = nullptr;
                    L1 = L1->next;
                    L2 = L2->next;
                }
                else
                {
                    L1 = L1->next;
                    L2 = L2->next;
                    continue;
                }
            }
        }
        else
        {
            while (L1 || L2)
            {
                L1 ? copy(p, L1) : copy(p, L2);
            }
        }
    }
    p->next = nullptr;
}

void copy(LinkList &L, LinkList &p)
{
    LNode *q = new LNode;
    q->exponent = p->exponent;
    q->factor = p->factor;
    L->next = q;
    L = L->next;
    p = p->next;
}

void ListPrint(LinkList L)
{
    LinkList p = L->next;
    while (p)
    {
        cout << p->factor << " " << p->exponent << " ";
        p = p->next;
    }
    cout << endl;
}