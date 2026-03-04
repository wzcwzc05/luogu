#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 10;
struct Node {
    ll id = 0;
    ll a = 0;
    ll b = 0;
};
ll n;
Node orders[N], n_1[N], n_2[N];
bool cmp(Node first, Node second) {
    if (first.a >= first.b && second.a >= second.b) {
        return first.b > second.b;
    }
    if (first.a < first.b && second.a < second.b) {
        return first.a > first.a;
    }
    if (first.a >= first.b && second.a < second.b) {
        return 0;
    } else {
        return 1;
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        ll tmp;
        cin >> tmp;
        orders[i].a = tmp, orders[i].id = i;
    }
    for (int i = 1; i <= n; ++i) {
        ll tmp;
        cin >> tmp;
        orders[i].b = tmp;
    }
    sort(orders + 1, orders + n + 1, cmp);
    ll sum_a = 0, sum_b = 0;
    for (int i = 1; i <= n; ++i) {
        sum_a += orders[i].a;
        sum_b += orders[i].b;
        // cout << i << " " << sum_a << " " << sum_b << "\n";
        if (sum_a >= sum_b) sum_b = sum_a;
    }
    cout << max(sum_a, sum_b) + orders[n].b << "\n";
    for (int i = 1; i <= n; ++i) cout << orders[i].id << " ";
    cout << "\n";
    return 0;
}