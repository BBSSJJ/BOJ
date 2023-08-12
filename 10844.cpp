#include <iostream>

using namespace std;
#define Mod 1000000000;

int dp[10][101];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= 9; i++) {
        dp[i][1] = 1;
    }

    for (int j = 2; j <= n; j++) {
        for (int i = 0; i <= 9; i++) {
            if (i == 0) {
                dp[i][j] = dp[i + 1][j - 1] % Mod;
            } else if (i == 9) {
                dp[i][j] = dp[i - 1][j - 1] % Mod;
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i + 1][j - 1]) % Mod;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i <= 9; i++) {
        answer = (answer + dp[i][n]) % Mod;
    }
    cout << answer;
}
