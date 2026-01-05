#include <climits>
#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int N, M;

struct edge {
    int from;
    int to;
    int weight;
};

vector<ll> dist;
vector<edge> edges;

int main() {
    cin >> N >> M;
    dist = vector<ll>(N + 1, LLONG_MAX);
    dist[1] = 0;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    for (int i = 1; i <= N - 1; i++) {
        for (int j = 0; j < edges.size(); j++) {
            if (dist[edges[j].from] == LLONG_MAX) continue;
            if (dist[edges[j].to] <= dist[edges[j].from] + edges[j].weight)
                continue;
            dist[edges[j].to] = dist[edges[j].from] + edges[j].weight;
        }
    }

    for (int j = 0; j < edges.size(); j++) {
        if (dist[edges[j].from] == LLONG_MAX) continue;
        if (dist[edges[j].to] <= dist[edges[j].from] + edges[j].weight)
            continue;
        cout << -1;
        return 0;
    }

    for (int i = 2; i <= N; i++) {
        if (dist[i] == LLONG_MAX)
            cout << -1 << "\n";
        else
            cout << dist[i] << "\n";
    }
}