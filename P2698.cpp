#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int minh[N], maxh[N], n, d, maxl;
bool vis[N];
bool check(int w)
{
    deque<int> maxq, minq;
    for (int i = 1; i < w; ++i) {
        while (!maxq.empty() && (maxh[maxq.back()] <= maxh[i]))
            maxq.pop_back();
        maxq.push_back(i);
        while (!minq.empty() && (minh[minq.back()] >= minh[i]))
            minq.pop_back();
        minq.push_back(i);
    }
    for (int i = w; i <= maxl; ++i) {
        if (vis[i]) {
            while (!maxq.empty() && (maxh[maxq.back()] <= maxh[i]))
                maxq.pop_back();
            maxq.push_back(i);
        }
        while (!maxq.empty() && maxq.front() <= i - w - 1)
            maxq.pop_front();
        if (vis[i]) {
            while (!minq.empty() && (minh[minq.back()] >= minh[i]))
                minq.pop_back();
            minq.push_back(i);
        }
        while (!minq.empty() && minq.front() <= i - w - 1)
            minq.pop_front();
        if (!maxq.empty() && !minq.empty() && maxh[maxq.front()] - minh[minq.front()] >= d) {
            return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        maxl = max(maxl, x);
        if (vis[x]) {
            minh[x] = min(minh[x], y);
            maxh[x] = min(maxh[x], y);
        } else {
            vis[x] = 1;
            minh[x] = y, maxh[x] = y;
        }
    }
    // for (int i = 1; i <= maxl; ++i)
    //     cout << vis[i] << " " << maxh[i] << " " << minh[i] << "\n";
    int l = 1, r = maxl, index = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            index = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << index << "\n";
    return 0;
}