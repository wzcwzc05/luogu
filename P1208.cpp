#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m;
struct node
{
    ll value, num;
};
vector<node> vec;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        node temp;
        cin >> temp.value >> temp.num;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end(), [](const node &a, const node &b)
         { return a.value < b.value; });
    ll ans = 0;
    for (auto &i : vec)
    {
        if (n >= i.num)
        {
            n -= i.num;
            ans += i.num * i.value;
        }
        else
        {
            ans += n * i.value;
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}