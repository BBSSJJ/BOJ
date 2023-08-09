// 2206
// bfs 사용
// depth는 같은데 부수고 온 상황이면 continue시켜서 최적화 가능할듯?
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int N, M;
int graph[1000][1000];
int visited[1000][1000][2];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pair<pair<int, int>, pair<int, int>>> q;

bool OOB(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= M)
        return true;
    else
        return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < M; j++) {
            graph[i][j] = str[j] - '0';
        }
    }
    int answer = 987654321;
    q.push({{0, 0}, {0, 0}});
    visited[0][0][0] = 1;
    while (!q.empty()) {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int depth = q.front().second.first;
        int breaked = q.front().second.second;
        q.pop();
        if (cx == N - 1 && cy == M - 1) {
            answer = min(answer, depth);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (OOB(nx, ny)) continue;

            if (breaked == 1) {
                if (visited[nx][ny][breaked]) continue;
                if (graph[nx][ny] == 1) continue;
                visited[nx][ny][breaked] = 1;
                q.push({{nx, ny}, {depth + 1, breaked}});
            } else {
                if (graph[nx][ny] == 1) {  // use break;
                    if (visited[nx][ny][1] == 1) continue;
                    visited[nx][ny][1] = 1;
                    q.push({{nx, ny}, {depth + 1, 1}});
                } else {
                    if (visited[nx][ny][breaked] == 1) continue;
                    visited[nx][ny][0] = 1;
                    q.push({{nx, ny}, {depth + 1, 0}});
                }
            }
        }
    }
    if (answer == 987654321)
        cout << -1;
    else
        cout << answer + 1;
}