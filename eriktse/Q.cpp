#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, q;

int main()
{
    cin >> q;
    while (q--)
    {
        map<string, int> mp;
        vector<string> a;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            string temp;
            cin >> temp;
            if (mp[temp] != 0)
                mp[temp]++;
            else
            {
                a.push_back(temp);
                mp[temp] = 1;
            }
        }
        for (auto i = a.begin(); i != a.end(); ++i)
        {
            cout << *i << " " << mp[*i] << "\n";
        }
    }
    return 0;
}