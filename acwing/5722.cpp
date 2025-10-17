#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> mp;
set<int> st;
int n, m, c, idx, nums;
void action() {
    for (auto it = st.begin(); it != st.end(); ++it) {
        int idx = *it;
        if (mp[idx] >= 5) {
            auto prev_it = prev(it), last_it = next(it);
            if (it == st.begin())
                mp[*last_it] += 1;
            else if (it == st.end())
                mp[*prev_it] += 1;
            else
                mp[*last_it] += 1, mp[*prev_it] += 1;
            mp[idx]=0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> c >> m >> n;
    for (int i = 1; i <= m; ++i) {
        cin >> idx >> nums;
        mp[idx] = nums;
        st.insert(idx);
    }
    action();
    return 0;
}