#include <bits/stdc++.h>
using namespace std;
double x, y, c, l, r, mid;
bool check(double a) {
    double h_x = sqrt(x * x - a * a);
    double h_y = sqrt(y * y - a * a);
    double h = h_x * (h_y / (h_x + h_y));
    // cout << a << "vs" << h_x << " " << h_y << " " << '\n';
    return h - c > 1e-5;
}
int main() {
    // ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> x >> y >> c;
    l = 0, r = min(x, y);
    // cout << mid << " " << l << " " << r << "\n";
    while (r - l > 1e-4) {
        mid = (l + r) / 2;
        // cout << mid << " " << l << " " << r << "\n";
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << fixed << setprecision(3) << l << "\n";
    return 0;
}