#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a, b, p;
vector<ll> all_p;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> a >> b >> p;
    for (int i = p; i <= b; ++i)
        if (isPrime(i)) all_p.push_back(i);
    return 0;
}