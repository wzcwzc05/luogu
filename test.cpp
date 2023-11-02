#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
ll n, a[N], sum;
bool vis[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        ll t, x, y;
        cin >> t;
        vis[t] = 1;
        bool flag1 = 1;
        for (int j = t; j >= 1; j--)
            if (vis[j] == 0)
            {
                flag1 = 0;
                x = a[j];
                break;
            }
        bool flag2 = 1;
        for (int j = t; j <= n; j++)
            if (vis[j] == 0)
            {
                flag2 = 0;
                y = a[j];
                break;
            }
        if (flag1 == 0 && flag2 == 0)
            sum += abs(x - y) * abs(x - y);
    }
    cout << sum << "\n";
    return 0;
}