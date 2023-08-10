#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, t, s;
    scanf("%d %d %d", &m, &t, &s);
    if (t == 0)
    {
        printf("0\n");
    }
    else
    {
        if (s / t <= m)
        {
            if (s % t == 0)
                cout << m - s / t << endl;
            else
                cout << m - s / t - 1 << endl;
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}