#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e3 + 10;
string st;
ll n, m, k;
vector<ll> a;
int main()
{
    cin >> st >> k;
    n = st.length();
    for (int i = 0; i <= st.length() - 1; i++)
        a.push_back(st[i] - '0');
    a.push_back(0);
    for (int i = 1; i <= k; i++)
    {
        bool flag = 0;
        for (int i = 0; i <= a.size() - 2; i++)
        {
            if (a[i] > a[i + 1])
            {
                a.erase(a.begin() + i);
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            a.erase(a.end() - 2);
    }
    if (a.size() - 2 == 0)
    {
        cout << a[0] << "\n";
        return 0;
    }
    bool flag = 1;
    for (int i = 0; i <= a.size() - 2; i++)
        if (flag == 1 && a[i] != 0)
        {
            cout << a[i];
            flag = 0;
        }
        else if (flag == 0)
            cout << a[i];
    cout << "\n";
    return 0;
}