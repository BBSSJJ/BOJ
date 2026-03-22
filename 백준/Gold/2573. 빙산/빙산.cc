#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int N, M;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<int>> map;
vector<vector<bool>> visited;
vector<pair<int, int>> willMelt;

bool OOB(int x, int y) { return (x < 0 || y < 0 || x >= N || y >= M); }

void melt() {
    for (auto i : willMelt) {
        if (map[i.first][i.second] != 0) {
            map[i.first][i.second] -= 1;
        }
    }
}

void bfs(int x, int y) {
    queue<pair<int, int>> que;
    visited[x][y] = true;
    que.push({x, y});

    while (!que.empty()) {
        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (OOB(nx, ny) || visited[nx][ny]) continue;
            if (map[nx][ny] == 0) {
                willMelt.push_back({cx, cy});
                continue;
            }

            visited[nx][ny] = true;
            que.push({nx, ny});
        }
    }
}

int main() {
    cin >> N >> M;

    map = vector<vector<int>>(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int year = 0;

    while (true) {
        visited = vector<vector<bool>>(N, vector<bool>(M, false));
        willMelt.clear();
        bool isOne = true;

        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < M - 1; j++) {
                if (map[i][j] != 0 && !visited[i][j]) {
                    if (!isOne) {
                        cout << year;
                        return 0;
                    }
                    bfs(i, j);
                    isOne = false;
                }
            }
        }
        if (willMelt.size() == 0) {
            cout << 0;
            return 0;
            break;
        }
        year++;
        melt();
    }
}