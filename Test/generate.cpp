#include <cstdio>
#include <cstdlib>
#include <random>
#include <ctime>
using namespace std;
int main()
{
    freopen("input.in", "w", stdout);
    srand(time(NULL));
    for (int i = 1; i <= 20000000; i++)
    {
        int t = rand() % 100;
        double temp = t * 1.0 / 100;
        printf("%.2lf ", temp + (double)i);
    }
    printf("\n");
    return 0;
}