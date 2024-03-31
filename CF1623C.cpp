#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
ll q, n, a[N], b[N];
bool check(int num) {
  for (int i = n; i >= 3; --i) {
    if (a[i] - num < 0) return false;
    int d = min(a[i] - num, b[i]) / 3;
    a[i] -= 3 * d;
    a[i - 1] += d;
    a[i - 2] += 2 * d;
  }
  for (int i = 1; i <= n; ++i)
    if (a[i] < num) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> q;
  while (q--) {
    cin >> n;
    ll l = 1, r = 1e9 + 1;
    for (int i = 1; i <= n; ++i) cin >> a[i], b[i] = a[i];
    while (l <= r) {
      int mid = (r + l) / 2;
      if (check(mid)) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
      for (int i = 1; i <= n; ++i) a[i] = b[i];
    }
    cout << l - 1 << "\n";
  }
  return 0;
}