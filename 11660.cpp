// ios_base cin tie 안해주면 시간초과
#include <iostream>

using namespace std;

int N, M, a, b, c, d;

int map[1025][1025];
long long dp[1025][1025];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + map[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c >> d;
        cout << (dp[c][d] - dp[c][b - 1] - dp[a - 1][d] + dp[a - 1][b - 1]) << "\n";
    }
}