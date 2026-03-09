#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 10;
struct Node {
    int num, count;
};
Node a[N];
int n, m;
int count(int n) {
    int res = 0;
    while (n != 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}
bool cmp(const Node& a, const Node& b) { return a.count < b.count; }
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        a[i].num = i;
        a[i].count = count(i);
    }
    stable_sort(a + 1, a + n + 1, cmp);
    cout << a[m].num << "\n";
    return 0;
}