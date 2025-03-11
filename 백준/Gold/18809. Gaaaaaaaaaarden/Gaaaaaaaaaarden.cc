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

void comb2(int idx, int gr, vector<int>& order) {
    if (gr == GR) {
        vector<int> tmp = order;
        templates.push_back(tmp);
        return;
    }
    if (idx == lands.size()) {
        return;
    }

    for (int i = idx; i < lands.size(); i++) {
        order[i] = 1;
        comb2(i + 1, gr + 1, order);
        order[i] = 0;
    }
}

void comb1(int idx, int g, vector<int>& selected) {
    if (g == G) {
        for (int t = 0; t < templates.size(); t++) {
            vector<int> temp = templates[t];

            int c = 0;
            for (int i = 0; i < lands.size(); i++) {
                if (temp[i] == 1) {
                    temp[i] = selected[c];
                    c++;
                }
            }
            answer = max(simul(temp), answer);
        }
        return;
    }
    if (idx == GR) {
        return;
    }

    for (int i = idx; i < GR; i++) {
        selected[i] = 'G';
        comb1(i + 1, g + 1, selected);
        selected[i] = 'R';
    }
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

    vector<int> selected(GR, 'R');
    vector<int> order(lands.size(), 0);
    comb2(0, 0, order);

    comb1(0, 0, selected);

    cout << answer;
}