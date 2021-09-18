#include <stdio.h>
#include <stdlib.h>

/**
 * 直接插入排序
 */

void insert_sort(int *list, int size)
{
    //从第二个元素（下标为1开始遍历）
    int i = 1;
    for (i = 1; i < size; ++i)
    {
        int insertElem = list[i];
        int position = i;

        //从position向前遍历，找到目标位置后插入
        while (position > 0 && list[position - 1] > insertElem)
        {
            //向后移动一个
            list[position] = list[position - 1];
            position--;
        }

        //只要有过移动
        if (position != i)
        {
            list[position] = insertElem;
        }
    }
}

int main(void)
{

    int list[8] = {14, 33, 27, 10, 35, 19, 42, 44};
    insert_sort(list, 8);

    int i = 0;
    for (i = 0; i < 8; ++i)
    {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}