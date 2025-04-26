#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct
{
    ElemType *elem;
    int length;
} SqList;

void InitList(SqList *L);

void ScanfList(SqList *L);

void PrintList(SqList *L);

int main()
{
    SqList A0,B0;
    InitList(&A0);
    InitList(&B0);
    ScanfList(&A0);
    ScanfList(&B0);
    int i;
    for(i = 0; i < A0.length || i < B0.length ; i ++)
    {
        if(!(A0.elem[i] == B0.elem[i]))
        {
            i++;
            break;
        }

    }
    if(i == A0.length && i == B0.length)
    {
        printf("A=B");
    }
    else if(i == A0.length && i < B0.length)
    {
        printf("A<B");
    }
    else if(i < A0.length && i < B0.length && A0.elem[i] < B0.elem[i])
    {
        printf("A<B");
    }
    else
    {
        printf("A>B");
    }
    return 0;
}

void PrintList(SqList *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ", *((L->elem) + i));
    }
    printf("\n");
}

void InitList(SqList *L)
{
    L->elem = (ElemType *)malloc(sizeof(ElemType) * MAXSIZE);
    memset(L->elem, 0, sizeof(ElemType) * MAXSIZE);
    L->length = 0;
}

void ScanfList(SqList *L)
{
    int len;
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d", (L->elem + i));
        L->length++;
    }
}

