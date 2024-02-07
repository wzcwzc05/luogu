#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, i, sum;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    while (cin >> n)
        sum += n, i++;
    sum *= pow(2, i - 1);
    cout << sum << "\n";
    return 0;
}