#include <bits/stdc++.h>
using namespace std;
int a, b, ans, n;
int main()
{
    cin >> n;
    cin >> b;
    for (int i = 2; i <= n; i++)
    {
        cin >> a;
        if (b - a <= 0)
            ans += a - b;
        b = a;
    }
    cout << ans << endl;
    return 0;
}