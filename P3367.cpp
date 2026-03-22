#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 10;
ll n, m, fa[N];
int findf(int x) {
    if (fa[x] != x)
        return fa[x] = findf(fa[x]);
    else
        return x;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) fa[i] = i;
    int opt, x, y;
    for (int i = 1; i <= m; ++i) {
        cin >> opt >> x >> y;
        if (opt == 1) {
            fa[findf(x)] = findf(y);
        } else if (opt == 2) {
            if (findf(x) == findf(y))
                cout << "Y\n";
            else
                cout << "N\n";
        }
    }
    return 0;
}