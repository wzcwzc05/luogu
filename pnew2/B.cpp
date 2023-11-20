#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 2e5 + 10;
ll n, m, a[N], prefix[N], q;
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << "\n";
    }
    return 0;
}