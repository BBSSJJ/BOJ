#include <iostream>
#include <queue>
// #include <bits/stdc++.h>

using namespace std;

char maze[1001][1001];
int R, C;
int startx, starty;
char a;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<pair<int, int>, pair<char, int>>> que;
vector<pair<int, int>> fire;
// #: 벽, .: 지나갈 수 있음, F: 불 난 곳
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> a;
            if (a == 'J') {
                que.push({{i, j}, {'J', 0}});
            } else if (a == 'F') {
                fire.push_back({i, j});
            }
            maze[i][j] = a;
        }
    }
    for (int i = 0; i < fire.size(); i++) {
        que.push({{fire[i].first, fire[i].second}, {'F', 0}});
    }

    while (!que.empty()) {
        int x = que.front().first.first;
        int y = que.front().first.second;
        char object = que.front().second.first;
        int time = que.front().second.second;
        que.pop();

        // 현재 내 위치가 불에 탄 경우!!!!!
        if (object == 'J' && maze[x][y] == 'F') {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (object == 'J') {
                if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
                    // 탈출 성공
                    cout << time + 1;
                    return 0;
                } else if (maze[nx][ny] == '.') {
                    maze[nx][ny] = 'J';
                    que.push({{nx, ny}, {'J', time + 1}});
                }
            } else if (object == 'F') {
                if (nx < 0 || ny < 0 || nx >= R || ny >= C || maze[nx][ny] == 'F' || maze[nx][ny] == '#') {
                    continue;
                } else {
                    maze[nx][ny] = 'F';
                    que.push({{nx, ny}, {'F', time + 1}});
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}