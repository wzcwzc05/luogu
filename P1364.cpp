#include <bits/stdc++.h>
using namespace std;
vector<int> mp[1010];
int a[1010];
int n;
int bfs(int x)
{
    int sum = 0;
    queue<pair<int, int>> q;
    bitset<1010> bt(0);
    q.push({ x, 0 });
    while (!q.empty()) {
        int temp = q.front().first;
        int dis = q.front().second;
        sum += a[temp] * dis;
        bt[temp] = 1;
        q.pop();
        for (auto& i : mp[temp]) {
            if (!bt[i])
                q.push({ i, dis + 1 });
        }
    }
    return sum;
}
int main()
{
    int v, l, r;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> l >> r;
        if (l != 0)
            mp[i].push_back(l), mp[l].push_back(i);
        if (r != 0)
            mp[i].push_back(r), mp[r].push_back(i);
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        int temp = bfs(i);
        ans = min(ans, temp);
    }
    cout << ans << '\n';
    return 0;
}