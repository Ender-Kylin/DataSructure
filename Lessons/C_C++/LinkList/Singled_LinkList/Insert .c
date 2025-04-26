#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Singled_LinkList.c"

//一下均为带头节点

//在第i个为止上插入一个元素e
bool ListInsert(LinkList *L, int i, ElemType e);


int main()
{
    return 0;
}

bool ListInsert(LinkList *L, int i, ElemType e)
{
    if(i < 1)
    {
        return false;
    }
    LNode *p;
    int j = 0;
    p = L;
    while(p != NULL && j < i - 1)
    {
        p = p -> next;
        
    }
}