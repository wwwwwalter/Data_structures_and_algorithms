#include <stdio.h>
#include <stdlib.h>

/**
 * 最短路径
 * 弗洛伊德算法
*/

#define V 4        //顶点数
#define INF 65535  //设定一个最大值
int P[V][V] = {0}; //记录各个顶点之间的最短路径

void printMatrix(int (*matrix)[V]); //输出各个顶点之间最短路径
void printPath(int i, int j);       //递归输出各个顶点之间最短路径的具体线路
void floyWarshall(int graph[V][V]); //实现弗洛伊德算法

//中序递归输出各个顶点之间最短路径的具体线路
void printPath(int i, int j)
{
    int k = P[i][j];
    if (k == 0)
    {
        return;
    }

    printPath(i, k);
    printf("%d-", k + 1);
    printPath(k, j);
}

//实现弗洛伊德算法
void floyWardshall(int (*graph)[V])
{
    int start, end, mid;
    //遍历每个顶点，将其作为其它顶点之间的中间顶点，更新graph
    for (mid = 0; mid < V; ++mid)
    {
        for (start = 0; start < V; ++start)
        {
            for (end = 0; end < V; ++end)
            {
                //如果新的路径比之前记录的更短，则更新graph数组
                if (graph[start][mid] + graph[mid][end] < graph[start][end])
                {
                    graph[start][end] = graph[start][mid] + graph[mid][end];
                    //记录此路径
                    P[start][end] = mid;
                }
            }
        }
    }
}

//输出各个顶点之家的最短路径
void printMatrix(int (*graph)[V])
{
    int i, j;
    for (i = 0; i < V; ++i)
    {
        for (j = 0; j < V; ++j)
        {
            if (j == i)
            {
                continue;
            }
            printf("%d - %d 最短路径为:", i + 1, j + 1);
            if (graph[i][j] == INF)
                printf("%s\n", "INF");
            else
            {
                printf("%d", graph[i][j]);
                printf(",依次经过:%d-", i + 1);
                printPath(i, j);
                printf("%d\n", j + 1);
            }
        }
    }
}

int main(int argc, char *args[])
{

    int graph[V][V] = {
        {0, 3, INF, 5},
        {2, 0, INF, 4},
        {INF, 1, 0, INF},
        {INF, INF, 2, 0}};

    floyWardshall(graph);
    printMatrix(graph);

    int start, end;
    for (start = 0; start < V; ++start)
    {
        for (end = 0; end < V; ++end)
        {
            if (P[start][end] == 0)
            {
                if (start == end)
                {
                    printf("0 ");
                }
                else
                {
                    printf("%d ", end + 1);
                }
            }
            else
            {
                printf("%d ", P[start][end] + 1);
            }
        }
        printf("\n");
    }

    printf("====================\n");
    for (start = 0; start < V; ++start)
    {
        for (end = 0; end < V; ++end)
        {
            printf("%d ", graph[start][end]);
        }
        printf("\n");
    }

    return 0;
}
