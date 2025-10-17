#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct opt {
    int opt;
    bitset<65>* num;
};
ll n, m, tmp, ans;
bitset<65> res;
opt all_opts[100005];
string str;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    bitset<65> max_num(m);
    ll max_t = log2(m) + 1, now = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> str >> tmp;
        if (str == "AND") all_opts[i].opt = 0;
        if (str == "OR") all_opts[i].opt = 1;
        if (str == "XOR") all_opts[i].opt = 2;
        all_opts[i].num = new bitset<65>(tmp);
        max_t = max(max_t, (ll)log2(tmp) + 1);
    }
    bitset<65> zero_res(0);
    for (int i = 1; i <= n; ++i) {
        if (all_opts[i].opt == 0) zero_res = zero_res & *(all_opts[i].num);
        if (all_opts[i].opt == 1) zero_res = zero_res | *(all_opts[i].num);
        if (all_opts[i].opt == 2) zero_res = zero_res ^ *(all_opts[i].num);
    }

    // cout << m << "\n";
    for (int i = max_t; i >= 0; --i) {
        int t = 1, f = 0;
        ll r = 1ll << i;
        for (int j = 1; j <= n; ++j) {
            if (all_opts[j].opt == 0) {
                t = t & (all_opts[j].num->test(i));
                f = f & (all_opts[j].num->test(i));
            }
            if (all_opts[j].opt == 1) {
                t = t | (all_opts[j].num->test(i));
                f = f | (all_opts[j].num->test(i));
            }
            if (all_opts[j].opt == 2) {
                t = t ^ (all_opts[j].num->test(i));
                f = f ^ (all_opts[j].num->test(i));
            }
        }
        // cout << i << " " << t << " " << f << " " << now << " " << r << "\n";
        if (f)
            res[i] = 1;
        else if (t && now + r <= m) {
            res[i] = 1;
            now += r;
        }
    }
    cout << max(res.to_ullong(), zero_res.to_ullong()) << "\n";
    return 0;
}
