#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, x, y, ans;
string str, str1;
int mp_up[100005], mp_right[100005], pre_up[100005], pre_right[100005];
map<int, vector<int>> st_up, st_right;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> x >> y;
    cin >> str;
    if (x == 0 && y == 0) {
        cout << n * (n + 1) / 2 << endl;
        return 0;
    }
    st_up[0].push_back(1);
    st_right[0].push_back(1);
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == 'W') mp_up[i] = 1, mp_right[i] = 0;
        if (str[i] == 'S') mp_up[i] = -1, mp_right[i] = 0;
        if (str[i] == 'A') mp_up[i] = 0, mp_right[i] = -1;
        if (str[i] == 'D') mp_up[i] = 0, mp_right[i] = 1;
        pre_up[i + 1] = pre_up[i] + mp_up[i];
        pre_right[i + 1] = pre_right[i] + mp_right[i];
        st_up[pre_up[i + 1]].push_back(i + 1);
        st_right[pre_right[i + 1]].push_back(i + 1);
        if (!st_up[pre_up[i + 1] - x].empty()) {
            //  cout << i + 1 << " " << pre_up[i + 1] - x << endl;
            for (auto j : st_up[pre_up[i + 1] - x]) {
                if (pre_right[i + 1] - pre_right[j] == y) {
                    // cout << i + 1 << " " << n << "\n";
                    ans += (n - i);
                }
            }
        }
    }
    // for (auto j : st_up[1]) cout << j << " ";
    cout << ans << endl;
    return 0;
}