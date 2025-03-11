#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, G, R, GR, answer;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> garden;
vector<pair<int, int>> lands;
vector<vector<int>> templates;

struct node {
    int x;
    int y;
    int color;
    int time;
};

// 0은 호수, 1은 배양액을 뿌릴 수 없는 땅, 2는 배양액을 뿌릴 수 있는 땅

bool OOB(int x, int y) { return (x < 0 || y < 0 || x >= N || y >= M); }

int simul(vector<int>& temp) {
    vector<vector<int>> visited(garden);
    vector<vector<int>> times(N, vector<int>(M, 0));
    queue<node> que;

    for (int i = 0; i < lands.size(); i++) {
        int x = lands[i].first;
        int y = lands[i].second;
        if (temp[i] != 0) {
            visited[x][y] = temp[i];
            que.push({x, y, temp[i], 0});
        } else
            visited[x][y] = 1;
    }

    int flowerCount = 0;

    while (!que.empty()) {
        node cur = que.front();
        que.pop();

        if (visited[cur.x][cur.y] == 0) continue;  // 일단 넣었는데, 꽃이 폈을 때 없애줘야 함...

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (OOB(nx, ny) || visited[nx][ny] == 0) {
                continue;
            } else if (visited[nx][ny] == 1) {
                visited[nx][ny] = cur.color;
                times[nx][ny] = cur.time + 1;
                que.push({nx, ny, cur.color, cur.time + 1});
                continue;
            } else if (visited[nx][ny] != cur.color && times[nx][ny] == cur.time + 1) {
                flowerCount++;
                visited[nx][ny] = 0;
            }
        }
    }

    return flowerCount;
}

int main() {
    cin >> N >> M >> G >> R;
    GR = G + R;
    garden = vector<vector<int>>(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> garden[i][j];
            if (garden[i][j] == 2) lands.push_back({i, j});
        }
    }

    vector<int> tmp;
    for (int i = 0; i < lands.size() - G - R; i++) {
        tmp.push_back(0);
    }
    for (int i = 0; i < G; i++) {
        tmp.push_back('G');
    }
    for (int i = 0; i < R; i++) {
        tmp.push_back('R');
    }
    do {
        answer = max(answer, simul(tmp));
    } while (next_permutation(tmp.begin(), tmp.end()));

    cout << answer;
}