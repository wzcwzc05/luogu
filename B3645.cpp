#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N = 1e5 + 10;
ll n, q, sum;
ll l, r;
ll a[N], prefix[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    prefix[0] = 1;
    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] * a[i];
    for (int i = 1; i <= q; i++)
    {
        cin >> l >> r;
        sum = sum ^ ((prefix[r] / prefix[l - 1]) % 1145141);
    }
    cout << sum << "\n";
    return 0;
}