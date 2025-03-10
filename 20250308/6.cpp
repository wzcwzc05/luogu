#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
ll reverse_bit(ll x) {
    ll res = 0, a = 1;
    while (x > 0) {
        res += ((x % 2 == 0) ? 1 : 0) * a;
        a *= 2;
        x /= 2;
    }
    return res;
}
int main() {
    // cout<<reverse_bit(10)<<"\n";
    ll a = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        ll tmp;
        cin >> tmp;
        a |= tmp;
    }
    ll k = 0;
    while (a & (1 << k)) { 
        k++;
    }
    ll x = 1 << k;
    cout<<x<<"\n";
    return 0;
}