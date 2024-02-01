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
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        int left_p = 0, right_p = n - 1, mid_p = 0;
        while (left_p < right_p)
        {
            mid_p = left_p + (right_p - left_p) / 2;
            if (vec[mid_p] >= temp)
                right_p = mid_p;
            else
                left_p = mid_p + 1;
        }
        if (vec[left_p] == temp)
            cout << left_p + 1 << " ";
        else
            cout << "-1 ";
    }
    cout << "\n";

    return 0;
}