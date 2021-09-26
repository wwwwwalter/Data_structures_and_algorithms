#include <stdio.h>
#include <stdlib.h>

/**
 * 插值查找
*/

int interpolation_search(int *arr, int begin, int end, int ele)
{
    int mid = 0;
    if (begin > end)
    {
        return -1;
    }

    mid = begin + ((end - begin) / (arr[end] - arr[begin]) * (ele - arr[begin]));
    if (ele == arr[mid])
    {
        return mid;
    }

    if (ele < arr[mid])
    {
        return interpolation_search(arr, begin, mid - 1, ele);
    }
    else
    {
        return interpolation_search(arr, mid + 1, end, ele);
    }
}

int main(void)
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int pos = interpolation_search(arr, 0, 9, 2);
    printf("pos=%d\n", pos);

    return 0;
}