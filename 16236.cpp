#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
int N, m, start_i, start_j;
int graph[20][20];
bool visited[20][20];
bool eat[20][20];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int shark_size = 2;

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> can_eat;
queue<tuple<int, int, int>> que;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> m;
            graph[i][j] = m;
            if (m == 9) {
                start_i = i;
                start_j = j;
            }
        }
    }
    int time = 0;
    int live_time = 0;
    int eat_count = 0;

    visited[start_i][start_j] = true;
    graph[start_i][start_j] = 0;
    que.push({start_i, start_j, time});
    while (!que.empty()) {
        int cx = get<0>(que.front());
        int cy = get<1>(que.front());
        int ctime = get<2>(que.front());
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int ntime = ctime + 1;
            if (!can_eat.empty() && ntime > get<2>(can_eat.top())) {
                int nx = get<0>(can_eat.top());
                int ny = get<1>(can_eat.top());
                int ntime = get<2>(can_eat.top());
                eat_count++;
                if (eat_count == shark_size) {
                    shark_size++;
                    eat_count = 0;
                }
                graph[nx][ny] = 0;

                while (!que.empty()) {
                    que.pop();
                }
                while (!can_eat.empty()) {
                    can_eat.pop();
                }
                que.push({nx, ny, ntime});
                for (int k = 0; k < N; k++) {
                    for (int l = 0; l < N; l++) {
                        visited[k][l] = false;
                    }
                }
                visited[nx][ny] = true;
                live_time = ntime;
                break;
            }
            if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visited[nx][ny]) {
                // 자기보다 크면 못감
                if (graph[nx][ny] > shark_size) {
                    continue;
                }
                // 먹이 먹으면 초기화 후 그 자리에서 다시 출발
                else if (graph[nx][ny] != 0 && graph[nx][ny] < shark_size) {
                    can_eat.push({nx, ny, ntime});
                    visited[nx][ny] = true;
                    que.push({nx, ny, ntime});

                } else {
                    visited[nx][ny] = true;
                    que.push({nx, ny, ntime});
                }
            }
        }
    }
    cout << live_time << endl;
}