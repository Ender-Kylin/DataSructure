#include <iostream>
#include <climits>
#include <iomanip>

using namespace std;

#define MVNum 20
#define MaxInt INT_MAX

typedef char VertexType;
typedef int ArcType;

typedef struct
{
    VertexType vexs[MVNum];     // 顶点
    ArcType arcs[(MVNum*MVNum+MVNum) / 2]; // 邻接矩阵
    int vexnum, arcnum;
} AMGraph;

// 搜索顶点在G当中的位置
int LocateVex(AMGraph G, VertexType v)
{
    int i = 0;
    for (i = 0; G.vexs[i]; i++)
    {
        if (v == G.vexs[i])
        {
            break;
            }
    }
    return i;
}

int getIndex(int i, int j)
{
    if (i < j)
    {
        swap(i, j);
    }
    return i * (i - 1) / 2 + j; 
}

void CreateUDN(AMGraph &G)
{
    int a = G.vexnum * (G.vexnum + 1) / 2;
    cin >> G.arcnum>>G.vexnum;
    for(int i = 0;i < G.vexnum; ++i)
    {
        cin >> G.vexs[i];
    }
    for(int i = 0; i < a; ++i)
    {
        G.arcs[i] = MaxInt;
    }
    for(int k = 0; k < G.arcnum; ++k)
    {
        VertexType v1,v2;
        ArcType w;
        cin>> v1>>v2>>w;
        int i = LocateVex(G, v1), j = LocateVex(G, v2);
        G.arcs[getIndex(i, j)] = w;
    }
}

