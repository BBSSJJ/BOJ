#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D, depth;
bool visited[1000001];

int main() {
    for (int i = 0; i < 1000001; i++) {
        visited[i] = false;
    }
    cin >> F >> S >> G >> U >> D;
    queue<pair<int, int>> que;
    que.push({S, 0});
    while (!que.empty()) {
        int cur = que.front().first;
        int cur_depth = que.front().second;
        que.pop();

        if (cur == G) {
            cout << cur_depth << endl;
            return 0;
        }

        int upstair = cur + U;
        int downstair = cur - D;

        if (upstair <= F && !visited[upstair]) {
            visited[upstair] = true;
            que.push({upstair, cur_depth + 1});
        }
        if (downstair >= 1 && !visited[downstair]) {
            visited[downstair] = true;
            que.push({downstair, cur_depth + 1});
        }
    }

    cout << "use the stairs" << endl;
    return 0;
}