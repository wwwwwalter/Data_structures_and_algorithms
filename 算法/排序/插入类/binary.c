#include <stdio.h>
#include <stdlib.h>

/**
 * 折半插入排序
*/

void binary_insert(int *list, int size)
{
    //从第二个元素开始
    int i = 1;
    for (i = 1; i < size; ++i)
    {
        printf("#########\n");
        int insertElem = list[i];
        int position = i;

        //二分查找插入位置
        int low = 0;
        int high = i - 1;
        int mid = (low + high) / 2;

        while (low <= high)
        {
            mid = (low + high) / 2;
            if (list[mid] >= insertElem)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
            printf("mid = %d\n", mid);
        }

        //向后移动挪位置
        int j = i;
        for (j = i; j > low; j--)
        {
            printf("%d -> %d\n", list[j - 1], list[j]);
            list[j] = list[j - 1];
        }

        list[low] = insertElem;
    }
}

int main(void)
{
    // int list[8] = {14, 33, 27, 10, 35, 19, 42, 44};
    int list[8] = {1, 2, 3, 3, 4, 5, 6, 3};
    binary_insert(list, 8);

    int i = 0;
    for (i = 0; i < 8; ++i)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}