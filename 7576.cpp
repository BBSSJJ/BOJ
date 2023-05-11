// #include <bits/stdc++.h>

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, k;
int graph[1001][1001];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pair<int, int>> que;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> k;
            graph[i][j] = k;
            if (k == 1) {
                que.push({i, j});
            }
        }
    }

    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if (graph[nx][ny] == 0) {
                graph[nx][ny] = graph[x][y] + 1;
                que.push({nx, ny});
            }
        }
    }

    int answer = -1;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] == 0) {
                cout << "-1";
                return 0;
            } else {
                answer = max(answer, graph[i][j]);
            }
        }
    }
    cout << answer - 1;
}