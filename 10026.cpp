#include <iostream>
#include <queue>
#include <string>

using namespace std;

char picture_original[100][100];
char picture_fixed[100][100];
int picture_original_section;
int picture_fixed_section;
bool visited[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string s;
int N;

bool OOB(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= N)
        return true;
    else
        return false;
}

void bfs(char picture[][100], int x, int y) {
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
            if (visited[nx][ny] || OOB(nx, ny)) continue;
            if (picture[cx][cy] != picture[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> picture_original[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (picture_original[i][j] == 'G')
                picture_fixed[i][j] = 'R';
            else
                picture_fixed[i][j] = picture_original[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                bfs(picture_original, i, j);
                picture_original_section++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                bfs(picture_fixed, i, j);
                picture_fixed_section++;
            }
        }
    }

    cout << picture_original_section << " " << picture_fixed_section << "\n";
}