#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, L, R;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool OOB(int x, int y) { return (x < 0 || y < 0 || x >= N || y >= N); }

bool bfs(int x, int y, vector<vector<int>>& board, vector<vector<bool>>& visited) {
    queue<pair<int, int>> que;
    vector<pair<int, int>> countries;

    int population = board[x][y];
    visited[x][y] = true;
    que.push({x, y});
    countries.push_back({x, y});

    while (!que.empty()) {
        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (OOB(nx, ny) || visited[nx][ny]) continue;

            int gap = abs(board[cx][cy] - board[nx][ny]);

            if (gap < L || gap > R) continue;

            population += board[nx][ny];
            countries.push_back({nx, ny});
            que.push({nx, ny});
            visited[nx][ny] = true;
        }
    }

    if (countries.size() == 1) {
        return false;
    }

    population /= countries.size();
    for (int i = 0; i < countries.size(); i++) {
        board[countries[i].first][countries[i].second] = population;
    }

    return true;
}

int main() {
    cin >> N >> L >> R;

    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int day = 0;
    while (true) {
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        bool moved = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    if (bfs(i, j, board, visited)) moved = true;
                }
            }
        }

        if (!moved) break;
        day++;
    }
    cout << day;
}