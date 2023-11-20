#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e8 + 10;
double fun(int n, double x)
{
    double s = 0;
    for (int i = 2; i <= n; i++)
    {
        bool flag = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << x << " " << i * 1.0 << endl;
            s += x / (i * 1.0);
            x *= x;
        }
    }
    return s;
}
int main()
{
    int n;
    double s;
    cin >> n >> s;
    printf("%.4lf\n", fun(n, s));
    return 0;
}