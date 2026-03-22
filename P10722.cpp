#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
ll n, q;
ll count_t[N];
ll ans[N];
string str;
vector<ll> mp[N];
void dfs(int sum, int x) {
    ans[x] += sum;
    for (auto& node : mp[x]) {
        dfs(sum + count_t[node], node);
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n - 1; ++i) {
        ll tmp;
        cin >> tmp;
        mp[tmp].push_back(i + 1);
    }
    cin >> str;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        ll tmp;
        cin >> tmp;
        count_t[tmp] += 1;
    }
    dfs(count_t[1], 1);
    for (int i = 1; i <= n; ++i) {
        ll flag = str[i - 1] - '0';
        if (ans[i] % 2 == 0)
            cout << (int)flag;
        else
            cout << (int)!flag;
    }
    cout << '\n';
    return 0;
}