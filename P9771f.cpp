#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e6 + 10;
ll n, a[N], l, r;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int last = a[1];
    int flag;
    if (a[2] - a[1] >= 0)
        flag = 1;
    else
        flag = 2;
    ll ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] - a[i - 1] >= 0 && flag == 2)
        {
            flag = 1;
            ans++;
            continue;
        }
        if (a[i] - a[i - 1] < 0 && flag == 1)
        {
            flag = 2;
            ans++;
            continue;
        }
    }
    cout << ans << "\n";
    return 0;
}