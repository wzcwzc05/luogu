#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using set_t = set<int>;
int q, n, cnt;
string opt;
map<set_t, int> keys;
unordered_map<int, set_t> values;
int getSetId(set_t& s) {
    if (keys[s] == 0) {
        keys[s] = ++cnt;
        values[cnt] = s;
        return cnt;
    } else
        return keys[s];
}
set_t getSetById(int id) { return values[id]; }
void solve() {
    set_t tmp;
    keys.clear(), values.clear();
    cnt = 0;
    keys[tmp] = ++cnt;
    values[cnt] = tmp;
    cin >> n;
    stack<int> stk;
    for (int i = 1; i <= n; ++i) {
        cin >> opt;
        if (opt == "PUSH") stk.push(1);
        if (opt == "DUP") stk.push(stk.top());
        if (opt == "INTERSECT") {
            set_t top1_set = getSetById(stk.top());
            stk.pop();
            set_t top2_set = getSetById(stk.top());
            stk.pop();
            set_t res;
            set_intersection(top1_set.begin(), top1_set.end(), top2_set.begin(),
                             top2_set.end(), inserter(res, res.begin()));
            stk.push(getSetId(res));
        }
        if (opt == "UNION") {
            set_t top1_set = getSetById(stk.top());
            stk.pop();
            set_t top2_set = getSetById(stk.top());
            stk.pop();
            set_t res;
            set_union(top1_set.begin(), top1_set.end(), top2_set.begin(),
                      top2_set.end(), inserter(res, res.begin()));
            stk.push(getSetId(res));
        }
        if (opt == "ADD") {
            int top1_id = stk.top();
            stk.pop();
            set_t top2_set = getSetById(stk.top());
            stk.pop();
            top2_set.insert(top1_id);
            stk.push(getSetId(top2_set));
        }
        cout << getSetById(stk.top()).size() << "\n";
    }
    cout << "***\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}