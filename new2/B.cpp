#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
string str;
char ans[N];
int l, r, top;
int main()
{
    cin >> str;
    if (str.size() < 3)
    {
        cout << str << "\n";
        return 0;
    }
    ans[1] = str[0], ans[2] = str[1];
    top = 2;
    for (int i = 2; i <= str.size() - 1; i++)
    {
        if (str[i] == 'C' && ans[top] == 'B' && ans[top - 1] == 'A')
        {
            top -= 2;
            continue;
        }
        else
        {
            top++;
            ans[top] = str[i];
        }
    }
    for (int i = 1; i <= top; i++)
        cout << ans[i];
    cout << "\n";
    return 0;
}