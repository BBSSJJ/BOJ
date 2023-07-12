#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, u, v;
vector<int> graph[100001];
int indegree[32001];

vector<int> start_node;

int main()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        indegree[v]++;
        graph[u].push_back(v);
    }

    // 위상정렬

    /*
    vector<int> sorted;
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            sorted.push_back(i);
            for (int j = 0; j < graph[i].size(); j++) {
                indegree[graph[i][j]] -= 1;
                if (indegree[graph[i][j]] == 0)
                    sorted.push_back(graph[i][j]);
            }
        }
    }
    */

    queue<int> q;
    vector<int> sorted;

    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int cur = q.front();
        sorted.push_back(cur);
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++)
        {
            indegree[graph[cur][i]] -= 1;
            if (indegree[graph[cur][i]] == 0)
                q.push(graph[cur][i]);
        }
    }

    for (int i = 0; i < sorted.size(); i++)
    {
        cout << sorted[i] << " ";
    }
}