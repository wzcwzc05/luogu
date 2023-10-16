#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
long long q, n, a[N], ans;
map<ll, ll> m;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> q;
    while (q--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        long long j = 1, i = 1;
        ans = 0;
        while (j <= n)
        {
            if (m[a[j]] == 0)
            {
                ans = max(ans, j - i + 1);
                m[a[j]] = 1;
                j++;
            }
            else
            {
                m[a[i]] = 0;
                i++;
            }
        }
        m.clear();
        cout << ans << "\n";
    }
    return 0;
}