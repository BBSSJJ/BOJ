#include <iostream>
#include <queue>
#include <stack>

using namespace std;
int N, M, u, v, w, start, finish;
vector<pair<int, int>> graph[1001];
int cost[1001];
int pre[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra() {
    cost[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cur = pq.top().second;
        int c = pq.top().first;
        pq.pop();

        if (cost[cur] != c) continue;

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nc = graph[cur][i].second;
            if (cost[next] > cost[cur] + nc) {
                cost[next] = cost[cur] + nc;
                pre[next] = cur;
                pq.push({cost[cur] + nc, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cost[i] = 100000000;
    }

    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    cin >> start >> finish;

    dijkstra();

    int tmp = finish;
    vector<int> route;
    route.push_back(finish);

    while (tmp != start) {
        int parent = pre[tmp];
        route.push_back(parent);
        if (parent == start)
            break;
        else
            tmp = parent;
    }
    cout << cost[finish] << "\n";
    cout << route.size() << "\n";

    for (int i = route.size() - 1; i >= 0; i--) {
        cout << route[i] << " ";
    }
}