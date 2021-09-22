#include <stdio.h>
#define N 8 //设定待排序序列中的元素个数
//list[N] 为存储待排序序列的数组
void shell_sort(int list[N])
{
    int temp, i, j;
    //初始化间隔数为 1
    int interval = 1;
    //计算最大间隔
    while (interval < N / 3)
    {
        interval = interval * 3 + 1;
    }
    //根据间隔数，不断划分序列，并对各子序列排序
    while (interval > 0)
    {
        //对各个子序列做直接插入排序
        for (i = interval; i < N; i +=interval)
        {
            temp = list[i];
            j = i;
            while (j > interval - 1 && list[j - interval] >= temp)
            {
                list[j] = list[j - interval];
                j -= interval;
            }
            if (j != i)
            {
                list[j] = temp;
            }
        }
        //计算新的间隔数，继续划分序列
        interval = (interval - 1) / 3;
    }
}
int main()
{
    int i;
    int list[N] = {35, 33, 42, 10, 14, 19, 27, 44};
    //对待排序序列做希尔排序
    shell_sort(list);
    //输出已排序序列
    for (i = 0; i < N; i++)
    {
        printf("%d ", list[i]);
    }
}