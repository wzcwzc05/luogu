#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, a[N];
stack<int> stk;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int t = 2, now = 1;
    stk.push(a[1]);
    while (true)
    {
        if (!stk.empty() && stk.top() == now)
        {
            stk.pop();
            now++;
            continue;
        }
        if (t > n)
            break;
        stk.push(a[t]);
        t++;
    }
    if (now >= n)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}