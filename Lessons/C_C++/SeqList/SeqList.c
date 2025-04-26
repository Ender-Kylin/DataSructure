#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义最大函数

#define MAxSize 1000

//定义默认长度
#define InitSize 5

typedef int ElemType;

// 静态分配顺序表

typedef struct
{
    ElemType data[MAxSize]; // 最大长度定义
    int length;             // 记录当前顺序表的长度
} SqList1;                  // 顺序表的类型的定义

//动态分配顺序表

typedef struct
{
    ElemType *data;
    int MAXSIZE;
    int length;
}SqList2;

// 初始化一个静态顺序表

void InitList1(SqList1 *L);

// 打印一个静态顺序表

void Print_List1(SqList1 *L);

//打印一个动态顺序表
void Print_List2(SqList2 *L);


//初始化一个动态顺序表
void InitList2(SqList2 *L);

//扩展一个动态顺序表
void IncreaseSize(SqList2 *L, int len);

//插入一个元素--动态
void ListInsert(SqList2 *L, int i, int e);

//删除一个元素--动态
void ListDelete(SqList2 *L, int i, int *e);

//查找元素--动态--按值
int GetElem(SqList2 * L, int i);

int main()
{
    int choose;
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        SqList1 L;    // 声明一个顺序表
        InitList1(&L); // 初始化顺序表
        for (int i = 0; i < 10; i++)
        {
            *((L.data) + i) = i + 1;
            L.length++;
        }
        Print_List1(&L);
        break;
    case 2:
        SqList2 L2;
        InitList2(&L2);
        for (int i = 0; i < 5; i++)
        {
            *((L2.data) + i) = i + 1;
            L2.length++;
        }
        printf("增加长度前:\n");
        Print_List2(&L2);
        IncreaseSize(&L2, 5);
        for (int i = 5; i < 10; i++)
        {
            *((L2.data) + i) = i + 1;
            L2.length++;
        }


        printf("增加长度后:\n");
        Print_List2(&L2);

        printf("插入元素后:\n");
        ListInsert(&L2, 3, 100);
        Print_List2(&L2);

        printf("删除第四个元素之后:\n");
        int e;
        ListDelete(&L2, 3, &e);
        Print_List2(&L2);

        printf("被删除的元素为:%d", e);

        printf("查找元素5是第%D位元素:%d\n(-1表示未找到)", GetElem(&L2, 5));

        free(L2.data);
        L2.data = NULL;
        break;
    }
    return 0;
}

void InitList1(SqList1 *L)
{
    for (int i = 0; i < MAxSize; i++)
    {
        L->data[i] = 0; // 初始化
    }
    L->length = 0;
}

void Print_List1(SqList1 *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("L.data[%d] = %d\n", i, *((L->data) + i));
    }
}

void Print_List2(SqList2 *L)
{
    for (int i = 0; i < L->length; i++)
    {
        printf("L.data[%d] = %d\n", i, *((L->data) + i));
    }
}

void InitList2(SqList2 *L)
{
    //先用malloc分配一片连续的内存空间
    L->data = (int *)malloc(InitSize * sizeof(int));

    //尝试初始化
    memset(L->data, 0, InitSize * sizeof(int));

    L->length = 0;
    L->MAXSIZE = InitSize;
}

void IncreaseSize(SqList2 *L, int len)
{
    int *p = L->data;
    L->data = (int *) malloc((L->MAXSIZE + len) * sizeof(int));
    memcpy(L->data, p, L->length * sizeof(int));
    L->MAXSIZE += len;
    free(p);
}

void ListInsert(SqList2 *L, int i, int e)
{
    if (!(i < 1 || i > L->length +1))
    {
        L->data = (int *) realloc(L->data, sizeof(int) * (L->length + 1));
        Print_List2(L);
        for (int j = L->length + 1; j >= i; j--)
        {
            L->data[j] = L->data[j - 1];
        }
        L->data[i - 1] = e;
        L->length;
    }
    else
    {
        printf("插入失败");
    }
    L->length ++;
}

void ListDelete(SqList2 *L, int i, int *e)
{
    if(i < 1 || i > L->length +1)
    {
        printf("删除失败");
    }
    else
    {
        *e = L->data[i - 1];
        for(int j = i; j < L->length; j++)
        {
            L->data[j - 1] = L->data[j];
        }
        L->length --;
    }
}

int GetElem(SqList2 * L, int i)
{
    for(int j = 0; j < L->length; j++)
    {
        if (L->data[j] == i)
        {
            return j + 1;
        }        
    }
    return -1;
}