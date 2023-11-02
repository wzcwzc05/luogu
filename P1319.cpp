#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e3 + 10;
ll n, m, x, y, num, t;
bool mp[N][N], f1;
int main()
{
    x = 1, y = 1, num = 0;
    cin >> n;
    while (cin >> t)
    {
        for (int i = 1; i <= t; i++)
        {
            num++;
            // cout << num / n + 1 << " " << num % n << "\n";
            if (num % n != 0)
                mp[num / n + 1][num % n] = f1;
            else
                mp[num / n][n] = f1;
        }
        if (f1)
            f1 = false;
        else
            f1 = true;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << mp[i][j];
        cout << "\n";
    }
    return 0;
}