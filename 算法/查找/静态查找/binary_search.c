#include <stdio.h>
#include <stdlib.h>

/**
 * 二分查找
*/

int binary_search(int *arr, int p, int q, int elem)
{
    int mid = 0;
    if (p > q)
    {
        return -1;
    }

    mid = (p + q) / 2;
    if (elem == arr[mid])
    {
        return mid;
    }

    if (elem < arr[mid])
    {
        return binary_search(arr, p, mid - 1, elem);
    }
    else
    {
        return binary_search(arr, mid + 1, q, elem);
    }
}

int main(void)
{
    int arr[10] = {10, 14, 19, 26, 27, 30, 31, 35, 42, 44};
    int pos = binary_search(arr, 0, 9, 31);
    printf("pos=%d\n", pos);

    return 0;
}