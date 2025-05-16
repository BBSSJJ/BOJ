#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;
vector<vector<int>> board;

bool OOB(int x, int y) { return x < 0 || y < 0 || x >= N || y >= M; }

void bfs(int i, int j, vector<pair<int, int>>& melt) {
    vector<vector<int>> visited(N, vector<int>(M, 0));
    queue<pair<int, int>> que;
    que.push({i, j});
    while (!que.empty()) {
        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();

        if (OOB(cx, cy)) continue;
        if (board[cx][cy] == 0 && visited[cx][cy] != 0) {
            continue;
        } else if (board[cx][cy] == 1) {
            visited[cx][cy] += 1;
            if (visited[cx][cy] == 2) {
                melt.push_back({cx, cy});
            }
            continue;
        }
        visited[cx][cy] += 1;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            que.push({nx, ny});
        }
    }
}
bool step() {
    vector<pair<int, int>> melt;
    bfs(0, 0, melt);
    if (melt.empty()) {
        return false;
    }
    for (int i = 0; i < melt.size(); i++) {
        board[melt[i].first][melt[i].second] = 0;
    }

    return true;
}

int main() {
    cin >> N >> M;
    board = vector<vector<int>>(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    int answer = 0;
    while (step()) {
        answer++;
    }
    cout << answer;
}