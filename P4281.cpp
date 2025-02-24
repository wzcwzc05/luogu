#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
const int MAX_LOG = 20;
int n, m, x, y;
vector<int> G[N];
int depth[N], visited[N], father[N][MAX_LOG + 1];
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n - 1; ++i) {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    return 0;
}