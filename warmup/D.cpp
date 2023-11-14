#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int q, n, m, step1, step2;
int startx, starty, keyx, keyy, endx, endy;
int mp[501][501], temp[501][501];
bool vis[501][501][3];
int dx[5] = {1, 0, -1, 0};
int dy[5] = {0, 1, 0, -1};
struct node // 结构体，用于存储节点，x,y为坐标,step为步数，isKey代表是否走过钥匙
{
    int x;
    int y;
    int step;
    bool isKey;
};

int main()
{
    int q;
    cin >> q;
    for (int k = 1; k <= q; k++)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // 标记数组清零
                vis[i][j][0] = 0;
                vis[i][j][1] = 0;

                char ch;
                cin >> ch;
                if (ch == '.')
                    mp[i][j] = 0;
                if (ch == '#')
                    mp[i][j] = 1;
                if (ch == 'P')
                {
                    startx = i, starty = j;
                    mp[i][j] = 0; // 记录起点位置
                }
                if (ch == 'K')
                {
                    mp[i][j] = 2; // 数组中2代表该位置为key
                }
                if (ch == 'E')
                {
                    endx = i, endy = j;
                    mp[i][j] = 1; // 记录终点位置
                }
            }
        }
        queue<node> q; // 队列
        node start;
        start.x = startx, start.y = starty, start.step = 0, start.isKey = 0;
        q.push(start);  // 起点加入队列
        step1 = -1;
        while (!q.empty())
        {
            int x = q.front().x;
            int y = q.front().y;
            int step = q.front().step;
            bool key = q.front().isKey;

            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx == endx && yy == endy && key == 1)   // 如果已经到达终点且路径经过key，直接结束
                {
                    step1 = step + 1;
                    break;
                }
                if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && mp[xx][yy] != 1)    //如果下一步节点在范围内且不为墙
                {
                    node next;
                    if (mp[xx][yy] == 2)    // 如果该位置是key，那么改变node的key标记，如果不是，从上个节点继承
                        next.isKey = 1;
                    else
                        next.isKey = key;
                    if (vis[xx][yy][next.isKey])    // 被访问过直接跳过
                        continue;
                    vis[xx][yy][next.isKey] = 1;    // 标记已被访问
                    next.x = xx;
                    next.y = yy;
                    next.step = step + 1;
                    q.push(next);   // 加入队列
                }
            }
            if (step1 != -1)    //
                break;
        }
        if (step1 == -1)
        {
            cout << "No solution\n";
            continue;
        }

        cout << step1 << "\n";
    }
    return 0;
}