#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, b[100], sum, endx, x, ans;
bool isPower(ll x, ll p)
{
    ll last, num = 0;
    if (x <= 0)
        return false;
    while (x != 0)
    {
        last = x % p;
        if (last != 1 && last != 0)
            return false;
        else if (last == 1)
            if (num != 0)
                return false;
            else
                num = 1;

        x = x / p;
    }
    return true;
}
int main()
{
    x = 0;
    cin >> endx >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    ans = INT_MAX;
    for (int i = n; i >= 1; i--)
    {
        int left = endx - i;
        if (left > 0)
        {
            for (int j = 1; j <= m; j++)
            {
                if (isPower(left, b[j]))
                {
                    ans = min(ans, (ll)pow(left, 1.0 / b[j]) + 1);
                }
                else
                    continue;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (isPower(n, b[i]))
            ans = min(ans, (ll)pow(n, 1.0 / b[i]));
    }
    cout << ans << "\n";
    return 0;
}