#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, l, r;
vector<ll> v, prefix;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    prefix.push_back(0), v.push_back(0);
    for (int i = 1; i <= n; ++i) {
        int temp;
        cin >> temp;
        v.push_back(temp);
        prefix.push_back(prefix[i - 1] + v[i]);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << "\n";
    }
    return 0;
}
