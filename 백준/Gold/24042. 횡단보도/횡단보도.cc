#include <climits>
#include <iostream>
#include <queue>
#include <vector>
typedef long long ll;

using namespace std;

int main() {
    int N, M, u, v;
    cin >> N >> M;
    vector<vector<pair<int, int>>> graph(N + 1);
    vector<ll> dist(N + 1, LLONG_MAX);
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
    }

    dist[1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        pair<ll, int> tmp = pq.top();
        pq.pop();
        int cur = tmp.second;
        ll cDist = tmp.first;

        if (cur == N) {
            cout << cDist;
            return 0;
        }

        if (cDist > dist[cur]) continue;

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nDist = graph[cur][i].second;
            nDist = (nDist - (cDist % M) + M) % M;
            if (dist[next] > cDist + nDist + 1) {
                dist[next] = cDist + nDist + 1;
                pq.push({dist[next], next});
            }
        }
    }
}