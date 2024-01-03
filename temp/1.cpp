#include <bits/stdc++.h>
using namespace std;
string str1, str2;
int main()
{
    cin >> str1 >> str2;
    str1 += str2;
    sort(str1.begin(), str1.end());
    cout << str1 << "\n";
    return 0;
}