#include <stdio.h>
#include <stdlib.h>

/**
 * 简单选择排序
*/

void select_sort(int *list, int size)
{
    int i, j;
    int pos, min;
    //[1,size-1]
    //[0,size-1)
    for (i = 0; i < size - 1; ++i)
    {
        //记下无序列中第一个位置
        pos = i;
        //从无序列中找最小值
        for (j = i + 1; j < size; ++j)
        {
            if (list[j] < list[pos])
            {
                pos = j;
            }
        }

        if (pos != i)
        {
            printf("%d<->%d\n", list[i], list[pos]);
            min = list[pos];
            list[pos] = list[i];
            list[i] = min;
        }
    }
}

int main(void)
{
    int i;
    int list[8] = {14, 33, 27, 10, 35, 19, 42, 44};
    select_sort(list, 8);

    for (i = 0; i < 8; ++i)
    {
        printf("%d ", list[i]);
    }
    return 0;
}