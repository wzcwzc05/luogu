#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    double t;
    for (int i = 1; i <= 20000000; i++)
        scanf("%lf", &t);
    double temp = 0.04;
    for (int i = 1; i <= 20000000; i++)
        printf("%.2lf ", (double)i + temp);
    printf("\n");
    return 0;
}