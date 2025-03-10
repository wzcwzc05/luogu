#include <bits/stdc++.h>
using namespace std;
const string a = {"yizhong"};
string str;
char nn[110][110];
int n, x, y, flag;
int rec[110][110];
int xx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int yy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
void dfs(int x, int y, int depth) {
    if (x >= n || x < 0 || y < 0 || y >= n) {
        return;
    }
    if (depth == 7) {
        flag = 1;
        return;
    }
    if (nn[x][y] == a[depth]) {
        for (int i = 0; i < 8; i++) {
            dfs(x + xx[i], y + yy[i], depth + 1);
        }
    } else
        return;
    if (flag == 1) {
        rec[x][y] = 1;
    }
}
int main(void) {
    cin >> n;
    getline(cin, str);
    for (int i = 0; i < n; ++i) {
        getline(cin, str);
        for (int j = 0; j < n; j++) {
            nn[i][j] = str[j];
        }
    }
    flag = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (nn[i][j] == a[0]) {
                dfs(i, j, 0);
                flag = 0;
            }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (rec[i][j] == 0) nn[i][j] = '*';
            cout << nn[i][j];
        }
        cout << endl;
    }
    return 0;
}