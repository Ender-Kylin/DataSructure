#include <iostream>
#include <string.h>

using namespace std;

typedef struct
{
    int weight;
    int parent, lchild, rchild;
} HTnode, *HuffmanTree; // 数组存储

typedef char **HuffmanCode;

void Select(HuffmanTree HT, int n, int &s1, int &s2)
{
    int min1 = INT_MAX, min2 = INT_MAX;
    s1 = 0, s2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (HT[i].parent == 0 && HT[i].weight < min1)
        {
            min1 = HT[i].weight;
            s1 = i;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i != s1 && HT[i].parent == 0 && HT[i].weight < min2)
        {
            min2 = HT[i].weight;
            s2 = i;
        }
    }
}

void HuffmanCoding(HuffmanTree &HT, int n)
{
    if (n <= 1)
        return;
    int m = 2 * n - 1;
    HT = new HTnode[m + 1]; // 0单元不使用
    for (int i = 1; i <= m; i++)
    {
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        HT[i].parent = 0; // 初始化
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> HT[i].weight;
    }
    // 构建
    for (int i = n + 1; i <= m; ++i)
    {
        int s1, s2;
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

void CreateHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n)
{
    HC = new char *[n + 1];
    char *cd = new char[n];
    cd[n - 1] = '\0';
    for (int i = 1; i <= n; ++i)
    {
        int start = n - 1, c = i, f = HT[i].parent;
        while (f != 0)
        {
            --start;
            if (HT[f].lchild == c)
            {
                cd[start] = '0';
            }
            else
            {
                cd[start] = '1';
            }
            c = f;
            f = HT[f].parent;
        }
        HC[i] = new char[n - start];
        strcpy(HC[i], &cd[start]);
    }
    delete cd;
}

int main()
{
    HuffmanTree HT;
    HuffmanCode HC;
    int n = 0;
    cin >> n;
    HuffmanCoding(HT, n);
    CreateHuffmanCode(HT, HC, n);
    for (int i = 1; i <= n; i++)
    {
        cout << HC[i] << endl;
    }
    return 0;
}