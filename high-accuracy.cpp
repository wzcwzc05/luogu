#include <bits/stdc++.h>
using namespace std;
string st1, st2;
int result[1000010], n;
int main()
{
    cin >> st1 >> st2;

    // 反转字符串
    reverse(st1.begin(), st1.end());
    reverse(st2.begin(), st2.end());

    // 末尾补零
    if (st1.length() > st2.length())
    {
        string temp(st1.length() - st2.length(), '0');
        st2 += temp;
    }
    else
    {
        string temp(st2.length() - st1.length(), '0');
        st1 += temp;
    }

    //加法运算
    for (int i = 0; i <= st1.length() - 1; i++)
    {
        int a = st1[i] - '0';
        int b = st2[i] - '0';
        result[i] = a + b;
    }

    //进位操作
    for (int i = 0; i <= st1.length() - 1; i++)
    {
        if (result[i] >= 10)
        {
            result[i + 1] += 1;
            result[i] = result[i] % 10;
        }
    }

    //判断最后一位是否进位
    if (result[st1.length()] == 0)
        n = st1.length() - 1;
    else
        n = st1.length();
        
    //输出
    for (int i = n; i >= 0; i--)
    {
        cout << result[i];
    }
    cout << "\n";
    return 0;
}