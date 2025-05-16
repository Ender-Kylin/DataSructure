#include <iostream>
#include <climits>
#include <iomanip>
#include <cstring>

using namespace std;

#define MVNum 20
#define OK 1
#define ERROR 0
#define MaxInt INT_MAX

typedef char VertexType;
typedef int ArcType;
typedef int Status;



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

// 搜索索引
int LocateVex(ALGraph G, char v)
{
    int i = 0;
    for (i = 0; i < G.vexnum; ++i)
    {
        if (v == G.vertices[i].data)
            break;
    }
    return i;
}

void CreateDG(ALGraph &G)
{
    cin >> G.vexnum >> G.arcnum;
    for (int i = 0; i < G.vexnum; ++i)
    {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = nullptr;
    }
    for (int k = 0; k < G.arcnum; ++k)
    {
        char v1, v2;
        int data;
        cin >> v1 >> v2 >> data;
        int i = LocateVex(G, v1), j = LocateVex(G, v2);
        ArcNode *p = new ArcNode;
        p->adjvex = j;
        p->info = data;
        p->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p;
    }
}

void FindInDegree(ALGraph G, int indgree[])
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        indgree[i] = 0;
    }
    for (int i = 0; i < G.vexnum; ++i)
    {
        ArcNode *p = G.vertices[i].firstarc;
        while (p)
        {
            indgree[p->adjvex]++;
            p = p->nextarc;
        }
    }
}

Status TopologicalSort(ALGraph G, VertexType topo[])
{
    int indgree[MVNum], s[MVNum], p = 0, q = 0, m = 0;
    FindInDegree(G, indgree);
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (!indgree[i])
        {
            s[q++] = i;
        }
    }
    while (q != p)
    {
        topo[m++] = s[p++];
        ArcNode *pi = G.vertices[topo[m - 1]].firstarc;
        while (pi)
        {
            int k = pi->adjvex;
            --indgree[k];
            if (indgree[k] == 0)
            {
                s[q++] = k;
            }
            pi = pi->nextarc;
        }
    }
    if (m < G.vexnum)
    {
        return ERROR;
    }
    else
    {
        return OK;
    }
}

int main()
{
    ALGraph G;
    CreateDG(G);
    VertexType topo[MVNum];
    memset(topo, -1, sizeof(topo));
    if (TopologicalSort(G, topo) == OK)
    {
        for (int i = 0; topo[i] != -1; ++i)
        {
            cout << G.vertices[topo[i]].data << " ";
        }
    }
    else
    {
        cout << "存在环" << endl;
        for (int i = 0; topo[i] != -1; ++i)
        {
            cout << G.vertices[topo[i]].data << " ";
        }
    }
    return 0;
}