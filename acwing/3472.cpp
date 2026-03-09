#include <bits/stdc++.h>
using namespace std;
int n, cnt;
int seq[10];
vector<int> ans[100];
bitset<100> bs;
bool check(int row, int col) {
    for (int i = 1; i <= row - 1; ++i) {
        if (abs(row - i) == abs(col - seq[i])) return false;
        if (col == seq[i]) return false;
    }
    return true;
}
void dfs(int dep) {
    if (dep > 8) {
        cnt++;
        for (int i = 1; i <= 8; ++i) ans[cnt].push_back(seq[i]);
    } else {
        for (int i = 1; i <= 8; ++i) {
            if (check(dep, i)) seq[dep] = i, dfs(dep + 1);
            seq[dep] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        int tmp;
        cin >> tmp;
        for (int j = 0; j < 8; ++j) cout << ans[tmp][j];
        cout << "\n";
    }

    return 0;
}