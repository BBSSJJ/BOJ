#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

char map[1000][1000];
int time[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct obj {
    int x;
    int y;
    char c;  // m -> me , f-> fire
    int time;
};

vector<pair<int, int>> fire;
int sx, sy;
int h, w;

bool OOB(int x, int y) { return (x < 0 || y < 0 || x >= h || y >= w); }

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        vector<pair<int, int>>().swap(fire);
        fill(&time[0][0], &time[1000][1000], 0);

        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            cin >> s;
            for (int j = 0; j < w; j++) {
                map[i][j] = s[j];
                if (s[j] == '*')
                    fire.push_back({i, j});
                else if (s[j] == '@') {
                    sx = i;
                    sy = j;
                }
            }
        }

        queue<obj> que;
        que.push({sx, sy, 'm', 0});
        for (auto f : fire) {
            que.push({f.first, f.second, 'f', 0});
        }

        int answer = 0;
        bool success = false;

        while (!que.empty()) {
            obj o = que.front();
            int cx = o.x;
            int cy = o.y;
            char c = o.c;
            int ctime = o.time;
            que.pop();

            /////////////////////////////////////////
            // 현재 자리가 죽은 자리면 continue 해줘야 함....
            if (map[cx][cy] == '*' && o.c == 'm') continue;
            /////////////////////////////////////////

            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (c == 'm') {
                    if (OOB(nx, ny)) {
                        // 성공
                        answer = ctime + 1;
                        success = true;
                        break;
                    }
                    if (map[nx][ny] != '.') continue;
                    map[nx][ny] = '@';
                    que.push({nx, ny, 'm', ctime + 1});
                } else {
                    if (OOB(nx, ny)) continue;
                    if (map[nx][ny] == '#' || map[nx][ny] == '*') continue;
                    map[nx][ny] = '*';
                    que.push({nx, ny, 'f', ctime + 1});
                }
            }
            if (success) break;
        }

        if (answer == 0)
            cout << "IMPOSSIBLE"
                 << "\n";
        else
            cout << answer << "\n";
    }
}