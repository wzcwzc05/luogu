#include <bits/stdc++.h>
using namespace std;
void out(int hour, int minute)
{
    if (hour < 10)
        cout << "0" << hour << ":";
    else
        cout << hour << ":";
    if (minute < 10)
        cout << "0" << minute << endl;
    else
        cout << minute << endl;
    return;
}
int main()
{
    long long s, v, t;
    cin>>s>>v;
    if (s % v != 0)
        t = s / v + 1;
    else
        t = s / v;
    t += 10;
    int hour = t / 60, left = 8;
    int minute = t % 60;
    while (true)
    {
        if (left - hour > 0)
        {
            out(left - hour - 1, 60 - minute);
            break;
        }
        hour -= left;
        left = 24;
    }
    return 0;
}