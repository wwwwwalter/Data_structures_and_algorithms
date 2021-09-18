#include <stdio.h>
#include <stdlib.h>

/**
 * 快速排序
*/

/*
* 默认：以最后一个值作为中间值
* 返回：拆分后中间值的下标
* [p,q]用于指定排序区域
*/
int partition(int *arr, int p, int q)
{
    //lo 首个元素下标，ho 代表第二个元素下标,pivot代表中间值(最后一个值)
    int lo = p;
    int hi = q - 1;
    int pivot = arr[q];

    while (1)
    {
        //lo从左往右遍历，直至找到一个不小于 pivot 的元素
        // >= pivot,停在大的地方
        while (arr[lo] < pivot)
        {
            lo++;
        }
        //hi从右往左遍历，直至找到一个不大于 pivot 的元素
        // <= pivot，停在小的地方
        while (hi > 0 && arr[hi] > pivot)
        {
            hi--;
        }

        //如果 lo≥hi，退出循环(有可能指向同一个值，也可能擦肩而过)
        if (lo >= hi) //如果最后剩的哪个数=pivot就会出现lo==hi的情况，否则都是擦肩而过
        {
            break;
        }
        else
        {
            //交换arr[lo]和arr[hi]的值，这里导致不稳定
            int temp = arr[lo];
            arr[lo] = arr[hi];
            arr[hi] = temp;
            //lo hi都向前移动一个位置
            lo++;
            hi--;
        }
    }

    //交换arr[lo]和arr[q]的值，lo总是停在大的地方，所以放心和pivot交换
    int temp = arr[lo];
    arr[lo] = pivot;
    arr[q] = temp;

    printf("lo = %d\n", lo);
    return lo;
}

//递归
void quick_sort(int *arr, int p, int q)
{
    int par;
    //如果待排序序列不存在，或者仅包含 1 个元素，则不再进行分割
    if (q - p <= 0)
    {
        return;
    }
    else
    {
        //调用 partition() 函数，分割 [p,q] 区域
        par = partition(arr, p, q);
        //以 [p,par-1]作为新的待排序序列，继续分割
        quick_sort(arr, p, par - 1);
        //以[par+1,q]作为新的待排序序列，继续分割
        quick_sort(arr, par + 1, q);
    }
}

int main(void)
{
    int i = 0;
    int arr[10] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
    quick_sort(arr, 0, 9);

    for (i = 0; i < 10; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
