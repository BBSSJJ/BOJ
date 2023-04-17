#include <iostream>
#include <vector>
using namespace std;

int n, m, area, max_area, picture_count;
int graph[500][500];
bool visited[500][500];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int x, int y) {
    area++;
    visited[x][y] = true;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (graph[nx][ny] == 1 && !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 1 && !visited[i][j]) {
                picture_count++;
                area = 0;
                dfs(i, j);
                max_area = max(area, max_area);
            }
        }
    }
    cout << picture_count << endl;
    cout << area << endl;
}