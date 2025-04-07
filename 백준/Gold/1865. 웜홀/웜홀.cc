#include <climits>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
int TC, N, M, W, S, E, T;

int main() {
    cin >> TC;
    while (TC--) {
        cin >> N >> M >> W;
        vector<int> dist(N + 1, 1000000000);
        vector<tuple<int, int, int>> edges;
        for (int i = 0; i < M; i++) {
            cin >> S >> E >> T;
            edges.push_back({S, E, T});
            edges.push_back({E, S, T});
        }
        for (int i = 0; i < W; i++) {
            cin >> S >> E >> T;
            edges.push_back({S, E, -T});
        }

        // 벨만 포드
        dist[1] = 0;
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < edges.size(); j++) {
                if (dist[get<0>(edges[j])] == INT_MAX) continue;
                dist[get<1>(edges[j])] = min(dist[get<1>(edges[j])], dist[get<0>(edges[j])] + get<2>(edges[j]));
            }
        }

        bool can = false;
        for (int j = 0; j < edges.size(); j++) {
            if (dist[get<0>(edges[j])] == INT_MAX) continue;
            if (dist[get<1>(edges[j])] > dist[get<0>(edges[j])] + get<2>(edges[j])) {
                can = true;
                break;
            }
        }
        if (can)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}