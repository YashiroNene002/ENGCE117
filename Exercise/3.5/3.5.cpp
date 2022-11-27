#include <stdio.h>
int main()
{
    int n, i, j, count;
    int koi[100];
    printf("Input number of element to be store in array : ");
    scanf("%d", &n);
    printf("----\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element[%d] : ", i + 1);
        scanf("%d", &koi[i]);
    } 
    for (int i = 0; i < n; i++)
    {
        count = 1;
        for (j = i + 1; j <= n - 1; j++)
        {
            if (koi[i] == koi[j] && koi[i] != 0)
            {
                count++;
                koi[j] = 0;
            }
        } 
        if (koi[i] != 0)
        {
            printf("%d -> %d\n", koi[i], count);
        } 
    }
} 
