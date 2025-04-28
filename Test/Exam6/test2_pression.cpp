#include <iostream>
#include <climits>
#include <iomanip>

using namespace std;

#define MVNum 20
#define MaxInt INT_MAX

typedef char VertexType;
typedef int ArcType;

// 临界矩阵表示的图
typedef struct
{
    VertexType vexs[MVNum];                    // 顶点
    ArcType arcs[(MVNum * MVNum + MVNum) / 2]; // 邻接矩阵(压缩为一维)
    int vexnum, arcnum;
} AMGraph;

// 邻接表节点
typedef struct ArcNode
{
    int adjvex;              // 该弧所指向的顶点的位置
    ArcType info;            // 权值
    struct ArcNode *nextarc; // 指向下一条弧的指针
} ArcNode;

// 邻接表顶点
typedef struct VNode
{
    VertexType data;   // 顶点信息
    ArcNode *firstarc; // 指向第一条依附该顶点的弧的指针
} VNode, AdjList[MVNum];

// 邻接表表示的图
typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

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

// 采用邻接矩阵创建图
void CreateUDN(AMGraph &G)
{
    cin >> G.vexnum >> G.arcnum; // 输入总顶点,总边数
    for (int i = 0; i < G.vexnum; ++i)
    {
        cin >> G.vexs[i]; // 输入各个节点的信息
    }
    for (int i = 0; i < G.vexnum * (G.vexnum - 1) / 2; ++i)
    {
        G.arcs[i] = MaxInt;
    }
    for (int k = 0; k < G.arcnum; ++k)
    {
        VertexType v1, v2; // 边依附的两个顶点
        ArcType w;         // 边的权值
        cin >> v1 >> v2 >> w;
        int i = LocateVex(G, v1), j = LocateVex(G, v2);
        G.arcs[getIndex(i, j)] = w;
    }
}

// 将邻接矩阵转化为邻接表
void AMToAL(AMGraph G, ALGraph &AL)
{
    AL.vexnum = G.vexnum;
    AL.arcnum = G.arcnum;
    // 初始化顶点表
    for (int i = 0; i < AL.vexnum; ++i)
    {
        AL.vertices[i].data = G.vexs[i];
        AL.vertices[i].firstarc = nullptr;
    }

    // 遍历邻接矩阵创建邻接表
    for (int i = 0; i < G.vexnum; ++i)
    {
        for (int j = 0; j < G.vexnum; ++j)
        {
            if (i != j)
            {
                if (G.arcs[getIndex(i, j)] != MaxInt)
                {
                    ArcNode *node = new ArcNode;
                    node->adjvex = j;
                    node->info = G.arcs[getIndex(i, j)];
                    node->nextarc = AL.vertices[i].firstarc;
                    AL.vertices[i].firstarc = node;
                }
            }
        }
    }
}

void PrintALGraph(ALGraph AL)
{
    for (int i = 0; i < AL.vexnum; ++i)
    {
        cout << AL.vertices[i].data;
        ArcNode *p = AL.vertices[i].firstarc;
        while (p)
        {
            cout << "   " << p->adjvex << " " << p->info;
            p = p->nextarc;
        }
        cout << endl;
    }
}

int main()
{
    AMGraph G;
    ALGraph AL;
    CreateUDN(G);
    AMToAL(G, AL);
    PrintALGraph(AL);
    return 0;
}