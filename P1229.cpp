#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str1, str2;
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> str1 >> str2;
    int t = 0;
    for (int i = 0; i < str1.size(); ++i)
        for (int j = 1; j < str2.size(); ++j)
            if (str1[i] == str2[j] && str1[i + 1] == str2[j - 1])
                ++t;
    cout << pow(2,t) << "\n";
    return 0;
}