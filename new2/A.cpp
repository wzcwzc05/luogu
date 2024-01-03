#include <bits/stdc++.h>
using namespace std;
int n, t, ans;
bool isPrime(int s)
{
    for (int i = 2; i * i <= s; i++)
        if (s % i == 0)
            return false;
    return true;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        if (t == 1)
            continue;
        long long temp = (int)sqrt(t);
        if (temp * temp == t && isPrime(temp))
            ans++;
    }
    cout << ans << "\n";
    return 0;
}