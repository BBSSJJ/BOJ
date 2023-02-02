// bfs 사용 시 que에 넣을 때 visited 표시를 하는 것이 중요!!!

#include <iostream>
#include <queue>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int graph[100][100];
    bool visited[100][100];
    int N, M, num;
    int cheese = 0;
    int cheese_temp = 0;
    int time = 0;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> num;
            graph[i][j] = num;
            if (num == 1) cheese++;
            visited[i][j] = false;
        }
    }

    queue<pair<int, int>> q;

    while (cheese > 0) {
        time++;
        cheese_temp = cheese;

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();

            if (a != 0) {
                if (graph[a - 1][b] == 0 && !visited[a - 1][b]) {
                    q.push({a - 1, b});
                    visited[a - 1][b] = true;
                } else if (graph[a - 1][b] == 1) {
                    graph[a - 1][b] = 0;
                    visited[a - 1][b] = true;
                    cheese--;
                }
            }
            if (b != 0) {
                if (graph[a][b - 1] == 0 && !visited[a][b - 1]) {
                    q.push({a, b - 1});
                    visited[a][b - 1] = true;
                } else if (graph[a][b - 1] == 1) {
                    graph[a][b - 1] = 0;
                    visited[a][b - 1] = true;
                    cheese--;
                }
            }
            if (a < N) {
                if (graph[a + 1][b] == 0 && !visited[a + 1][b]) {
                    q.push({a + 1, b});
                    visited[a + 1][b] = true;
                } else if (graph[a + 1][b] == 1) {
                    graph[a + 1][b] = 0;
                    visited[a + 1][b] = true;
                    cheese--;
                }
            }
            if (b < M) {
                if (graph[a][b + 1] == 0 && !visited[a][b + 1]) {
                    q.push({a, b + 1});
                    visited[a][b + 1] = true;
                } else if (graph[a][b + 1] == 1) {
                    graph[a][b + 1] = 0;
                    visited[a][b + 1] = true;
                    cheese--;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                visited[i][j] = false;
            }
        }
    }
    cout << time << " " << cheese_temp << endl;
}
