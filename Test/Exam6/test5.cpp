//
// Created by 37616 on 2025/5/14.
//

#include <iostream>
#include <climits>
#include <iomanip>

using namespace std;

#define MVNum 20
#define MaxInt INT_MAX

typedef char VertexType;

typedef int ArcType;

typedef struct {
    VertexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum, arcnum;
}AMGraph;

typedef struct {
    VertexType adjvex;
    ArcType lowcost;
}CloseEdge;

int Locatevex(AMGraph G, VertexType v) {
    int i = 0;
    for (i = 0; i < G.vexnum; i++) {
        if (v == G.vexs[i]) {
            break;
        }
    }
    return i;
}

void CreateUDN(AMGraph &G) {
    cin >>G.vexnum>>G.arcnum;
    for (int i = 0; i < G.vexnum; i++) {
        cin>>G.vexs[i];
    }
    for (int i = 0; i < G.vexnum; i++) {
        for (int  j =0; j < G.vexnum; j++) {
            G.arcs[i][j] = MaxInt;
        }
    }
    for (int k = 0; k < G.arcnum; k++) {
        VertexType v1,v2;
        ArcType w;
        cin>>v1>>v2>>w;
        int i = Locatevex(G,v1),j = Locatevex(G,v2);
        G.arcs[i][j] = w;
        G.arcs[j][i] = w;
    }
}

int Min(CloseEdge close_edge[], int n) {
    int min = MaxInt;
    int k = -1;
    for (int i = 0; i < n; i++) {
        if (close_edge[i].lowcost != 0 && close_edge[i].lowcost < min) {
            min = close_edge[i].lowcost;
            k = i;
        }
    }
    return k;
}

void MiniSpanTree_PRIM(AMGraph &G, VertexType u) {
    int k = Locatevex(G,u);
    CloseEdge close_edge[MVNum];
    for (int i = 0; i < G.vexnum; i++) {
        if (i != k) {
            close_edge[i].adjvex = u;
            close_edge[i].lowcost = G.arcs[i][k];
        }
        else {
            close_edge[i].lowcost = 0;
        }
    }
    for (int i = 0; i < G.vexnum - 1; i++) {
        k = Min(close_edge, G.vexnum);
        close_edge[k].lowcost = 0;
        cout << close_edge[k].adjvex << " " << G.vexs[k] << endl;
        for (int j = 0; j < G.vexnum; j++) {
            if (j != k && G.arcs[j][k] < close_edge[j].lowcost) {
                close_edge[j].adjvex = G.vexs[k];
                close_edge[j].lowcost = G.arcs[j][k];
            }
        }
    }
}

int main() {
    AMGraph G;
    VertexType u;
    CreateUDN(G);
    cin >> u;
    MiniSpanTree_PRIM(G,u);
    return 0;
}