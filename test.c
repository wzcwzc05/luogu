#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n, hash[10001];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        scanf("%d", &temp);
        hash[temp]++;
    }
    for (int i = 1; i <= 10000; i++)
        if (hash[i])
            printf("%d ", i);
    printf("\n");
    return 0;
}