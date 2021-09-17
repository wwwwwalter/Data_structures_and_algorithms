/**
 * 进制转换器项目要求：
 * 用户提供需要转换的数据和该数据的进制，以及要转换的进制，
 * 进制转换器提供给用户最终的正确转换的结果。
 * 提示：
 * 此进制转换器可以在 2-36 进制之间对数据进行任意转换。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int top = -1;

void push(char *a, char elem)
{
    a[++top] = elem;
}

void pop(char *a)
{
    if (top == -1)
    {
        return;
    }
    if (a[top] >= 10)
    {
        printf("%c", a[top] + 55);
    }
    else
    {
        printf("%d", a[top]);
    }
    top--;
}

//将各进制转成十进制
int scaleFun(char *data, int system)
{
    int k = (int)strlen(data) - 1;
    int system_10_data = 0;
    int i;

    for (i = k; i >= 0; --i)
    {
        int temp;
        if (data[i] >= 48 && data[i] <= 57)
        {
            temp = data[i] - 48;
        }
        else
        {
            temp = data[i] - 55;
        }
        system_10_data += temp * pow(system, k - i);
    }
    return system_10_data;
}

int main(void)
{
    char data[100] = "64";
    int system = 16;
    int system_10_data = scaleFun(data, system);
    printf("%d\n", system_10_data);

    //十进制转n进制
    int newSystem = 2;
    while (system_10_data / newSystem)
    {
        push(data, system_10_data % newSystem);
        system_10_data /= newSystem;
    }
    push(data, system_10_data % newSystem);

    //出栈输出
    while (top != -1)
    {
        pop(data);
    }
    printf("\n");

    return 0;
}