#include <stdio.h>
#include <stdlib.h>

/**
 * 顺序查找
*/

int linear_search(int *array, int size, int value)
{
    int i = 0;
    for (i = 0; i < size; ++i)
    {
        if (array[i] == value)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10, 14, 19, 26, 27, 31, 33, 35, 42, 44};
    int add = linear_search(arr, 10, 33);
    if (add == -1)
    {
        printf("查找失败\n");
    }
    else
    {
        printf("查找成功:%d\n", add + 1);
    }

    return 0;
}