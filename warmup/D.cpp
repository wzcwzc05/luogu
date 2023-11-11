#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int q, n, m, step1, step2;
int startx, starty, keyx, keyy, endx, endy;
int mp[501][501], temp[501][501];
bool vis[501][501][3];
int dx[5] = {1, 0, -1, 0};
int dy[5] = {0, 1, 0, -1};
struct node
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
                    mp[i][j] = 0;
                }
                if (ch == 'K')
                {
                    mp[i][j] = 2;
                }
                if (ch == 'E')
                {
                    endx = i, endy = j;
                    mp[i][j] = 1;
                }
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                temp[i][j] = mp[i][j];
        /*for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cout << mp[i][j] << " ";
            cout << "\n";
        }
        break;*/
        queue<node> q;
        node start;
        start.x = startx, start.y = starty, start.step = 0, start.isKey = 0;
        q.push(start);
        step1 = -1;
        while (!q.empty())
        {
            int x = q.front().x;
            int y = q.front().y;
            int step = q.front().step;
            bool key = q.front().isKey;

            if (x == endx && y == endy)
            {
                step1 = step;
                break;
            }
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx==endx && yy==endy && key==1)
                {
                    //cout << "yes\n";
                    step1 = step+1;
                    break;
                }
                if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && mp[xx][yy] != 1)
                {
                    node next;
                    if (mp[xx][yy] == 2)
                        next.isKey = 1;
                    else
                        next.isKey = key;
                    if (vis[xx][yy][next.isKey])
                        continue;
                    if (xx == endx && yy == endy && vis[xx][yy][1])
                        continue;
                    vis[xx][yy][next.isKey] = 1;
                    next.x = xx;
                    next.y = yy;
                    next.step = step + 1;
                    q.push(next);
                }
            }
            if (step1!=-1)
            break;
            // cout<<q.front().x<<" "<<q.front().y<<" "<<q.front().step<<"\n";
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