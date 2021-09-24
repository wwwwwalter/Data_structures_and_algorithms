#include <stdio.h>
#include <stdlib.h>

/**
 * 桶排序
 * 将所有元素分为 10 组，每组的标号分别为 0~9。
 * 对序列中的各个元素乘以 10 再取整，得到的值即为该元素所在组的组号。
*/

#define N 7         // 待排序序列中的元素个数
#define NBUCKET 10  // 桶的数量
#define INTERVAL 10 // 每个桶能存放的元素个数

//桶
struct Node
{
    float data;
    struct Node *next;
};

struct Node *insert_sort(struct Node *list)
{
    struct Node *k;
    struct Node *nodelist;
    if (list == NULL || list->next == NULL)
    {
        return list;
    }

    nodelist = list;
    k = list->next;
    nodelist->next = NULL;

    while (k != NULL)
    {
        struct Node *ptr;
        if (nodelist->data > k->data)
        {
            struct Node *temp;
            temp = k;
            k = k->next;
            temp->next = nodelist;
            nodelist = temp;
            continue;
        }
        for (ptr = nodelist; ptr->next != 0; ptr = ptr->next)
        {
            if (ptr->next->data > k->data)
            {
                break;
            }
        }

        if (ptr->next != 0)
        {
            struct Node *temp;
            temp = k;
            k = k->next;
            temp->next = ptr->next;
            ptr->next = temp;
            continue;
        }
        else
        {
            ptr->next = k;
            k = k->next;
            ptr->next->next = NULL;
            continue;
        }
    }
    return nodelist;
}

void bucket_sort(float array[], int size)
{
    int i, j;
    struct Node **buckets;
    buckets = (struct Node **)malloc(sizeof(struct Node *) * NBUCKET);
    for (i = 0; i < NBUCKET; ++i)
    {
        buckets[i] = NULL;
    }

    //根据规定，将array中的每个元素分散存储到各个桶中
    for (i = 0; i < N; ++i)
    {
        struct Node *node;
        int pos = array[i] * 10;
        //创建存储该元素的存储块，并连接到指定的桶中，前插法
        node = (struct Node *)malloc(sizeof(struct Node));
        node->data = array[i];
        node->next = buckets[pos];
        buckets[pos] = node;
    }
    //调用自定义排序算法，对桶内元素排序
    for (i = 0; i < NBUCKET; ++i)
    {
        buckets[i] = insert_sort(buckets[i]);
    }

    //合并所有桶内元素
    for (j = 0, i = 0; i < NBUCKET; ++i)
    {
        struct Node *node;
        node = buckets[i];
        while (node)
        {
            array[j++] = node->data;
            node = node->next;
        }
    }
}

int main(void)
{
    float array[7] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    bucket_sort(array, 7);
    int i = 0;
    for (i = 1; i < 7; ++i)
    {
        printf("%.2f ", array[i]);
    }
    printf("\n");
    return 0;
}