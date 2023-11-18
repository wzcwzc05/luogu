// dijkstra最短路
#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();

void dijkstra(const vector<vector<pair<int, int>>>& graph, int start, vector<int>& distances) {
    int n = graph.size();
    distances.assign(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distances[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int distance = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (distance > distances[current]) {
            continue;
        }

        for (auto& edge : graph[current]) {
            int next = edge.first;
            int nextDistance = distance + edge.second;

            if (nextDistance < distances[next]) {
                distances[next] = nextDistance;
                pq.push({nextDistance, next});
            }
        }
    }
}

int main() {
    // 示例：图的节点数量和边
    int n = 5; // 节点数量
    vector<vector<pair<int, int>>> graph(n);

    // 添加边 (u, v, w) 到图中
    // u 是起点, v 是终点, w 是权重
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 1});
    graph[1].push_back({3, 1});
    graph[2].push_back({1, 2});
    graph[2].push_back({3, 5});
    graph[3].push_back({4, 3});

    vector<int> distances;
    dijkstra(graph, 0, distances);

    for (int i = 0; i < n; ++i) {
        cout << "最短路径到达节点 " << i << " 的距离是: " << distances[i] << endl;
    }

    return 0;
}
