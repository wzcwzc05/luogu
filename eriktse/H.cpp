#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, t, q;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> q;
    while (q--)
    {
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> t;
            ans = ans ^ t;
        }
        cout << ans << "\n";
    }
    return 0;
}