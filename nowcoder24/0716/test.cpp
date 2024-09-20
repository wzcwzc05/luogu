#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

enum Direction { ABOVE, BELOW, LEFT, RIGHT };

Direction getNewDirection(Direction dir, char mirror) {
    if (mirror == '-') {
        if (dir == LEFT || dir == RIGHT)
            return dir;
        else if (dir == ABOVE)
            return BELOW;
        else
            return ABOVE;
    } else if (mirror == '|') {
        if (dir == ABOVE || dir == BELOW)
            return dir;
        else if (dir == LEFT)
            return RIGHT;
        else
            return LEFT;
    } else if (mirror == '/') {
        if (dir == LEFT) return BELOW;
        if (dir == RIGHT) return ABOVE;
        if (dir == ABOVE) return RIGHT;
        if (dir == BELOW) return LEFT;
    } else if (mirror == '\\') {
        if (dir == LEFT) return ABOVE;
        if (dir == RIGHT) return BELOW;
        if (dir == ABOVE) return LEFT;
        if (dir == BELOW) return RIGHT;
    }
    return dir;  // Should never reach here
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> maze(n);
    for (int i = 0; i < n; ++i) {
        cin >> maze[i];
    }

    int q;
    cin >> q;
    vector<int> results(q);

    for (int i = 0; i < q; ++i) {
        int u, v;
        string dir;
        cin >> u >> v >> dir;
        --u;
        --v;  // Convert to 0-based index

        Direction currentDir;
        if (dir == "above")
            currentDir = ABOVE;
        else if (dir == "below")
            currentDir = BELOW;
        else if (dir == "left")
            currentDir = LEFT;
        else if (dir == "right")
            currentDir = RIGHT;

        set<tuple<int, int, Direction>> visited;

        // Move to the first position based on the initial direction
        if (currentDir == ABOVE)
            --u;
        else if (currentDir == BELOW)
            ++u;
        else if (currentDir == LEFT)
            --v;
        else if (currentDir == RIGHT)
            ++v;

        while (u >= 0 && u < n && v >= 0 && v < m) {
            tuple<int, int, Direction> currentPosition =
                make_tuple(u, v, currentDir);
            if (visited.count(currentPosition) > 0) break;
            visited.insert(currentPosition);
            currentDir = getNewDirection(currentDir, maze[u][v]);

            if (currentDir == ABOVE)
                --u;
            else if (currentDir == BELOW)
                ++u;
            else if (currentDir == LEFT)
                --v;
            else if (currentDir == RIGHT)
                ++v;
        }

        results[i] = visited.size();

        // 输出visited集合的内容
        /*
        cout << "Query " << i + 1 << " visited mirrors: ";
        for (const auto& pos : visited) {
            cout << "(" << get<0>(pos) + 1 << ", " << get<1>(pos) + 1 << ", ";
            switch(get<2>(pos)) {
                case ABOVE: cout << "above"; break;
                case BELOW: cout << "below"; break;
                case LEFT: cout << "left"; break;
                case RIGHT: cout << "right"; break;
            }
            cout << ") ";
        }
        cout << endl;
        */
    }

    for (int res : results) {
        cout << res << endl;
    }

    return 0;
}
/*
2 3
/-\
\|/
1
2 1 right
*/