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
    int vexnum; //顶点数
    int arcnum; //边数
} AMGraph;

//标记数组
bool visited[MVNum];

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

//获取邻接矩阵中的下表
int getIndex(int j, int i)
{
    if (i < j)
    {
        swap(i, j);
    }
    return i * (i - 1) / 2 + j; 
}

//创建邻接矩阵
void CreateUDN(AMGraph &G)
{
    
    cin >> G.arcnum>>G.vexnum;
    int a = G.vexnum * (G.vexnum + 1) / 2;
    for(int i = 0;i < G.vexnum; ++i)
    {
        cin >> G.vexs[i];
    }
    for(int i = 0; i < a; ++i)
    {
        G.arcs[i] = 0;
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

void DFS_AM(AMGraph G, int v)
{
    cout<<G.vexs[v]<<" ";
    visited[v] = true;
    for(int w = 0;w < G.vexnum; ++w)
    {
        if((G.arcs[getIndex(v, w)]!= 0 )&& !visited[w])//判断的是w
        {
            DFS_AM(G,w);
        }
    } 
}


int main()
{
    AMGraph G;
    CreateUDN(G);
    DFS_AM(G, 0);
    return 0;
}