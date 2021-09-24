#include <stdio.h>
#include <stdlib.h>

/**
 * 计数排序
*/

int getMax(int *list, int size)
{
    int max = list[0];
    int i = 0;
    for (i = 1; i < size; ++i)
    {
        if (list[i] > max)
        {
            max = list[i];
        }
    }
    return max;
}

void count_sort(int *list, int size)
{
    //找最大值
    int max = getMax(list, size);

    //创建数组arr
    int array[100] = {0};
    int output[7] = {0};

    int i = 0;

    //统计各个元素出现次数，并存储到arr相应位置

    for (i = 0; i < size; ++i)
    {
        array[list[i]]++;
    }

    //累加数组中出现次数,排位
    for (i = 1; i <= max; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    for (i = 1; i <= max; ++i)
    {
        array[i] = array[i] + array[i - 1];
        printf("%d ", array[i]);
    }
    printf("\n");

    //根据arr中的值，找到各个元素排序后所在位置，存储再output数组中
    for (i = size - 1; i >= 0; --i)
    {
        output[array[list[i]] - 1] = list[i];
        //数组相应位置上值-1
        array[list[i]]--;
    }

    //将output拷贝到list中
    for (i = 0; i < size; ++i)
    {
        list[i] = output[i];
    }
}

int main(void)
{
    int list[7] = {4, 2, 2, 8, 3, 3, 1};
    count_sort(list, 7);

    int i = 0;
    for (i = 0; i < 7; ++i)
    {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}