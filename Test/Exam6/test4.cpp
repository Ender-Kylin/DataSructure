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
    VertexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum;
    int arcnum;
}AMGraph;


int LocateVex(AMGraph G, VertexType v)
{
    int i = 0;
    for(i = 0; G.vexs[i]; ++i)
    {
        if(v == G.vexs[i])
        {
            break;
        }
    }
    return i;
}

void CreateUDN(AMGraph &G)
{
    cin >>G.arcnum>>G.vexnum;
    for(int i = 0; i < G.vexnum; ++i)
    {
        cin >>G.vexs[i];
    }
    for(int i = 0; i < G.vexnum; ++i)
    {
        for(int  j = 0; j < G.vexnum; ++j)
        {
            *(*(G.arcs + i)+j) = -1;  //初始化为-1
        }
    }
    for(int k = 0; k < G.arcnum; ++k)
    {
        VertexType v1 ,v2;
        ArcType w;
        cin >>v1>>v2>>w;
        int i = LocateVex(G,v1), j = LocateVex (G, v2);
        G.arcs[i][j] = G.arcs[j][i] =w;
    }
}

void BFS_AM(AMGraph G, int v)
{
    int * vexs_BFS = new int[G.vexnum];
    bool visited[MVNum];
    
    int p = 0, q = 0;
    cout <<G.vexs[v];
    vexs_BFS[q++] = v;
    visited[v] = true;
    while(p != q)
    {
        int u = p++;
        for(int  i = G.vexnum; i > -1 ; --i)
        {
            if(G.arcs[u][i] != -1 && !visited[i])
            {
                cout<<G.vexs[i]<<" ";
                visited[i] = true
                ;
                vexs_BFS[q++] = v;
            }
        }
    }
}

int main()
{
    AMGraph G;
    CreateUDN(G);
    BFS_AM(G, 0);
    return 0;
}