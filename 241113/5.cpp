#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll all_a[30] = {9226, 4690, 4873, 1285, 4624, 1596, 6982, 590,
                      8806, 121,  8399, 8526, 5426, 64,   9655, 7705,
                      3929, 3588, 7397, 8020, 1311, 5676, 3469, 2325,
                      1226, 8203, 9524, 3648, 5278, 8647};

int main() {
    ll maxn = INT_MAX, maxi = 0;
    cout << (3 ^ 5) << "\n";
    for (ll i = 0; i <= 20000; ++i) {
        ll sum = 0;
        for (ll j = 0; j < 30; ++j) {
            sum += (i ^ all_a[j]) * (i ^ all_a[j]);
        }
        if (sum < maxn) maxn = sum, maxi = i;
    }
    cout << maxn << " " << maxi << "\n";
    return 0;
}