// 2573
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int graph[300][300];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void oneYear();
bool isSeperated();
int iceCount;

bool OOB(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= M)
        return true;
    else
        return false;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
            if (graph[i][j] != 0) iceCount++;
        }
    }

    int answer = 0;
    while (1) {
        if (isSeperated()) break;
        if (iceCount == 0) {  // 분리되지 않았는데 다 녹아서 끝나면 반드시 0으로 만들어줘야함!
            answer = 0;
            break;
        } else
            oneYear();
        answer++;
    }

    cout << answer;
}

bool isSeperated() {
    int visited[300][300] = {
        0,
    };
    queue<pair<int, int>> que;
    int count;
    for (int p = 0; p < N; p++) {
        for (int q = 0; q < M; q++) {
            if (graph[p][q] != 0) {
                que.push({p, q});
                visited[p][q] = 1;
                break;
            }
        }
        if (!que.empty()) break;
    }

    while (!que.empty()) {
        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (OOB(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            if (graph[nx][ny] == 0) continue;

            visited[nx][ny] = 1;
            que.push({nx, ny});
        }
    }

    for (int p = 0; p < N; p++) {
        for (int q = 0; q < M; q++) {
            if (graph[p][q] != 0 && !visited[p][q]) return true;
        }
    }
    return false;
}

void oneYear() {
    int visited[300][300] = {
        0,
    };
    queue<pair<int, int>> que;
    for (int p = 0; p < N; p++) {
        for (int q = 0; q < M; q++) {
            if (!visited[p][q] && graph[p][q] == 0) {
                que.push({p, q});
                visited[p][q] = 1;
                while (!que.empty()) {
                    int cx = que.front().first;
                    int cy = que.front().second;
                    que.pop();

                    for (int i = 0; i < 4; i++) {
                        int nx = cx + dx[i];
                        int ny = cy + dy[i];
                        if (OOB(nx, ny)) continue;
                        if (visited[nx][ny]) continue;
                        if (graph[nx][ny] != 0) {
                            graph[nx][ny] -= 1;
                            if (graph[nx][ny] == 0) {
                                visited[nx][ny] = 1;
                                iceCount--;
                            }
                        } else {
                            visited[nx][ny] = 1;
                            que.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
}