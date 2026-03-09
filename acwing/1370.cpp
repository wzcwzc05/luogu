#include <bits/stdc++.h>
using namespace std;
int nums[11], n;
char opt[11];
int calc() {
    int p = 1;
    int now = nums[1];
    while (opt[p] == ' ') now = now * 10 + nums[++p];
    while (p <= n - 1) {
        char now_opt = opt[p++];
        int last = nums[p];
        while (opt[p] == ' ' && p <= n - 1) {
            last = last * 10 + nums[++p];
        }
        if (now_opt == '+')
            now = now + last;
        else
            now = now - last;
    }
    return now;
}
void dfs(int dep) {
    if (dep >= n) {
        if (calc() == 0) {
            cout << nums[1];
            for (int i = 2; i <= n; ++i) cout << opt[i - 1] << nums[i];
            cout << '\n';
        }
    } else {
        opt[dep] = ' ', dfs(dep + 1);
        opt[dep] = '+', dfs(dep + 1);
        opt[dep] = '-', dfs(dep + 1);
        opt[dep] = 0;
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) nums[i] = i;
    dfs(1);
    return 0;
}