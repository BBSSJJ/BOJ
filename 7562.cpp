#include <iostream>
#include <queue>
using namespace std;

int T, I;
int visited[300][300];
int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

bool OOB(int x, int y) { return (x < 0 || y < 0 || x >= I || y >= I); }
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;

    while (T--) {
        cin >> I;
        int sx, sy, fx, fy;
        cin >> sx >> sy >> fx >> fy;

        queue<pair<int, int>> que;
        for (int i = 0; i < I; i++) {
            for (int j = 0; j < I; j++) {
                visited[i][j] = 0;
            }
        }

        visited[sx][sy] = 0;
        que.push({sx, sy});
        int answer = 0;

        while (!que.empty()) {
            int cx = que.front().first;
            int cy = que.front().second;
            int depth = visited[cx][cy];
            que.pop();

            if (cx == fx && cy == fy) {
                answer = depth;
                break;
            }

            for (int i = 0; i < 8; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (OOB(nx, ny) || visited[nx][ny] != 0) continue;

                que.push({nx, ny});
                visited[nx][ny] = depth + 1;
            }
        }

        cout << answer << "\n";
    }
}