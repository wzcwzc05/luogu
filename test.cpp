#include <cstdio>
int main()
{
    for (int i = 1; i <= 100; ++i)
        if (i == 100) {
            int sum = 100;
            int& p=sum;
        }
    printf("%d\n", p); // p悬空
    return 0;
}