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

int LocateElem(SqList *L, ElemType e);

void ScanfList(SqList *L);

void Copy(SqList *A, SqList *B,SqList *C);

int main()
{
	SqList A, B, C;
	InitList(&A);
	InitList(&B);
	InitList(&C);
	ScanfList(&A);
	ScanfList(&B);
	Copy(&A,&B, &C);
	PrintList(&C);
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

int LocateElem(SqList *L, ElemType e)
{
	for (int i = 0; i < L->length; i++)
	{
		if (*(L->elem + i) == e)
		{
			return 1;
		}
	}
	return 0;
}




void ScanfList(SqList *L)
{
	int len;
	scanf("%d", &len);
	for (int i = 0; i < len; i++)
	{
		scanf("%d", (L -> elem + i));
		L -> length++;
	}
}


void Copy(SqList *A, SqList *B,SqList *C)
{
	for(int i = 0, j = 0; i < A -> length; i++)
	{
		if(LocateElem(B, A->elem[i]))
		{
			C->elem[j++] = A->elem [i];
			C->length ++;
		}
	}
}