#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N;

    vector<int> number(N + 1);
    vector<vector<bool>> dp(N + 1, vector<bool>(N + 1, false));

    // i부터 i(길이 1), i-1부터 i(길이 2) 저장
    for (int i = 1; i <= N; i++) {
        cin >> number[i];
        dp[i][i] = true;
        if (i != 1 && number[i - 1] == number[i]) {
            dp[i - 1][i] = true;
        }
    }

    // 길이 3이상 저장
    for (int gap = 2; gap < N; gap++) {
        for (int i = 1; i + gap <= N; i++) {
            if (number[i] == number[i + gap] && dp[i + 1][i + gap - 1]) {
                dp[i][i + gap] = true;
            }
        }
    }

    cin >> M;
    while (M--) {
        int S, E;
        cin >> S >> E;
        if (dp[S][E])
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
}