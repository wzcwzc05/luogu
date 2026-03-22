#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e4 + 10;
int fa[N * 3], n, k, opt, x, y, res;
int findf(int x) { return fa[x] == x ? x : fa[x] = findf(fa[x]); }
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= 3 * n + 1; ++i) fa[i] = i;
    for (int i = 1; i <= k; ++i) {
        cin >> opt >> x >> y;
        if (x > n || y > n)
            res++;
        else if (opt == 1) {
            if (findf(x) == findf(y + n) || findf(x) == findf(y + 2 * n))
                res++;
            else
                fa[findf(x)] = findf(y), fa[findf(x + n)] = findf(y + n),
                fa[findf(x + n * 2)] = findf(y + n * 2);
        } else {
            // cout << findf(x) << " " << findf(y) << "\n";
            if (findf(x) == findf(y) || findf(y) == findf(x + n))
                res++;
            else
                fa[findf(x)] = findf(y + n),
                fa[findf(x + n)] = findf(y + n * 2),
                fa[findf(x + n * 2)] = findf(y);
        }
    }
    cout << res << "\n";
    return 0;
}