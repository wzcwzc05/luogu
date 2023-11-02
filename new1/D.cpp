#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll q, n, m, ans;
string st;
int main()
{
    cin >> q >> n;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        if (l < r)
        {
            if (r - l >= n)
                ans++;
        }
        else if (24 - l + r >= n)
            ans++;
    }
    cout << ans << "\n";
    return 0;
}