
#include <iostream>
#include <vector>
using namespace std;

int dp[10][1001];
int N, answer;

int main() {
    cin >> N;
    for (int i = 0; i < 10; i++) {
        dp[i][1] = 1;
    }
    if (N == 1) {
        cout << 10 << endl;
        return 0;
    }
    for (int j = 2; j <= N; j++) {
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k <= i; k++) {
                dp[i][j] = (dp[i][j] + dp[k][j - 1]) % 10007;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        answer = (answer + dp[i][N]) % 10007;
    }

    cout << answer << endl;
}