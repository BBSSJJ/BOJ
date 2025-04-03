#include <climits>
#include <iostream>
#include <queue>

using namespace std;

int N, M, u, v, cost, from, to;

int main() {
    cin >> N >> M;
    vector<vector<pair<int, int>>> route(N + 1);
    vector<int> dist(N + 1, INT_MAX);
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> cost;
        route[u].push_back({v, cost});
    }
    cin >> from >> to;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[from] = 0;
    pq.push({0, from});

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cdist = pq.top().first;
        pq.pop();

        if (dist[cur] < cdist) continue;

        for (int i = 0; i < route[cur].size(); i++) {
            int next = route[cur][i].first;
            int ndist = route[cur][i].second;
            if (dist[cur] + ndist >= dist[next]) continue;
            dist[next] = dist[cur] + ndist;
            pq.push({dist[next], next});
        }
    }

    cout << dist[to] << endl;
}
