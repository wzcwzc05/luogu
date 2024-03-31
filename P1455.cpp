#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 10;
int n, m, w[N], v[N], father[N], sum, dp[N];
int x, y;
ll find(ll index) {
    if (father[index] == index)
        return index;
    else
        return father[index] = find(father[index]);
}
int main() {
    cin >> n >> m >> sum;
    for (int i = 1; i <= n; ++i) father[i] = i;
    for (int i = 1; i <= n; ++i) cin >> w[i] >> v[i];
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        father[find(x)] = find(y);
    }
    for (int i = 1; i <= n; ++i)
        if (father[i] != i) {
            w[find(i)] += w[i], w[i] = 0;
            v[find(i)] += v[i], v[i] = 0;
        }
    for (int i = 0; i <= n; ++i)
        for (int j = sum; j >= 0; --j)
            if (j - w[i] >= 0) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    cout << dp[sum] << "\n";
    return 0;
}