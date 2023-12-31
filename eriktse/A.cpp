#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long n, a[N], q, prefix[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
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