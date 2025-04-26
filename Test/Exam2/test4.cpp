#include <iostream>

using namespace std;

typedef int Elemtype;

typedef struct LNode
{
    int code;
    int key;
    // 定义整型变量code用来存放序号
    // 定义整型变量key用来存放密码
    struct LNode *next;
} LNode, *LinkList;

void CreateList(LinkList &L);

void Obsolete(LinkList &L);

int m, n;

int main()
{
    LinkList tail;
    cin >> m >> n;
    CreateList(tail);
    while (--n)
    {
        Obsolete(tail);
    }
    cout << tail->code;
    delete tail;
    return 0;
}

void CreateList(LinkList &L)
{
    LinkList p = L;
    p->code = 1;
    cin >> p->key;
    for (int i = 1; i < n;)
    {
        LNode *q = new LNode;
        q->code = ++i;
        cin >> q->key;
        q->next = nullptr;
        p->next = q;
        p = p->next;
    }
    p->next = L;
    L = p; // L为这个循环链表的尾巴
}

void Obsolete(LinkList &L)
{
    for (int i = 1; i < m; i++)
    {
        L = L->next;
    }
    LNode *q = L->next;
    L->next = q->next;
    cout << q->code << " ";
    m = q->key;
    delete q;
}