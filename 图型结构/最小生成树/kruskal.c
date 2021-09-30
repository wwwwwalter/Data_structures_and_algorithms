#include <stdio.h>
#include <stdlib.h>

/**
 * 最小生成树：克鲁苏卡尔
*/

#define N 9 //图中边的数量
#define P 6 //图中顶点的数量

//构建表示边的结构体
typedef struct Edge
{
    //一条边有2个顶点
    int initial;
    int end;
    //边的权值
    int weight;
} edge;

//qsort排序函数中使用，使edges结构体中的边按照权值大小升序排序
int cmp(const void *a, const void *b)
{
    return ((edge *)a)->weight - ((edge *)b)->weight;
}

//克鲁斯卡尔算法寻找最小生成树，edges存储用户输入的图的各个边，minTree用于记录组最小生成树的各个边
void kruskal_mintree(edge edges[], edge minTree[])
{
    int i, initial, end, elem, k;
    //每个顶点配置一个标记值
    int assists[P];
    int num = 0;
    //初始状态下，每个顶点的标记都不同
    for (i = 0; i < P; ++i)
    {
        assists[i] = i;
    }

    //根据权值，对所有边进行升序排序
    qsort(edges, N, sizeof(edges[0]), cmp);

    for (i = 0; i < N; ++i)
    {
        printf("%d %d %d\n", edges[i].initial, edges[i].end, edges[i].weight);
    }

    //遍历所有边
    for (i = 0; i < N; ++i)
    {
        //找到当前的两个顶点在assists数组中的位置下表
        initial = edges[i].initial - 1;
        end = edges[i].end - 1;
        printf("(%d)%d-(%d)%d:%d\n", assists[initial], edges[i].initial, assists[end], edges[i].end, edges[i].weight);
        //如果顶点位置存在且顶点标记不同，说明不在一个集合中，不会产生回路
        if (assists[initial] != assists[end])
        {
            //记录该边，作为最小生成树的组成部分
            minTree[num] = edges[i];
            num++;
            elem = assists[end];
            //将新加入生成树的顶点全部标记为一样的
            for (k = 0; k < P; ++k)
            {
                if (assists[k] == elem)
                {
                    printf("(%d)->(%d)\n", assists[k], assists[initial]);
                    assists[k] = assists[initial];
                }
            }
            //如果选择的边和数量和顶点数相差1，证明最小生成树已经形成，退出循环
            if (num == P - 1)
            {
                break;
            }
        }
    }
}

void display(edge *minTree)
{
    int cost = 0;
    int i;
    printf("minTree:\n");
    for (i = 0; i < P - 1; ++i)
    {
        printf("%d-%d 权值:%d\n", minTree[i].initial, minTree[i].end, minTree[i].weight);
        cost += minTree[i].weight;
    }
    printf("总权值：%d\n", cost);
}

int main(void)
{
    edge edges[N];
    edge minTree[P - 1];

    int num[9][3] = {
        {5, 1, 7},
        {5, 3, 8},
        {1, 2, 6},
        {1, 3, 3},
        {3, 2, 4},
        {3, 4, 3},
        {2, 4, 2},
        {2, 6, 5},
        {4, 6, 2},
    };

    int i;
    for (i = 0; i < N; ++i)
    {
        edges[i].initial = num[i][0];
        edges[i].end = num[i][1];
        edges[i].weight = num[i][2];
    }

    kruskal_mintree(edges, minTree);
    display(minTree);

    return 0;
}