#include <stdio.h>
int main()
{
    int* p = NULL;
    for (int i = 1; i <= 100; ++i)
        if (i == 100) {
            int sum = 100;
            p = &sum;
        }
    printf("%d\n", *p); // p悬空
    return 0;
}