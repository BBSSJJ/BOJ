#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, u, v;
vector<vector<int>> graph;
vector<vector<int>> dp;
vector<bool> visited;

void dfs(int cur) {
    visited[cur] = true;
    dp[cur][1] = 1;
    for (int i = 0; i < graph[cur].size(); i++) {
        int next = graph[cur][i];
        if (visited[next]) continue;
        dfs(next);
        dp[cur][0] += dp[next][1];
        dp[cur][1] += min(dp[next][0], dp[next][1]);
    }
}

int main() {
    cin >> N;
    graph = vector<vector<int>>(N + 1);
    visited = vector<bool>(N + 1, false);
    dp = vector<vector<int>>(N + 1, vector<int>(2, 0));

    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);
    cout << min(dp[1][0], dp[1][1]);
}