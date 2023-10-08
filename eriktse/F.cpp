#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long q, n, t[N], a[N], ess, b[N], prefix[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> q;
    while (q--)
    {
        ess = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> t[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (t[i] == 1)
                ess += a[i];
            if (t[i] == 1)
                b[i] = -a[i];
            else
                b[i] = a[i];
        }
        long long maxx = 0;
        long long minn = 0;
        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + b[i];
            maxx = max(prefix[i] - minn, maxx);
            minn = min(prefix[i], minn);
        }
        cout << ess + maxx << "\n";
    }
    return 0;
}