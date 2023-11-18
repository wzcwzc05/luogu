// 动态规划（滑雪）
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int x;
    int y;
    int h;
}; // 一个结构体记录这个点的位置和高度

struct cmpl
{
    bool operator()(const Node a, const Node b) const
    {
        return a.h < b.h;
    }
}; // 优先队列的比较函数

priority_queue<Node, vector<Node>, cmpl> pq;
int d[105][105], a[105][105];
int n, m, i, j;
int main()
{
    scanf("%d %d", &n, &m);
    int k = 0, t;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            cin >> t;
            Node q;
            q.x = i;
            q.y = j;
            q.h = t;
            pq.push(q); // 将这个元素入队，STL会自动将它从小到大排好
            d[i][j] = 1;
            a[i][j] = t;
        }
    int maxn = INT_MIN;
    while (!pq.empty())
    {
        Node tmp = pq.top(); // 依次出队并更新最小值
        int ans = 1, x1 = tmp.x, y1 = tmp.y, h1 = tmp.h;
        if (a[x1 + 1][y1] > h1)
            ans = max(ans, d[x1 + 1][y1] + 1);
        if (a[x1 - 1][y1] > h1)
            ans = max(ans, d[x1 - 1][y1] + 1);
        if (a[x1][y1 + 1] > h1)
            ans = max(ans, d[x1][y1 + 1] + 1);
        if (a[x1][y1 - 1] > h1)
            ans = max(ans, d[x1][y1 - 1] + 1);
        d[x1][y1] = ans;
        maxn = max(maxn, ans);
        pq.pop();
    }
    cout << maxn << endl;
    return 0;
}