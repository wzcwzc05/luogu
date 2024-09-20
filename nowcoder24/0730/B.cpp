#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m, a, b, q;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> q;
    while (q--) {
        cin >> n >> m >> a >> b;
        if ((n==2 && m==1) || (n==1 && m==2)) {
            cout << "Yes\n";
            continue;
        }
        if (n % 2 != 0 && m % 2 != 0) {
            cout << "No\n";
            continue;
        }
        if (a == 1 && b == 1) {
            cout << "No\n";
            continue;
        }
        if (a == 1 && b == 0) {
            if (n % 2 == 0 || m % 2 == 0)
                cout << "Yes\n";
            else
                cout << "No\n";
            continue;
        }
        if (a == 0 && b == 1) {
            if (n % 2 == 0 || m % 2 == 0)
                cout << "Yes\n";
            else
                cout << "No\n";
            continue;
        }
        if (a == 0 && b == 0) {
            cout << "Yes\n";
            continue;
        }
    }
    return 0;
}