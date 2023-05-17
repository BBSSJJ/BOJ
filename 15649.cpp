#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool visited[9];
int answer[9];
void bt(int n, int m) {
    visited[n] = true;
    answer[m] = n;
    if (m == M - 1) {
        for (int i = 0; i < M; i++) {
            cout << answer[i] << " ";
        }
        cout << "\n";
        visited[n] = false;
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            bt(i, m + 1);
        }
    }
    visited[n] = false;
    return;
}
int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        bt(i, 0);
    }
}