#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m;
char ch1, ch2;
int main()
{
    cin >> ch1 >> ch2;
    int a = ch1 - 'A';
    int b = ch2 - 'A';
    int s = a + b;
    int gw = s % 26;
    int sw = s / 26;
    char ch3 = gw + 'A';
    char ch4 = sw + 'A';
    if (ch4 != 'A')
        cout << ch4 << ch3 << "\n";
    else
        cout << ch3 << "\n";
    return 0;
}