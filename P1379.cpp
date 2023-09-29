#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int a[5][5];        // 存储地图
int startx, starty; // 存储初始位置
void toMap(int num) // 实现将一个数字转化为地图
{
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
        {
            a[i][j] = num % 10;
            num /= 10;
            if (a[i][j] == 0) // 在转化地图过程中，如果发现“0”，那么记录初始位置
            {
                startx = i;
                starty = j;
            }
        }
}
int toNum() // 实现将地图转化为数字
{
    int num = 0;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            num = num * 10 + a[i][j];
        }
    }
    return num;
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}