#include <bits/stdc++.h>
using namespace std;
using ll = long long;
double p1, p2, p3, p4, p5;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> p1 >> p2 >> p3 >> p4 >> p5;
    double t1 = p1 + p2 + p3, t2 = p4 + p5;
    cout << fixed << setprecision(10)
         << 1.0 - pow(t1, 10) - 10 * pow(t1, 9) * t2 << "\n";
    return 0;
}