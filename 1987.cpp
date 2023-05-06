#include <iostream>
#include <vector>
using namespace std;

int R, C;

string graph[20];

bool alphabet_visited[26];
bool node_visited[20][20];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
// 0은 빈칸, 1은 벽, 2는 바이러스
int max_depth = 0;

void dfs(int ci, int cj, int depth) {
    node_visited[ci][cj] = true;
    alphabet_visited[graph[ci][cj] - 'A'] = true;
    max_depth = max(depth, max_depth);

    for (int i = 0; i < 4; i++) {
        int ni = ci + dx[i];
        int nj = cj + dy[i];
        if (ni >= 0 && nj >= 0 && ni < R && nj < C && !node_visited[ni][nj] && !alphabet_visited[graph[ni][nj] - 'A']) {
            dfs(ni, nj, depth + 1);
        }
    }
    node_visited[ci][cj] = false;
    alphabet_visited[graph[ci][cj] - 'A'] = false;
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> graph[i];
    }
    dfs(0, 0, 1);
    cout << max_depth << endl;
}