#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
vector<int> a;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for (auto &i : a)
        cout << i << " ";
    return 0;
}