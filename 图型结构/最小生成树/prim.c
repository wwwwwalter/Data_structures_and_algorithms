#include <stdio.h>

/**
 * 最小生成树 MST
 * 普里姆算法 
*/

#define V 6

typedef enum
{
    false,
    true
} bool;

//查找权值最小的、尚未被选择的顶点
//key 数组记录了各顶点之间的权值数据，visited数组记录着各个顶点是否已经被选择的信息
int min_key(int key[], bool visited[])
{
    int min = 2147483647;
    int min_index;

    int v;
    for (v = 0; v < V; ++v)
    {
        if (visited[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

//输出最小生成树
void print_mst(int parent[], int cost[V][V])
{
    int min_cost = 0;
    printf("最小生成树为:\n");
    int i = 0;
    for (i = 1; i < V; ++i)
    {
        printf("%d - %d wight:%d\n", parent[i] + 1, i + 1, cost[i][parent[i]]);
        min_cost += cost[i][parent[i]];
    }
    printf("总权值：%d\n", min_cost);
}

//根据用户提供的图的信息(存储在cost数组中),寻找最小生成树
void find_mst(int cost[V][V])
{
    int parent[V] = {0};
    int key[V] = {0};
    bool visited[V] = {0};

    int i = 0;
    for (i = 0; i < V; ++i)
    {
        key[i] = 2147483647;
        visited[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;
    parent[0] = -1;

    int x = 0;
    for (x = 0; x < V - 1; ++x)
    {
        int u = min_key(key, visited);
        visited[u] = true;

        int v = 0;
        for (v = 0; v < V; ++v)
        {
            if (cost[u][v] != 0 && visited[v] == false && cost[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = cost[u][v];
            }
        }
    }
    print_mst(parent, cost);
}

int main(void)
{
    int p1, p2;
    int wight;
    int cost[V][V] = {0};

    cost[1 - 1][5 - 1] = 7;
    cost[5 - 1][1 - 1] = 7;
    cost[1 - 1][3 - 1] = 3;
    cost[3 - 1][1 - 1] = 3;
    cost[5 - 1][3 - 1] = 8;
    cost[3 - 1][5 - 1] = 8;
    cost[1 - 1][2 - 1] = 6;
    cost[2 - 1][1 - 1] = 6;
    cost[2 - 1][3 - 1] = 4;
    cost[3 - 1][2 - 1] = 4;
    cost[2 - 1][4 - 1] = 2;
    cost[4 - 1][2 - 1] = 2;
    cost[3 - 1][4 - 1] = 3;
    cost[4 - 1][3 - 1] = 3;
    cost[2 - 1][6 - 1] = 5;
    cost[6 - 1][2 - 1] = 5;
    cost[4 - 1][6 - 1] = 2;
    cost[6 - 1][4 - 1] = 2;

    find_mst(cost);

    return 0;
}