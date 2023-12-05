#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int n, a[N];
int main()
{
    cin >> n;
    stack<int> stk;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        while (!stk.empty() && t <= stk.top())
            stk.pop();
        if (stk.empty())
            a[i] = -1;
        else
            a[i] = stk.top();
        stk.push(t);
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << "\n";
    return 0;
}