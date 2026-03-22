#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 10;
int n, m, q, fa[N];
int findf(int x) {
    if (fa[x] == x)
        return x;
    else
        return fa[x] = findf(fa[x]);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) fa[i] = i;
    int x, y;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        fa[findf(x)] = findf(y);
    }
    while (q--) {
        cin >> x >> y;
        if (findf(x) == findf(y))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
