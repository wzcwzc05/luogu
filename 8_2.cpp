#include <bits/stdc++.h>
using namespace std;
int mp[10][10] = {0};
int ans;
bool check() {
    for (int i = 0; i <= 4; ++i) {
        int t = mp[i][0], flag = 0;
        for (int j = 0; j <= 4; ++j)
            if (mp[i][j] != t) {
                flag = 1;
                break;
            }
        if (flag == 0) return false;
        t = mp[0][i], flag = 0;
        for (int j = 0; j <= 4; ++j)
            if (mp[j][i] != t) {
                flag = 1;
                break;
            }
        if (flag == 0) return false;
    }
    int t = mp[0][0], flag = 0;
    for (int i = 0, j = 0; i <= 4; ++i, ++j)
        if (mp[i][j] != t) {
            flag = 1;
            break;
        }
    if (flag == 0) return false;
    t = mp[4][0], flag = 0;
    for (int i = 4, j = 0; i >= 0; --i, ++j)
        if (mp[i][j] != t) {
            flag = 1;
            break;
        }
    if (flag == 0) return false;
    return true;
}
void dfs(int dep, int black, int white) {
    if (dep >= 25) {
        if (((black == 12 && white == 13) || (black == 13 && white == 12)) &&
            check())
            ans++;
        return;
    }
    // cout << dep << " " << black << " " << white << "\n";
    mp[dep / 5][dep % 5] = 1;
    dfs(dep + 1, black + 1, white);
    mp[dep / 5][dep % 5] = 0; 
    dfs(dep + 1, black, white + 1);
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    dfs(0, 0, 0);
    cout << ans << "\n";
    return 0;
}