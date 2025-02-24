#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
struct crime_pair {
    int x, y, v;
};
crime_pair a[N];
ll n, m;
bool cmp(crime_pair &a, crime_pair &b) { return a.v < b.v; }
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].v;
    }
    sort(a + 1, a + m + 1, cmp);
    return 0;
}