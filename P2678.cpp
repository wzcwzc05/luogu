#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 10;
ll l, n, m;
ll a[N];
bool check(int k)
{
    ll t = 0, i = 0, pos = 0;
    while (i < n + 1)
    {
        i++;
        if (a[i] - a[pos] < k)
        {
            t++;
        }
        else
        {
            pos = i;
        }
    }
    return t <= m;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n + 1] = l;
    ll left = 0;
    ll right = l + 1, mid, ans;
    while (left + 1 != right)
    {
        mid = (left + right) / 2;
        if (check(mid))
        {
            ans = mid;
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    cout << ans << "\n";
    return 0;
}