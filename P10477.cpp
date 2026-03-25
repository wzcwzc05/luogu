#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e3 + 10;
ll n, m, cnt, len, fa_1[N], fa_2[N], p;
string str1, str2;
bitset<N> vis;
void build(string& str, vector<int> tr[], ll fa[]) {
    cnt = 1, p = 1;
    len = str.size() - 1;

    for (int i = 0; i <= len + 1; ++i) {
        fa[i] = 0;
    }
    for (int i = 0; i <= len; ++i) {
        if (str[i] == '0') {
            tr[p].push_back(++cnt);
            fa[cnt] = p;
            p = cnt;
        } else {
            p = fa[p];
        }
    }
}
void gen_str(int node, vector<int> tr[], string s[]) {
    vector<string> tmp;
    for (auto& i : tr[node]) {
        gen_str(i, tr, s);
        tmp.push_back(s[i]);
    }
    sort(tmp.begin(), tmp.end());
    s[node] = "(";
    for (auto& i : tmp) s[node] += i;
    s[node] += ")";
}
void solve() {
    vector<int> tr_1[N], tr_2[N];
    string tr_str1[N], tr_str2[N];
    // cout << "!!!" << str1 << " " << str2 << "\n";
    build(str1, tr_1, fa_1);
    build(str2, tr_2, fa_2);
    gen_str(1, tr_1, tr_str1);
    gen_str(1, tr_2, tr_str2);
    // cout << tr_str1[1] << " " << tr_str2[1] << "\n";
    if (tr_str1[1] == tr_str2[1])
        cout << "same\n";
    else
        cout << "different\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    while (n--) {
        cin >> str1 >> str2;
        solve();
    }
    return 0;
}