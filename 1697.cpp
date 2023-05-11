// #include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue<int> que;
int road[100001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    que.push(N);
    road[N] = 1;
    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        if (cur + 1 <= 100000 && road[cur + 1] == 0) {
            road[cur + 1] = road[cur] + 1;
            que.push(cur + 1);
        }
        if (cur - 1 >= 0 && road[cur - 1] == 0) {
            road[cur - 1] = road[cur] + 1;
            que.push(cur - 1);
        }
        if (cur * 2 <= 100000 && road[cur * 2] == 0) {
            road[cur * 2] = road[cur] + 1;
            que.push(cur * 2);
        }
    }

    cout << road[K] - 1;
}