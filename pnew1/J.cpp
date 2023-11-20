#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5 + 10;
ll n, q, a[N], prefix1[N], sum, l, r, prefix2[N];
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix1[i] = prefix1[i - 1] + a[i];
        prefix2[i] = prefix2[i - 1] + a[i] * a[i];
    }
    while (q--)
    {
        cin >> l >> r;
        ll t = prefix1[r] - prefix1[l - 1];
        ll t2 = prefix2[r] - prefix2[l - 1];
        sum = (t * t - t2) / 2;
        cout << sum << "\n";
    }
    return 0;
}