#include <bits/stdc++.h>
using namespace std;
vector<int> a, b, c;
map<int, int> mp;
int n, m;
bool isdivisor(int x, int y)
{
    return y % x == 0;
}
void output(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        for (int j = 1; j <= m; j++)
        {
            int temp;
            cin >> temp;
            a.push_back(temp);
        }
        sort(a.begin(), a.end());
        int temp = a[0],t=0;
        for (int j = 0; j <= m; j++)
        {
            if (a[j] == temp)
            {
                b.push_back(a[j]);
                t++;
            }
            else
                break;
        }
        a.erase(a.begin(), a.begin() + t);
        if (a.size() >= 2)
        {
            c.push_back(a[0]);
            a.erase(a.begin(), a.begin() + 1);
        }
        else
        {
            c.push_back(a[0]);
            a.clear();
        }
        if (!a.empty())
        {
            for (int j = 0; j < a.size(); j++)
            {
                bool flag = true;
                for (int k = 0; k < c.size(); k++)
                {
                    if (!isdivisor(c[k], a[j]))
                    {
                        b.push_back(a[j]);
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    c.push_back(a[j]);
                }
            }
        }
        
        if ((b.size() < 1) || (c.size() < 1))
        {
            cout << -1 << endl;
           goto stop;
        }
        for (int j = 0; j < b.size(); j++)
        {
            for (int k = 0; k < c.size(); k++)
            {
                if (isdivisor(c[k], b[j]))
                {
                    cout << -1 << endl;
                    goto stop;
                }
            }
        }
        cout << b.size() << " " << c.size() << endl;
        for (int j = 0; j < b.size(); j++)
        {
            cout << b[j] << " ";
        }
        cout << endl;
        for (int j = 0; j < c.size(); j++)
        {
            cout << c[j] << " ";
        }
        cout << endl;
        stop:
        a.clear();
        b.clear();
        c.clear();
    }
    return 0;
}