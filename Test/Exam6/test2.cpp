#include <iostream>
#include <climits>
#include <iomanip>

using namespace std;

#define MVNum 20
#define MaxInt INT_MAX

typedef char VertexType;
typedef int ArcType;


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

//搜索索引
int LocateVex(ALGraph G, char v)
{
    int i = 0;
    for(i = 0; i < G.vexnum; ++i)
    {
        if(v == G.vertices[i].data)
            break;
    }
    return i;
}

//利用邻接表创建图
void CreateUDG(ALGraph &G)
{
    cin >> G.vexnum>>G.arcnum;
    for(int i = 0; i < G.vexnum;++i)
    {
        cin>>G.vertices[i].data;
        G.vertices[i].firstarc = nullptr;
    }
    for(int k = 0;k < G.arcnum; ++k)
    {
        char v1, v2;
        int data;
        cin >> v1 >>v2>>data;
        int i = LocateVex(G, v1), j = LocateVex(G, v2);
        ArcNode * p1 = new ArcNode, *p2 = new ArcNode;
        p1->adjvex = j; p2->adjvex = i;
        p1->info = p2->info = data;
        p1->nextarc = G.vertices[i].firstarc;p2->nextarc = G.vertices[j].firstarc;
        G.vertices[i].firstarc = p1;G.vertices[j].firstarc = p2;
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
    ALGraph AL;
    CreateUDG(AL);
    PrintALGraph(AL);
    return 0;   
}
