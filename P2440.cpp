#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 10;
ll n, m, a[N];
bool check(ll mid)
{
    ll s = 0;
    for (ll i = 1; i <= n; i++)
    {
        s += a[i] / mid;
    }
    if (s >= m)
        return true;
    else
        return false;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    ll l = 0, r = 1e8 + 10, mid = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        r = max(a[i], r);
    }
    r++;
    while (l + 1 != r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
        {
            l = mid;
            ans = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << ans << "\n";
    return 0;
}