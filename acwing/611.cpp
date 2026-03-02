#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int id, n;
    double s, ans = 0;
    cin >> id >> n >> s;
    ans += n * s;
    cin >> id >> n >> s;
    ans += n * s;
    cout << "VALOR A PAGAR: R$ " << fixed << setprecision(2) << ans << "\n";
    return 0;
}