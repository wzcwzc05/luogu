#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m;
vector<ll> v;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        ll temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    cout << v[m] << "\n";
    return 0;
}