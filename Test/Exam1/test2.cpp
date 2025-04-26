#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100


typedef int ElemType;



typedef struct
{
	ElemType *elem;
	int length;
}SqList;

void InitList(SqList *L);

void ListInsert(SqList *L, int e);

void PrintList(SqList * L);

int main()
{
	int len, x;
	SqList L;
	scanf("%d", &len);
	InitList(&L);
	for (int i = 0; i < len; i++)
	{
		scanf("%d", (L.elem + i));
		L.length++;
	}
	scanf("%d", &x);
	ListInsert(&L, x);
	PrintList(&L);
	return 0;
}






void InitList(SqList *L)
{
	L->elem = (ElemType *)malloc(sizeof(ElemType)* MAXSIZE);
	memset(L->elem, 0, sizeof(ElemType)* MAXSIZE);
	L->length = 0;
}


void PrintList(SqList * L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", *((L->elem) + i));
	}
	printf("\n");
}

void ListInsert(SqList *L, int e)
{
	if (e > L->elem[L->length - 1])
	{
		L->elem[L->length] = e;
		L->length++;
	}
	else
	{
		for (int i = L->length - 1; i >= 0; i--)
		{
			*(L->elem + i + 1) = *(L->elem + i);
			if (e < *(L->elem + i) && e> *(L->elem + i - 1))
			{
				*(L->elem + i) = e;
				L->length++;
				return;
			}
		}
		L->elem[0] = e;
		L->length++;
	}

}