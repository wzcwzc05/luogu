#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
struct Node {
    int left = 0, right = 0;
};
Node tree[N];
int n, ans;
void dfs(int dep, int index)
{
    if (tree[index].left == 0 && tree[index].right == 0) {
        ans = max(ans, dep);
        return;
    }
    dfs(dep + 1, tree[index].left);
    dfs(dep + 1, tree[index].right);
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> tree[i].left >> tree[i].right;
    dfs(1, 1);
    cout << ans << "\n";
    return 0;
}