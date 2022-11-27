#include <stdio.h>
int main()
{
    int i,n,number,Total;
    number=0;
    Total=9;
    printf("User Input : ");
    scanf("%d", &n);
    printf("##########\n");
    printf("Series = ");
    for (i = 1; i <= n; i++)
    {
        number = number + Total;
        printf("%d", Total);
        if (i <= n - 1)
        {
            printf(" + ");
        } 
        Total = Total * 10 + 9;
    } 
    printf("\nnumber = ");
    printf("%d  ", number);
}  
