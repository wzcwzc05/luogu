#include <bits/stdc++.h>
using namespace std;
const int N = 1515;
long long l[N][N], in[N], ou[N], dp[N];
int n, m, u, v, w, k, tmp;
queue<int> q;
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        l[u][v] = w;
        in[v]++;
    }
    for (int i = 2; i <= n; i++) {
        if (!in[i]) {
            for (int j = 1; j <= n; j++) {
                if (l[i][j]) {
                    in[j]--;
                }
            }
        }
    }
    q.push(1);
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        ou[k++] = tmp;
        for (int i = 1; i <= n; i++) {
            if (l[tmp][i]) {
                in[i]--;
                if (!in[i]) {
                    q.push(i);
                }
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        dp[i] = INT_MIN;
    }
    dp[1] = 0;
    for (int i = 0; ou[i]; i++) {
        for (int j = 1; j <= n; j++) {
            if (l[j][ou[i]]) dp[ou[i]] = max(dp[ou[i]], l[j][ou[i]] + dp[j]);
        }
    }
    if (dp[n] != INT_MIN)
        cout << dp[n];
    else
        cout << -1;
    return 0;
}