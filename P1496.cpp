#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
ll st[N], ed[N], n, m;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> st[i] >> ed[i];
    sort(st + 1, st + n + 1);
    sort(ed + 1, ed + n + 1);
    ll l = 1, r = 1, ans = 0;
    while (true) {
        ans += ed[r] - st[l];
        if (l + 1 <= n)
            if (ed[l] > st[l + 1])
                ans -= ed[l] - st[l + 1];
        ++r, ++l;
        if (l > n || r > n)
            break;
    }
    cout << ans << "\n";
    return 0;
}