#include <stdio.h>
#include <stdlib.h>

/**
 * 归并排序
*/

void merge(int *arr, int p, int mid, int q)
{
    int i, j, k;
    int leftarr[100], rightarr[100];

    //拷贝
    for (i = 0; i < mid - p + 1; ++i)
    {
        leftarr[i] = arr[p - 1 + i];
    }
    leftarr[i] = 2147483647;
    for (i = 0; i < q - mid; ++i)
    {
        rightarr[i] = arr[mid + i];
    }
    rightarr[i] = 2147483647;

    //逐一比较leftarr和rightarr中的元素，每次将较小的元素拷贝到arr[p,q]中
    i = j = 0;
    for (k = p; k <= q; ++k)
    {
        if (leftarr[i] <= rightarr[j])
        {
            arr[k - 1] = leftarr[i];
            i++;
        }
        else
        {
            arr[k - 1] = rightarr[j];
            j++;
        }
    }
}

void merge_sort(int *arr, int p, int q)
{
    int mid;
    if (arr == NULL || p > q || p == q)
    {
        return;
    }
    //分割
    mid = (p + q) / 2;
    merge_sort(arr, p, mid);
    merge_sort(arr, mid + 1, q);
    //合并
    merge(arr, p, mid, q);
}

int main(void)
{
    int i = 0;
    int arr[8] = {7, 5, 2, 4, 1, 6, 3, 0};

    merge_sort(arr, 1, 8);
    for (i = 0; i < 8; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}