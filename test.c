#include <stdio.h>
int main()
{
    char a[255];
    int i = 0, k = 0;
    for (i = 0; scanf("%c", &a[i]) != EOF; i++)
        ;
    for (k = i; k >= 0; k--)
        printf("%c", a[k]);
    printf("\n");
    return 0;
}