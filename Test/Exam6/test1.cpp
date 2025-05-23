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
    ArcType arcs[MVNum][MVNum]; // 邻接矩阵
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

// 采用邻接矩阵创建图
void CreateUDN(AMGraph &G)
{
    cin >> G.vexnum >> G.arcnum; // 输入总顶点,总边数
    for (int i = 0; i < G.vexnum; ++i)
    {
        cin >> G.vexs[i]; // 输入各个节点的信息
    }
    for (int i = 0; i < G.vexnum; ++i)
    {
        for (int j = 0; j < G.vexnum; ++j)
        {
            G.arcs[i][j] = MaxInt; // 初始化为MaxInt
        }
    }
    for (int k = 0; k < G.arcnum; ++k)
    {
        VertexType v1, v2; // 边依附的两个顶点
        ArcType w;         // 边的权值
        cin >> v1 >> v2 >> w;
        int i = LocateVex(G, v1), j = LocateVex(G, v2);
        G.arcs[i][j] = w;
        G.arcs[j][i] = w;
    }
}

int main()
{
    AMGraph G;
    CreateUDN(G);
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            cout << setw(12) << G.arcs[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}