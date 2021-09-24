#include <stdio.h>
#include <stdlib.h>

/**
 * 基数排序
*/

//找数的最大值
int getMax(int *array, int size)
{
    int i;
    int max = array[0];
    for (i = 1; i < size; ++i)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

//找指定位数上的最大值
int getMax2(int *array, int size, int place)
{
    int i;
    int max = (array[0] / place) % 10;
    for (i = 1; i < size; ++i)
    {
        if ((array[i] / place) % 10 > max)
        {
            max = array[i];
        }
    }
    return max;
}

void count_sort(int *array, int size, int place)
{
    int i, output[7] = {0};
    int count[10] = {0};
    //找指定位数上的最大值
    int max = getMax2(array, size, place);
    //统计各个元素出现的次数
    for (i = 0; i < size; ++i)
    {
        count[(array[i] / place) % 10]++;
    }
    //累加排位
    for (i = 1; i <= max; ++i)
    {
        count[i] += count[i - 1];
    }
    //根据 count 数组中的信息，找到各个元素排序后所在位置，存储在 output 数组中
    for (i = size - 1; i >= 0; --i)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }
    //将 output 数组中的数据原封不动地拷贝到 array 数组中
    for (i = 0; i < size; ++i)
    {
        array[i] = output[i];
        printf("%d ", array[i]);
    }
    printf("\n");
}

void radix_sort(int *array, int size)
{
    //找到序列中最大值
    int max = getMax(array, size);
    //根据最大值具有的位置，从低位到高位依次调用计数排序算法
    int place = 0;
    for (place = 1; max / place > 0; place *= 10)
    {
        count_sort(array, size, place);
    }
}

int main(void)
{
    int array[] = {121, 432, 564, 23, 1, 45, 788};
    radix_sort(array, 7);

    int i = 0;
    for (i = 0; i < 7; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}