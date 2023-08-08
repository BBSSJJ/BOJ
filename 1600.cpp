// vistied를 3중배열로 해서 몇번 점프해서 온건지도 판단
//  map 사이즈가 1일 때 고려해야 함!

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int K, W, H;
int map[200][200];
int visited[200][200][31];
queue<pair<pair<int, int>, pair<int, int>>> q;

int jx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int jy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool OOB(int x, int y) {
    if (x < 0 || y < 0 || x >= H || y >= W) return true;
    return false;
}

int main() {
    cin >> K >> W >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> map[i][j];
        }
    }
    if (W == 1 && H == 1) {
        cout << 0;
        return 0;
    }

    q.push({{0, 0}, {0, 0}});
    visited[0][0][0] = 0;
    while (!q.empty()) {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int depth = q.front().second.first;
        int jumped = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (OOB(nx, ny)) continue;
            if (map[nx][ny]) continue;
            if (visited[nx][ny][jumped] != 0 && visited[nx][ny][jumped] <= depth + 1) continue;
            q.push({{nx, ny}, {depth + 1, jumped}});
            visited[nx][ny][jumped] = depth + 1;
        }
        if (jumped >= K) continue;
        for (int i = 0; i < 8; i++) {
            int nx = cx + jx[i];
            int ny = cy + jy[i];
            if (OOB(nx, ny)) continue;
            if (map[nx][ny]) continue;
            if (visited[nx][ny][jumped + 1] != 0 && visited[nx][ny][jumped + 1] <= depth + 1) continue;

            q.push({{nx, ny}, {depth + 1, jumped + 1}});
            visited[nx][ny][jumped + 1] = depth + 1;
        }
    }

    int answer = 100000000;
    for (int i = 0; i <= K; i++) {
        if (visited[H - 1][W - 1][i] != 0) answer = min(answer, visited[H - 1][W - 1][i]);
    }
    if (answer == 100000000)
        cout << -1;
    else
        cout << answer;
}