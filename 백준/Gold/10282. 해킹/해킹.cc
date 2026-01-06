#include <climits>
#include <iostream>
#include <queue>

using namespace std;

int T, n, d, c;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int cDist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cDist) continue;

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nDist = graph[cur][i].second;
            if (dist[next] <= cDist + nDist) continue;
            dist[next] = cDist + nDist;
            pq.push({dist[next], next});
        }
    }
}

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n >> d >> c;
        graph = vector<vector<pair<int, int>>>(n + 1);
        dist = vector<int>(n + 1, INT_MAX);
        for (int i = 0; i < d; i++) {
            int a, b, s;
            cin >> a >> b >> s;
            graph[b].push_back({a, s});
        }

        dijkstra(c);
        int count = 0;
        int time = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) continue;
            count++;
            time = max(time, dist[i]);
        }
        cout << count << " " << time << "\n";
    }
}