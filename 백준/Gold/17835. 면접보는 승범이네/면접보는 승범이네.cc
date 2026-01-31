#include <climits>
#include <iostream>
#include <queue>
#include <vector>
typedef long long ll;

using namespace std;

int N, M, K, u, v, c;

// 이거하면 시간초과 실화?
// struct cmp {
//     bool operator()(pair<ll, int>& p1, pair<ll, int>& p2) { return p1.first < p2.first; }
// };

vector<vector<pair<int, ll>>> graph;
vector<ll> minCost;
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    graph = vector<vector<pair<int, ll>>>(N + 1);
    minCost = vector<ll>(N + 1, LLONG_MAX);
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> c;
        graph[v].push_back({u, c});  // 역방향으로 해야됨! 조심!
    }

    for (int i = 0; i < K; i++) {
        cin >> u;
        pq.push({0, u});
        minCost[u] = 0;
    }

    while (!pq.empty()) {
        int cur = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();

        if (minCost[cur] < cost) continue;

        for (auto g : graph[cur]) {
            int next = g.first;
            ll nCost = g.second;
            if (minCost[next] <= cost + nCost) continue;
            minCost[next] = cost + nCost;
            pq.push({minCost[next], next});
        }
    }

    ll maxCost = 0;
    int maxCity = 0;
    for (int i = 1; i <= N; i++) {
        if (minCost[i] != LLONG_MAX && minCost[i] > maxCost) {
            maxCost = minCost[i];
            maxCity = i;
        }
    }
    cout << maxCity << "\n" << maxCost;
}

// 다익스트라 -> 여러 점에서 시작해도 된다!
// long long타입 벡터로 바꿔놓고 변수들은 long long으로 안바꿨다..