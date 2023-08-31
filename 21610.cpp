#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, d, s;
int map[50][50];
bool cloud[50][50];

int gx[4] = {-1, -1, 1, 1};
int gy[4] = {-1, 1, -1, 1};

bool OOB(int x, int y) { return (x < 0 || y < 0 || x >= N || y >= N); }

void makeCloud() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (cloud[i][j] == true) {
                cloud[i][j] = false;
                continue;
            }
            if (map[i][j] >= 2) {
                cloud[i][j] = true;
                map[i][j] -= 2;
            }
        }
    }
}

void rain(int dir, int dist, int dx[], int dy[]) {
    bool tmpCloud[50][50] = {
        false,
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (cloud[i][j]) {
                cloud[i][j] = false;
                tmpCloud[(i + dx[dir] * dist) % N][(j + dy[dir] * dist) % N] = true;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cloud[i][j] = tmpCloud[i][j];
            if (tmpCloud[i][j]) {
                map[i][j]++;
            }
        }
    }
}

void getWater(int dx[], int dy[]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (cloud[i][j]) {
                for (int g = 0; g < 4; g++) {
                    int nx = i + gx[g];
                    int ny = j + gy[g];
                    if (OOB(nx, ny)) continue;
                    if (map[nx][ny] != 0) map[i][j]++;
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    int dx[9] = {0, 0, N - 1, N - 1, N - 1, 0, 1, 1, 1};
    int dy[9] = {0, N - 1, N - 1, 0, 1, 1, 1, 0, N - 1};

    cloud[N - 1][0] = true;
    cloud[N - 2][0] = true;
    cloud[N - 1][1] = true;
    cloud[N - 2][1] = true;
    for (int i = 0; i < M; i++) {
        cin >> d >> s;
        rain(d, s, dx, dy);
        getWater(dx, dy);
        makeCloud();
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            answer += map[i][j];
        }
    }
    cout << answer << endl;
}