#include <bits/stdc++.h>
using namespace std;
int n, i, j, k, ans;
string a[100], ansst;
char ch;
int flag[100];
int joinLength(string front, string tail)
{
    int len = min(front.length(), tail.length());
    int ans = -1;
    for (int i = 1; i <= len - 1; i++)
    {
        string temp1, temp2;
        temp2 = tail.substr(0, i);
        temp1 = front.substr(front.length() - i, i);
        if (temp1 == temp2)
        {
            ans = i;
            break;
        }
    }
    return ans;
}
string join(string front, string tail, int len)
{
    tail.erase(0, len);
    return front + tail;
}
void dfs(int dep, string st)
{
    if (st.length() >= ans)
    {
        ans = st.length();
        ansst = st;
    }
    for (int i = 1; i <= n; i++)
    {
        if (flag[i] < 2)
        {
            int temp = joinLength(st, a[i]);
            if (temp != -1)
            {
                string st1 = join(st, a[i], temp);
                flag[i] += 1;
                dfs(i, st1);
                flag[i] -= 1;
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> ch;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i][0] == ch)
        {
            for (int j = 1; j <= n; j++)
                flag[j] = 0;
            flag[i] = 1;
            dfs(i, a[i]);
        }
    }
    cout << ans << endl;
    return 0;
}