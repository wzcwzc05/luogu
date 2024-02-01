#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> vec;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    for (int i = 0; i < m; ++i)
    {
        int temp;
        cin >> temp;
        int pos = lower_bound(vec.begin(), vec.end(), temp) - vec.begin() + 1;
        if (vec[pos - 1] != temp)
            cout << "-1 ";
        else
            cout << pos << " ";
    }
    cout << "\n";
    return 0;
}