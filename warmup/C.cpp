#include <bits/stdc++.h>
using namespace std;
long long n, a, b, c, t;
int main()
{
    cin >> n;
    t = n;
    bool flag = 1;
    for (int i = 1; i <= n + 1; i++)
    {
        cin >> a;
        if (t == 0 && a != 0 && flag == 0)
        {
            if (a > 0)
                cout << "+" << a;
            else
                cout << a;
            break;
        }
        if (t == 1 && a != 0 && flag == 0)
        {
            if (a > 0 && a != 1)
                cout << "+" << a << "x";
            else if (a == 1)
                cout << "+x";
            else if (a == -1)
                cout << "-x";
            else if (a < 0)
                cout << a << "x";
            t--;
            flag=0;
            continue;
        }
        if (a != 0 && flag == 1)
        {
            if (t != 1 && t != 0)
            {
                if (a > 0 && a != 1)
                    cout << a << "x^" << t;
                else if (a == 1)
                    cout << "x^" << t;
                else if (a == -1)
                    cout << "-x^" << t;
                else if (a < 0)
                    cout << a << "x^" << t;
                flag=0;
                t--;
                continue;
            }
            if (t == 1)
                if (a > 0 && a != 1)
                    cout << a << "x";
                else if (a == 1)
                    cout << "x";
                else if (a == -1)
                    cout << "-x";
                else if (a < 0)
                    cout << a << "x";
            if (t == 0)
            {
                cout << a;
                flag=0;
                t--;
                continue;
            }
            flag = 0;
        }
        else if (a != 0 && flag == 0)
        {
            if (a > 0 && a != 1)
                cout << "+" << a << "x^" << t;
            else if (a == 1)
                cout << "+x^" << t;
            else if (a == -1)
                cout << "-x^" << t;
            else if (a < 0)
                cout << a << "x^" << t;
        }
        t--;
    }
    if (flag == 1)
        cout << 0;
    cout << "\n";
    return 0;
}