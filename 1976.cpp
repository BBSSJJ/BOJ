// https://www.acmicpc.net/problem/1976
// 플로이드 워셜 사용
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, u;
    cin >> N >> M;
    int graph[201][201];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> u;
            if (u != 1) {
                graph[i][j] = 1000000000;
            } else {
                graph[i][j] = u;
            }
        }
    }

    vector<int> travel_order;

    for (int i = 0; i < M; i++) {
        cin >> u;
        travel_order.push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                graph[j][k] = min(graph[j][i] + graph[i][k], graph[j][k]);
            }
        }
    }
    for (int i = 0; i < M - 1; i++) {
        int cur = travel_order[i];
        int next = travel_order[i + 1];
        if (cur == next) {  // 이거 조심!
            continue;
        }
        if (graph[cur][next] == 1000000000) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}