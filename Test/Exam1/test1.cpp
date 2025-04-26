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


void ListInsert(SqList *L, int i, ElemType e);


void ListDelete(SqList *L, int i);

void PrintList(SqList * L);


int LocateElem(SqList *L, ElemType e);

int main()
{
	SqList L;
	InitList(&L);
	int len,del,search;
	scanf("%d", &len);
	for (int i = 0; i < len; i++)
	{
		scanf("%d", (L.elem + i));
		L.length++;
	}
	scanf("%d", &del);
	ListDelete(&L, del);
	scanf("%d", &search);
	search =  LocateElem(&L, search);
	PrintList(&L);
	if (search)
	{
		printf("%d", search);
	}
	else
	{
		printf("Not find");
	}
	return 0;
}



void InitList(SqList *L)
{
	L->elem = (ElemType *)malloc(sizeof(ElemType)* MAXSIZE);
	memset(L->elem, 0, sizeof(ElemType)* MAXSIZE);
	L->length = 0;
}

void ListDelete(SqList *L, int i)
{
	for (int j = i - 1; j < L->length - 1; j++)
	{
		L->elem[j] = L->elem[j + 1];
	}
	L->length--;
}

void PrintList(SqList * L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", *((L->elem) + i));
	}
	printf("\n");
}

int LocateElem(SqList *L, ElemType e)
{
	for (int i = 0; i < L->length; i++)
	{
		if (*(L->elem + i) == e)
		{
			return i + 1;
		}
	}
	return 0;
}