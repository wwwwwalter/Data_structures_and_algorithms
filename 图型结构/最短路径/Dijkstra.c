#include <stdio.h>
#include <stdlib.h>

/**
 * 最短路径：迪杰斯特拉算法
*/

#define V 20
#define INFINITY 65535

typedef struct
{
    int vexs[V];    //存储图中顶点数据
    int arcs[V][V]; //二维数组，记录顶点之间的关系
    int vexnum;     //顶点数
    int arcnum;     //弧边数
} MGraph;

//构造无向有权图
void CreateDG(MGraph *G)
{
    G->vexnum = 7;
    G->arcnum = 9;

    int i = 0;
    for (i = 0; i < G->vexnum; ++i)
    {
        G->vexs[i] = i;
    }

    int temp[9][3] = {
        {0, 1, 2},
        {0, 2, 6},
        {1, 3, 5},
        {2, 3, 8},
        {3, 5, 15},
        {3, 4, 10},
        {4, 5, 6},
        {4, 6, 2},
        {5, 6, 6}};

    int j = 0;
    int k = 0;
    for (i = 0; i < G->vexnum; ++i)
    {
        for (j = 0; j < G->vexnum; ++j)
        {
            G->arcs[i][j] = INFINITY;
        }
    }

    for (i = 0; i < G->vexnum; ++i)
    {
        for (j = 0; j < G->vexnum; ++j)
        {
            if ((temp[k][0] == i && temp[k][1] == j) || (temp[k][0] == j && temp[k][1] == i))
            {
                G->arcs[i][j] = temp[k][2];
                G->arcs[j][i] = temp[k][2];
                k++;
            }
        }
    }
}

//迪杰斯特拉算法，v0表示有向网中起点所在数组中的下标
void Dijkstra_minTree(MGraph G, int v0, int *P, int *D)
{
    //为各个顶点配置一个标记值，用于确认该顶点是否已经找到最短路径
    int final[V];
    int v = 0;
    for (v = 0; v < G.vexnum; ++v)
    {
        final[v] = 0;
        D[v] = G.arcs[v0][v];
        P[v] = 0;
    }

    D[v0] = 0;
    final[v0] = 1;
    int k = 0;
    int i = 0;
    int w = 0;
    for (i = 0; i < G.vexnum; ++i)
    {
        int min = INFINITY;
        for (w = 0; w < G.vexnum; ++w)
        {
            if (!final[w])
            {
                if (D[w] < min)
                {
                    k = w;
                    min = D[w];
                }
            }
        }
        final[k] = 1;

        //对v0到各顶点的权值进行更新
        for (w = 0; w < G.vexnum; ++w)
        {
            if (!final[w] && (min + G.arcs[k][w] < D[w]))
            {
                D[w] = min + G.arcs[k][w];
                P[w] = k;//k的pre
            }
        }
    }
}

int main(void)
{
    MGraph G = {0};
    CreateDG(&G);
    int P[V] = {0}; //记录顶点0到各个顶点的最短路径
    int D[V] = {0}; //记录顶点0到各个顶点的总权值
    Dijkstra_minTree(G, 0, P, D);

    printf("最短路径:\n");
    int i = 0;
    for (i = 1; i < G.vexnum; ++i)
    {
        printf("%d - %d的最短路径中有顶点:", i, 0);
        printf(" %d-", i);
        int j = i;
        while (P[j] != 0)
        {
            printf("%d-", P[j]);
            j = P[j];
        }
        printf("0\n");
    }
    printf("源点到各个顶点的最短路径长度为:\n");
    for (i = 1; i < G.vexnum; ++i)
    {
        printf("%d - %d:%d\n", G.vexs[0], G.vexs[i], D[i]);
    }

    return 0;
}