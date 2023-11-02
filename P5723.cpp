#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e6 + 10;
ll n, sum, t, ans;
bool isPrime(ll x)
{
    if (x <= 0)
        return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int a=1;
    int* p=&a;
    cout<<*p<<endl;
    return 0;
}