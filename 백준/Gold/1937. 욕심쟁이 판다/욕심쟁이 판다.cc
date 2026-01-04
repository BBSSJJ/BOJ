#include <iostream>
#include <vector>

using namespace std;

int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> forest;
vector<vector<int>> dp;

bool outOfBound(int x, int y) { return x < 0 || y < 0 || x >= N || y >= N; }

void dfs(int x, int y) {
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (outOfBound(nx, ny)) continue;
        if (forest[x][y] >= forest[nx][ny]) continue;
        if (dp[nx][ny] == 0) dfs(nx, ny);
        dp[x][y] = max(dp[x][y], dp[nx][ny] + 1);
    }
}

int main() {
    cin >> N;

    forest = vector<vector<int>>(N, vector<int>(N, 0));
    dp = vector<vector<int>>(N, vector<int>(N, 0));
    int answer = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> forest[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[i][j] == 0) dfs(i, j);
            answer = max(answer, dp[i][j]);
        }
    }

    cout << answer;
}
