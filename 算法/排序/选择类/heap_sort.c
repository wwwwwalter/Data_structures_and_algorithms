#include <stdio.h>
#include <stdlib.h>
/**
 * 堆选择排序
*/

//单个记录的结构体
typedef struct Node
{
    int key;
} Node;

//表的结构体
typedef struct List
{
    Node r[9];
    int length;
} List;

//将以 r[s]为根结点的子树构成堆，堆中每个根结点的值都比其孩子结点的值大
void HeapAdjust(List *list, int s, int m)
{
    Node root = list->r[s];

    //对于第s个节点，筛选一直到叶子节点结束
    int j = 0;
    for (j = 2 * s; j <= m; j *= 2)
    {
        //从两个孩子节点中比较出较大的那个
        if (j + 1 < m && list->r[j].key < list->r[j + 1].key)
        {
            j++;
        }

        //root和大孩子节点比较
        if (root.key < list->r[j].key)
        {
            list->r[s] = list->r[j];
            s = j;
        }
    }
    //最终才将root放到正确的位置
    list->r[s] = root;
}

//交换两个记录的位置
void swap(Node *a, Node *b)
{
    int key = a->key;
    a->key = b->key;
    b->key = key;
}

void heap_sort(List *list)
{
    //构建堆的过程
    int i = 0;
    //从⌊n/2⌋个元素开始筛选,直到第一个元素
    for (i = list->length / 2; i > 0; --i)
    {
        //中途可能会出现破坏之前子堆的的情况，那就立即重建子堆
        HeapAdjust(list, i, list->length);
    }


    for (i = 1; i <= list->length; ++i)
    {
        printf("%d ", list->r[i].key);
    }
    printf("\n");

    //重构过程
    for (i = list->length; i > 1; --i)
    {
        //用最后一个叶子节点代替根节点，作为临时根节点
        swap(&(list->r[1]), &(list->r[i]));
        //临时根节点和孩子节点比较，然后交换
        HeapAdjust(list, 1, i - 1);
    }
}

int main(void)
{
    List *list = (List *)malloc(sizeof(List));
    list->length = 8;
    list->r[1].key = 49;
    list->r[2].key = 38;
    list->r[3].key = 65;
    list->r[4].key = 97;
    list->r[5].key = 76;
    list->r[6].key = 13;
    list->r[7].key = 27;
    list->r[8].key = 49;

    int i = 1;
    for (i = 1; i <= list->length; ++i)
    {
        printf("%d ", list->r[i].key);
    }
    printf("\n");
    heap_sort(list);

    for (i = 1; i <= list->length; ++i)
    {
        printf("%d ", list->r[i].key);
    }
    printf("\n");

    return 0;
}