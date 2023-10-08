#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, t;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        int ans = 0;
        while (t != 0)
        {
            if (t % 2 == 1)
                ans++;
            t /= 2;
        }
        cout << ans << " ";
    }
    cout << "\n";
    return 0;
}