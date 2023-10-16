#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
using ll = long long;
ll a[N], prefix[N], diff[N], n, maxx, minn, mod, m, sum[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> mod >> minn >> maxx;
    for (int i = 1; i <= m; i++)
    {
        char opt;
        cin >> opt;
        if (opt == 'A')
        {
            ll l, r, x;
            cin >> l >> r >> x;
            diff[l] += x;
            diff[r + 1] -= x;
        }
        else if (opt == 'Q')
        {
            ll l, r, ans = 0;
            cin >> l >> r;
            for (int j = 1; j <= r; j++)
                a[j] = a[j - 1] + diff[j];
            for (int j = l; j <= r; j++)
            {
                if (a[j] * j % mod >= minn && a[j] * j % mod <= maxx)
                    ans++;
            }
            cout << ans << "\n";
        }
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + diff[i];
        if (a[i] * i % mod >= minn && a[i] * i % mod <= maxx)
            sum[i] = sum[i - 1] + 1;
        else
            sum[i] = sum[i - 1];
    }

    cin >> m;
    ll l, r, ans = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << "\n";
    }
    return 0;
}