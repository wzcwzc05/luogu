#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    double t;
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    for (int i = 1; i <= 20000000; i++)
        cin >> t;
    double temp = 0.04;
    for (int i = 1; i <= 20000000; i++)
        cout << (double)i + temp << " ";
    cout << "\n";
    return 0;
}