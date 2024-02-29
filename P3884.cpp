#include <bits/stdc++.h>
using namespace std;
struct Node {
    int node, value;
};
vector<Node> mp[110];
int countDep[1010], n, maxdep, maxwidth;
int tr[1010];
bitset<1010> bt(0);
void dfs(int dep, int node)
{
    bt[node] = 1;
    maxdep = max(maxdep, dep);
    maxwidth = max(++countDep[dep], maxwidth);
    for (auto& i : mp[node]) {
        if (!bt[i.node])
            dfs(dep + 1, i.node);
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int x, y;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        mp[x].push_back({ y, 1 }), mp[y].push_back({ x, 2 });
    }
    cin >> x >> y;
    dfs(1, 1);
    cout << maxdep << "\n"
         << maxwidth << "\n";
    queue<pair<int, int>> q;
    bitset<1010> bt2(0);
    q.push({ x, 0 });
    while (!q.empty()) {
        int node = q.front().first, dis = q.front().second;
        bt2[node] = 1, q.pop();
        if (node == y) {
            cout << dis << "\n";
            break;
        }
        for (auto& i : mp[node]) {
            if (!bt2[i.node])
                q.push({ i.node, dis + i.value });
        }
    }
    return 0;
}