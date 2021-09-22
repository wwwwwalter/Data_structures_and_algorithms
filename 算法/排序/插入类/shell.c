#include <stdio.h>
#include <stdlib.h>

/**
 * 希尔排序
*/

void shell_sort(int *list, int size)
{
    //计算最大间隔
    int interval = 1;
    while (interval < size / 3)
    {
        interval = interval * 3 + 1;
    }

    //根据间隔数，不断划分序列，并对各子序列排序
    while (interval > 0)
    {
        printf("interval:%d\n", interval);
        int i;
        //对各个子序列做直接插入排序
        for (i = interval; i < size; i += interval)
        {
            //记录新值和位置
            int insertElem = list[i];
            int position = i;

            //从position向前遍历,找到目标位置后插入
            while (position > interval - 1 && list[position - interval] > insertElem)
            {
                //向后移动一个
                list[position] = list[position - interval];
                position = position - interval;
            }

            //只要有过移动
            if (position != i)
            {
                printf("%d<->%d 移动\n", list[position], insertElem);
                list[position] = insertElem;
            }
        }

        //重新计算间隔数
        interval = (interval - 1) / 3;
    }
}

int main(void)
{
    int i;
    int list[8] = {35, 33, 42, 10, 14, 19, 27, 44};
    shell_sort(list, 8);

    for (i = 0; i < 8; ++i)
    {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}