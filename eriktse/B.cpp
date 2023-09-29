#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long n, a[N], q, m, prefix[N], diff[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        diff[i] = a[i] - a[i - 1];
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        long long l, r, x;
        cin >> l >> r >> x;
        diff[l] += x;
        diff[r + 1] -= x;
    }
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] + diff[i];
    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + a[i];
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        long long l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << "\n";
    }
    return 0;
}