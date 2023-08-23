#include <iostream>
#include <queue>

using namespace std;

int N, M, K;
int board[20][20];
int dice[4][3] = {{0, 2, 0}, {4, 1, 3}, {0, 5, 0}, {0, 6, 0}};  // 바닥 -> dice[3][1]
int scores[20][20];                                             // 미리 점수 저장해둔다
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void roll(int dir) {  // 0->위 1->오른쪽 2->아래 3->왼쪽
    if (dir == 0) {
        int tmp = dice[0][1];
        dice[0][1] = dice[1][1];
        dice[1][1] = dice[2][1];
        dice[2][1] = dice[3][1];
        dice[3][1] = tmp;
    }
    if (dir == 1) {
        int tmp = dice[3][1];
        dice[3][1] = dice[1][2];
        dice[1][2] = dice[1][1];
        dice[1][1] = dice[1][0];
        dice[1][0] = tmp;
    }
    if (dir == 2) {
        int tmp = dice[3][1];
        dice[3][1] = dice[2][1];
        dice[2][1] = dice[1][1];
        dice[1][1] = dice[0][1];
        dice[0][1] = tmp;
    }
    if (dir == 3) {
        int tmp = dice[3][1];
        dice[3][1] = dice[1][0];
        dice[1][0] = dice[1][1];
        dice[1][1] = dice[1][2];
        dice[1][2] = tmp;
    }
}

bool OOB(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= M)
        return true;
    else
        return false;
}

int getScore(int x, int y) {
    int count = 1;
    int num = board[x][y];
    bool visited[20][20];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = false;
        }
    }
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (OOB(nx, ny) || visited[nx][ny] || board[nx][ny] != num) continue;
            visited[nx][ny] = true;
            count++;
            q.push({nx, ny});
        }
    }
    return count * num;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scores[i][j] = getScore(i, j);
        }
    }

    int cx = 0;
    int cy = 0;
    int dir = 1;
    int answer = 0;

    for (int i = 0; i < K; i++) {
        roll(dir);
        cx += dx[dir];
        cy += dy[dir];

        answer += scores[cx][cy];

        if (dice[3][1] > board[cx][cy]) {
            dir = (dir + 1) % 4;
        } else if (dice[3][1] < board[cx][cy]) {
            dir = (dir + 3) % 4;
        }

        // 방향 바뀌고 검사해야 한다.
        if ((dir == 0 && cx == 0) || (dir == 1 && cy == M - 1) || (dir == 2 && cx == N - 1) || (dir == 3 && cy == 0)) {
            dir = (dir + 2) % 4;
        }
    }

    cout << answer;
}