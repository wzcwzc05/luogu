#include <bits/stdc++.h>
using namespace std;
using ll = long long;
set<string> st, st2;
ll n, m, ans_max, ans_min;
string tmp;
void to_lower(string &str) {
    for (auto &c : str)
        if (c >= 'A' && c <= 'Z') c += ('a' - 'A');
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> tmp;
        to_lower(tmp);
        st.insert(tmp);
    }
    ans_max = st.size();
    for (int i = 1; i <= m; ++i) {
        cin >> tmp;
        to_lower(tmp);
        if (st.find(tmp) != st.end()) {
            if (st2.find(tmp) == st2.end()) ans_min++;
        } else {
            if (st2.find(tmp) == st2.end()) ans_max++;
        }
        st2.insert(tmp);
    }
    // for (auto &s : st) cout << s << "\n";
    cout << ans_min << "\n" << ans_max << "\n";
    return 0;
}
