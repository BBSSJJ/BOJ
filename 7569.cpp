#include <iostream>>
#include <queue>
#include <string>

using namespace std;

struct Location {
    int x;
    int y;
    int h;
    int time;
};

int M, N, H;
int storage[100][100][100];
queue<Location> que;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int time;
int answer;

bool OOB(int x, int y, int h) {
    if (x < 0 || y < 0 || h < 0 || x >= N || y >= M || h >= H)
        return true;
    else
        return false;
}

void checkStorage() {
    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (storage[h][i][j] == 0) {
                    answer = -1;
                    return;
                }
            }
        }
    }
}

int main() {
    cin >> M >> N >> H;

    for (int h = 0; h < H; h++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> storage[h][i][j];  // 1-> 익은 토마토 0 -> 안익은 토마토 -1 ->빈 상자
                if (storage[h][i][j] == 1) {
                    Location loc = {i, j, h, 0};
                    que.push(loc);
                }
            }
        }
    }

    while (!que.empty()) {
        Location loc = que.front();
        int x = loc.x;
        int y = loc.y;
        int h = loc.h;
        int time = loc.time;
        que.pop();

        answer = max(answer, time);

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (OOB(nx, ny, h)) continue;
            if (storage[h][nx][ny] == 0) {
                storage[h][nx][ny] = 1;
                Location loc = {nx, ny, h, time + 1};
                que.push(loc);
            }
        }
        int nh = h + 1;
        if (!OOB(x, y, nh) && storage[nh][x][y] == 0) {
            storage[nh][x][y] = 1;
            Location loc = {x, y, nh, time + 1};
            que.push(loc);
        }

        nh = h - 1;
        if (!OOB(x, y, nh) && storage[nh][x][y] == 0) {
            storage[nh][x][y] = 1;
            Location loc = {x, y, nh, time + 1};
            que.push(loc);
        }
    }

    checkStorage();

    cout << answer;
}