#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, p;
double a[N], b[N];
bool check(double num) {
    double count = num * p;
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        // cout << count << " " << a[i] * num << " " << b[i] << "\n";
        if (a[i] * num - b[i] > 0) sum += a[i] * num - b[i];
    }
    return sum <= count;
}
int main() {
    // 冒泡排序
    double l = INT_MAX, r = INT_MIN, flag = 0;
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> p;
    double count = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        count += a[i];
    }
    if (count <= p) {
        cout << -1 << "\n";
        return 0;
    }
    l = 0, r = 1e10;
    while (r - l > 1e-6) {
        // cout << l << " " << r << "\n";
        double mid = (r + l) / 2;
        // cout << mid << "\n";
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << "\n";
    return 0;
}