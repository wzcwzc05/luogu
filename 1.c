#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
int *Insert(int x, int *a, int *n)
{
    a = (int *)realloc(a, sizeof(int) * (*n + 1));
    int i = 0;
    for (i = 0; i < *n && a[i] <= x; ++i)
        ;
    *n += 1;
    for (int j = *n - 1; j >= i + 1; --j)
        a[j] = a[j - 1];
    a[i] = x;
    return a;
}
void Write(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main()
{
    int x, n = 0, *a = NULL;
    do
    {
        scanf("%d", &x);
    } while ((x >= 0) && (a = Insert(x, a, &n)));
    Write(a, n);
    free(a);
    return 0;
}