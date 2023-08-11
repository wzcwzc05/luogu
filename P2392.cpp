#include <bits/stdc++.h>
using namespace std;
int a[5][200], ans;
long long sum;
void dfs(int d, int left, int right, int t)
{
    if (t <= a[d][0])
    {
        dfs(d, left + a[d][t], right, t + 1);
        dfs(d, left, right + a[d][t], t + 1);
    }
    else
    {
        ans=min(ans,max(left,right));
    }
}
int main()
{
    for (int i = 1; i <= 4; i++)
        cin >> a[i][0];
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= a[i][0]; j++)
            cin >> a[i][j];
        ans = 2147483647;
        dfs(i, 0, 0, 1);
        sum+=ans;
    }
    cout<<sum<<endl;
    return 0;
}