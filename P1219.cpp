#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, ans;
int mp[200][200];
inline void dfs(int line)
{
    if (line > n) {
        ans++;
        if (ans > 3)
            return;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (mp[i][j] == 1) {
                    cout << j << " ";
                    break;
                }
        cout << "\n";
        return;
    } else {
        for (int i = 1; i <= n; i++)
            if (mp[line][i] == 0) {
                bool flag = 0;
                for (int j = 1; j <= line - 1; j++) {
                    if (mp[j][i] == 1 || mp[line - j][i - j] == 1 || mp[line - j][i + j] == 1) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    mp[line][i] = 1;
                    dfs(line + 1);
                    mp[line][i] = 0;
                }
            }
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    dfs(1);
    cout << ans << "\n";
    return 0;
}
