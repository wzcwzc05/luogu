#include <bits/stdc++.h>
using namespace std;
int a[10], b[10], pass, penlty;
int main()
{
    cin >> a[1] >> b[1] >> a[2] >> b[2] >> a[3] >> b[3];
    cin >> pass >> penlty;
    int i;
    for (i = 1; i <= 3; i++)
    {
        if (pass > a[i])
            break;
        else if (pass == a[i] && penlty <= b[i])
            break;
    }
    if (i == 1)
        cout << "Gold\n";
    if (i == 2)
        cout << "Silver\n";
    if (i == 3)
        cout << "Bronze\n";
    if (i == 4)
        cout << "Honorable\n";
    return 0;
}