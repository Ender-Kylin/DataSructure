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
void CreateList(LinkList &L, int n);

// 打印
void ListPrint(LinkList L);

// 在第i个元素前插入e
bool ListInsert(LinkList &L, int i, ElemType e);

// 删除第n个元素,并打印删除的元素
bool ListDelete(LinkList &L, int n, ElemType &e);

// 求L的表长
int ListLength(LinkList L);

int main()
{
    int n, e, i;
    LinkList L = new LNode;
    cin >> n;
    CreateList(L, n);
    cin >> i >> e;
    if (!ListInsert(L, i, e))
    {
        cout << "Insertion Location Error" << endl;
    }
    cin >> n;
    if (!ListDelete(L, n, e))
    {
        cout << "Deletion Location Error" << endl;
    }
    else
    {
        cout << e << endl;
    }
    cout << ListLength(L) << endl;
    ListPrint(L);
    return 0;
}

void CreateList(LinkList &L, int n)
{
    L->next = nullptr;
    LinkList p = L;
    for (int i = 0; i < n; i++)
    {
        LNode *q = new LNode;
        cin >> q->data;
        q->next = nullptr;
        p->next = q;
        p = q;
    }
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

bool ListInsert(LinkList &L, int i, ElemType e)
{
    LinkList p = L;
    if (i < 1)
    {
        return false;
    }
    else
    {
        for (int j = 0; j < i - 1; j++)
        {
            p = p->next;
            if (p == nullptr)
            {
                return false;
            }
        }
        LNode *q = new LNode;
        q->data = e;
        q->next = p->next;
        p->next = q;
    }
    return true;
}

bool ListDelete(LinkList &L, int n, ElemType &e)
{
    LinkList p = L, q;
    if (n < 1)
    {
        return false;
    }
    else
    {
        for (int j = 0; j < n; j++)
        {
            q = p;
            p = p->next;

            if (p == nullptr)
            {
                return false;
            }
        }
        e = p->data;
        q->next = p->next;

        delete p;
    }
    return true;
}

int ListLength(LinkList L)
{
    if (L == nullptr)
    {
        return 0;
    }
    else
    {
        int i;
        for (i = 0; L->next; i++)
        {
            L = L->next;
        }
        return i;
    }
}
