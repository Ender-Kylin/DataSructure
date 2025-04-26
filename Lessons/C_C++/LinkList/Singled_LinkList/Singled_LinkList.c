#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int ElemType;


//定义单链表
typedef struct
{
    ElemType data;
    struct LNode * next;
}LNode, *LinkList; //LNode强调是一个节点,而LinkList强调是一个单链表

//不带头节点

//初始化
bool InitList1(LinkList *L);

//判断是否为空
bool Empty1(LinkList L);


//带头节点

//初始化
bool InitList2(LinkList  *L);

//判断是否为空
bool Empty2(LinkList L);

int main()
{
    LinkList L;
    int chose;
    scanf("%d", &chose);
    switch (chose)
    {
        case 1:
                InitList1(&L);
                printf("如果非空则为0,否则为1:%d", Empty1(L));
                break;
        case 2 :
                InitList2(&L);
                printf("如果非空则为0,否则为1:%d", Empty2(L));
    }
    return 0;
}



bool InitList1(LinkList *L)
{
    *L = NULL;
    return true;
}

bool Empty1(LinkList L)
{
    if(L == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}//也可以写为return (L==NULL);

bool InitList2(LinkList  *L)
{
    *L = (LNode *) malloc (sizeof(LNode));
    if(*L == NULL)
    {
        return false;
    }
    (*L) -> next = NULL;
    return true;
}

bool Empty2(LinkList L)
{
    return L->next == NULL;
}