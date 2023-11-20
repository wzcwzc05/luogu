#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 10;
int n, a[N], maxx, minx;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 0 && i != 1)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    int t = 0;
    if (a[1] == 0)
        t = -1;
    ll ans = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i + 1] < i || a[i + 1] == 0)
        {
            cout << -1 << "\n";
            return 0;
        }
        while (a[i] >= a[i + 1])
        {
            a[i] >>= 1;
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}