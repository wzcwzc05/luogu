#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 10;
ll n, m, diff[N], a, b, c;
int main()
{
    cin >> n >> m;
    int last, now;
    if (m == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    cin >> last;
    for (int i = 1; i <= m - 1; i++)
    {
        cin >> now;
        int start = min(last, now);
        int end = max(last, now);
        diff[start]++;
        diff[end]--;
        last = now;
    }
    ll sum = 0, ans = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        sum += diff[i];
        cin >> a >> b >> c;
        if (sum > 0)
            ans += min(sum * a, sum * b + c);
    }
    if (ans >= 0)
        cout << ans << endl;
    else
        cout << 0 << endl;
    return 0;
}