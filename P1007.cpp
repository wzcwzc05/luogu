#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 10;
ll a[N], n, m, l;
ll timeMin, timeMax;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> l >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << min(a[1], l - a[1] + 1) << " " << max(a[1], l - a[1] + 1) << "\n";
        return 0;
    }
    if (n == 0)
    {
        cout << "0 0\n";
        return 0;
    }
    sort(a + 1, a + n + 1);
    ll *pos = lower_bound(a + 1, a + n + 1, l / 2);
    // cout << *pos << " " << *(pos - 1) << "\n";
    timeMin = max(*(pos - 1), l - *pos + 1);
    cout << timeMin << " ";
    ll minn = a[1], maxn = a[n];
    ll mid = (maxn + minn) / 2;
    ll mod = (maxn + minn) % 2;
    // cout << maxn << " " << n << "\n";
    if (maxn == l)
    {
        cout << maxn << "\n";
        return 0;
    }
    if (mod == 1)
        timeMax = max(mid - minn + mid, maxn - mid - 1 + l - mid - 1 + mod);
    else
        timeMax = max(mid - minn + mid, maxn - mid + l - mid + 1);
    cout << timeMax << "\n";
    return 0;
}