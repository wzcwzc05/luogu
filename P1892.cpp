#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int fa[2010];
vector<int> enm[2005];
char opt;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) {
    int fa_x = find(x), fa_y = find(y);
    if (fa_x != fa_y) fa[fa_x] = fa_y;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 1; i <= m; ++i) {
        cin >> opt >> x >> y;
        if (opt == 'F') fa[find(x)] = find(y);
        if (opt == 'E') {
            int fa_x = find(x), fa_y = find(y);
            enm[x].push_back(y), enm[y].push_back(x);
            for (auto &j : enm[x]) merge(j, y);
            for (auto &j : enm[y]) merge(j, x);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (find(i) == i) ans++;
    cout << ans << "\n";
    return 0;
}