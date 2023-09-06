#include <bits/stdc++.h>
using namespace std;
char ch;
stack<int> s;
int main()
{
    cin >> ch;
    int t=0;
    while (ch != '@')
    {
        if (ch >= '0' && ch <= '9')
        {
            t=t*10+ch-'0';
        }
        else if (ch == '.')
        {
            s.push(t);
            t=0;
        }
        else
        {
            int a, b;
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();
            if (ch == '-')
                s.push(a - b);
            if (ch == '+')
                s.push(a + b);
            if (ch == '*')
                s.push(a * b);
            if (ch == '/')
                s.push(a / b);
        }
        cin>>ch;
    }
    cout<<s.top()<<endl;
    return 0;
}