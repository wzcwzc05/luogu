#include <stdio.h>
int main()
{
    int c;
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    while (c = getchar() != '\n')
    {
        if (c == '\b')
            printf("\\b");
        if (c == '\t')
            printf("\\t");
        if (c == '\\')
            printf("\\\\");
        else
            putchar(c);
    }
    return 0;
}