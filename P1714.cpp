#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> v, pre;
ll n, m, ans;
int main()
{
    cin >> n >> m;
    v.push_back(0), pre.push_back(0);
    for (int i = 1; i <= n; ++i) {
        int temp;
        cin >> temp;
        v.push_back(temp);
        pre.push_back(v[i] + v[i - 1]);
    }
    ll left_p = 1, right_p = m;
    while (true) {
        
    }
    return 0;
}