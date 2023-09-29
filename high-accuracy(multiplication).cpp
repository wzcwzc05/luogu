#include <bits/stdc++.h>
using namespace std;
string st1, st2;
long long result[1000010], n;
int main()
{
    cin >> st1 >> st2;

    // 反转字符串
    reverse(st1.begin(), st1.end());
    reverse(st2.begin(), st2.end());

    // 乘法运算
    for (int i = 0; i <= st1.length() - 1; i++)
    {
        for (int j = 0; j <= st2.length() - 1; j++)
        {
            int a = st1[i] - '0';
            int b = st2[j] - '0';
            result[i + j] += a * b;
        }
    }

    // 进位操作
    for (int i = 0; i <= st1.length() + st2.length() - 2; i++)
    {
        if (result[i] >= 10)
        {
            result[i + 1] += result[i] / 10;
            result[i] = result[i] % 10;
        }
    }

    // 判断最后一位是否进位
    if (result[st1.length() + st2.length() - 1] == 0)
        n = st1.length() + st2.length() - 2;
    else
        n = st1.length() + st2.length() - 1;

    // 输出
    for (int i = n; i >= 0; i--)
    {
        cout << result[i];
    }
    cout << "\n";
    return 0;
}