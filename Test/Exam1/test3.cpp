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


void PrintList(SqList * L);

void ListDelete(SqList *L, int i);

int main()
{
	SqList L;
	int len;
	scanf("%d", &len);
	InitList(&L);
	for (int i = 0; i < len; i++)
	{
		scanf("%d", (L.elem + i));
		L.length++;
	}
	int temp = L.elem[0];
	for (int i = 1; i < L.length; i++)
	{
		if (temp == L.elem[i])
		{
			ListDelete(&L, i + 1);
			i--;
		}
		else
		{
			temp = L.elem[i];
		}
	}
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

void ListDelete(SqList *L, int i)
{
	for (int j = i - 1; j < L->length - 1; j++)
	{
		L->elem[j] = L->elem[j + 1];
	}
	L->length--;
}