#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, q, a, b, h;
bool hs[N];
int startx, starty, endx, endy;
vector<int> interval, interval2;
int count_x(int start1, int end1)
{
    if (start1 >= end1)
        return b * (start1 - end1);
    else
        return a * (end1 - start1);
}
int main()
{
    cin >> h >> n >> q >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        hs[t] = 1;
        interval.push_back(t);
    }
    sort(interval.begin(), interval.end());
    interval2 = interval;
    reverse(interval2.begin(), interval2.end());
    while (q--)
    {
        cin >> startx >> starty >> endx >> endy;
        if (startx == endx)
        {
            cout << count_x(starty, endy) << "\n";
            continue;
        }
        int ans = INT_MAX;
        vector<int>::iterator t = lower_bound(interval.begin(), interval.end(), starty);
        if (t != interval.end())
            ans = min(ans, count_x(starty, *t) + count_x(*t, endy));
        else if (hs[*interval.end()] == 1)
            ans = min(ans, count_x(starty, *t) + count_x(*t, endy));
        /*t = lower_bound(interval.begin(), interval.end(), endy);
        if (t != interval.end())
            ans = min(ans, count_x(starty, *t) + count_x(*t, endy));
        else if (hs[*interval.end()] == 1)
            ans = min(ans, count_x(starty, *t) + count_x(*t, endy));*/
        t = lower_bound(interval2.begin(), interval2.end(), starty, greater<int>());
        if (t!=interval2.end())
        ans = min(ans, count_x(starty, *t) + count_x(*t, endy));
        else if (hs[*interval2.end()]==1)
        ans = min(ans, count_x(starty, *t) + count_x(*t, endy));
        /*t = lower_bound(interval2.begin(), interval2.end(), endy, greater<int>());
        ans = min(ans, count_x(starty, *t) + count_x(*t, endy));
        if (t!=interval2.end())
        ans = min(ans, count_x(starty, *t) + count_x(*t, endy));
        else if (hs[*interval2.end()]==1)
        ans = min(ans, count_x(starty, *t) + count_x(*t, endy));*/
        cout << ans << "\n";
    }
    return 0;
}