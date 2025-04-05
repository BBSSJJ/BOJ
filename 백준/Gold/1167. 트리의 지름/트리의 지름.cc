
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int V, a, b, c;
int answer, target;
vector<bool> visited;
vector<vector<pair<int, int>>> graph;

void dfs(int cur, int total) {
    if (answer < total) {
        answer = total;
        target = cur;
    }

    for (int i = 0; i < graph[cur].size(); i++) {
        int next = graph[cur][i].first;
        int cost = graph[cur][i].second;
        if (visited[next]) continue;
        visited[next] = true;
        dfs(next, total + cost);
        visited[next] = false;
    }
}

int main() {
    cin >> V;

    graph = vector<vector<pair<int, int>>>(V + 1, vector<pair<int, int>>());
    visited = vector<bool>(V + 1, false);

    for (int i = 1; i <= V; i++) {
        cin >> a;
        while (true) {
            cin >> b;
            if (b == -1) break;
            cin >> c;
            graph[a].push_back({b, c});
        }
    }

    visited[1] = true;
    dfs(1, 0);
    answer = 0;

    visited = vector<bool>(V + 1, false);
    visited[target] = true;
    dfs(target, 0);
    cout << answer << endl;
}