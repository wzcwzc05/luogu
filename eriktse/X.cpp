#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
ll n, m, a[N], q;
ll tr[N];
ll lowbit(ll x)
{
    return x & (-x);
}
void add(ll node, ll s)
{
    while (node <= n)
    {
        tr[node] += s;
        node += lowbit(node);
    }
}
ll query(ll right)
{
    ll ans = 0;
    while (right > 0)
    {
        ans += tr[right];
        right -= lowbit(right);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i], add(i, a[i]);
    while (q--)
    {
        ll opt;
        cin >> opt;
        if (opt == 1)
        {
            ll x, y;
            cin >> x >> y;
            add(x, y);
        }
        if (opt == 2)
        {
            ll x, y;
            cin >> x >> y;
            cout << query(y) - query(x - 1) << "\n";
        }
    }
    return 0;
}