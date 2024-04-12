#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[100010], n, k, prefix[10010];
bool cmp(int a, int b) { return a > b; }
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; ++i) prefix[i] += prefix[i - 1] + a[i];
    cout << lower_bound(prefix + 1, prefix + n + 1, n % k) - prefix << "\n";
    return 0;
}