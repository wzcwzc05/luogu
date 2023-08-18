#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
void dfs(int t, int back)
{
    if (t >= 1)
    {
        for (int i = back; i <= t; i++)
        {
            ans.push_back(i);
            dfs(t - i, i);
            ans.pop_back();
        }
    }
    else
    {
        if (ans.size() > 1)
        {
            for (int i = 0; i < ans.size() - 1; i++)
            {
                cout << ans[i] << "+";
            }
            cout << ans[ans.size() - 1] << endl;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    dfs(n, 1);
    return 0;
}