// 1238

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, X, u, v, t;

vector<pair<int, int>> graph[1001];
int dist[1001][1001];

void dijk(int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, n});
    dist[n][n] = 0;

    while (!pq.empty())
    {
        int cur_node = pq.top().second;
        int cur_dist = pq.top().first;
        pq.pop();

        for (int i = 0; i < graph[cur_node].size(); i++)
        {
            int next_node = graph[cur_node][i].first;
            int next_dist = graph[cur_node][i].second;
            if (next_dist + cur_dist > dist[n][next_node])
                continue;
            dist[n][next_node] = next_dist + cur_dist;
            pq.push({dist[n][next_node], next_node});
        }
    }
}

int main()
{
    cin >> N >> M >> X;

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> t;
        graph[u].push_back({v, t});
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dist[i][j] = 99999999;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        dijk(i);
    }

    int max_time = 0;
    for (int i = 1; i <= N; i++)
    {
        max_time = max(max_time, dist[i][X] + dist[X][i]);
    }

    cout << max_time;
}
