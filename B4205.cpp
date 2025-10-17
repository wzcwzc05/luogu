#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, k;
string str;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    cin >> str;
    ll len = str.size();
    for (char sp_char = 'a'; sp_char <= 'z'; ++sp_char) {
        ll max_l = 0, now_l = 0;
        for (int i = 0; i < len; ++i) {
            if (str[i] == sp_char) {
                max_l++;
            } else {
                if (max_l != 0) {
                    ll x_length = max_l < (len - i) ? max_l : (len - i);
                    if (x_length * max_l + now_l >= k) {
                        cout << str[(k - now_l - 1) % x_length + i];
                        now_l = INT_MAX;
                        break;
                    }
                    now_l += x_length * max_l;
                    i += x_length - 1;
                } else
                    now_l++;
                max_l = 0;
            }
            if (now_l == k) {
                cout << str[i];
                break;
            }
        }
        if (now_l < k) cout << "*";
    }
    cout << "\n";
    return 0;
}