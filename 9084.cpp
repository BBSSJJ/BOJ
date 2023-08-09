// 9084
// DP문제, 동전의 순서 구분이 없으려면, 하나의 동전에 대해 dp를 모두 채워주고 다음 동전으로 채우기를 반복
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T, N;
int coin[20];
int cost;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> coin[i];
        }
        cin >> cost;

        vector<int> dp(cost + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = coin[i]; j <= cost; j++) {
                dp[j] += dp[j - coin[i]];
            }
        }
        cout << dp[cost] << "\n";
    }
}