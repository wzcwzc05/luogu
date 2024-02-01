#include <bits/stdc++.h>
using namespace std;
bool check(int x, int y, int z)
{
    int _hash[12];
    for (int i = 0; i <= 9; i++)
        _hash[i] = 0;
    while (x != 0)
    {

        if (_hash[x % 10] != 0 || x % 10 == 0)
            return false;
        else
            _hash[x % 10] = 1;
        if (_hash[y % 10] != 0 || y % 10 == 0)
            return false;
        else
            _hash[y % 10] = 1;
        if (_hash[z % 10] != 0 || z % 10 == 0)
            return false;
        else
            _hash[z % 10] = 1;
        x /= 10, y /= 10, z /= 10;
    }
    return true;
}
int main()
{
    for (int i = 100; i <= 333; i++)
    {
        int b = i * 2;
        int c = i * 3;
        if (check(i, b, c))
            cout << i << " " << b << " " << c << "\n";

    }
    return 0;
}