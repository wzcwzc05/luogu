#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
string s;
int main() {
    cin >> n >> k;
    cin >> s;
    for (char c = 'a'; c <= 'z'; c++) {
        ll d = k;
        int t = 0;
        int i;
        for (i = 0; i <= n; i++) {
            if (s[i] == c)
                t++;  // 符合条件，t++
            else {
                if (t) {
                    ll z = min(t, n - i);  // 取t和n-i的最小值
                    if (d > z * t) {  // 如果d>z*t，d减去z*t，i加上z-1，t置0
                        d -= z * t;
                        i += z - 1;
                        t = 0;
                    } else {
                        d %= z;
                        if (!d) d = z;
                        cout << s[i + d - 1];
                        d = 0;
                        t = 0;
                        break;
                    }
                } else if (i != n) {  // 如果t=0，i!=n，d--，如果d=0，输出s[i]
                    d--;
                    if (d == 0) {
                        cout << s[i];
                        break;
                    }
                }
            }
        }
        if (d) cout << "*";  // 如果d>0，输出*
    }
    return 0;
}
