#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
struct Node {
    int index = 0, value = 0;
};
Node tr[N][N];
int n, ans, t;
namespace xxx {
Node max(Node& a, Node& b)
{
    return a.value > b.value ? a : b;
}
Node min(Node& a, Node& b)
{
    return a.value < b.value ? a : b;
}
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    t = pow(2, n);
    for (int i = 1; i <= t; ++i)
        cin >> tr[1][i].value, tr[1][i].index = i;
    for (int i = 2; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= t; j += 2)
            tr[i][++count] = xxx::max(tr[i - 1][j], tr[i - 1][j + 1]);
    }
    cout << xxx::min(tr[n][1], tr[n][2]).index << "\n";
    return 0;
}