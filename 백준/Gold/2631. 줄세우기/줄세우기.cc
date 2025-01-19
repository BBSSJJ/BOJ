#include <iostream>
#include <vector>

using namespace std;

int N, answer;

int main() {
    cin >> N;

    vector<int> numbers(N + 1, 0);
    vector<int> dp(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> numbers[i];
    }

    for (int i = 1; i <= N; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (numbers[j] < numbers[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (answer < dp[i]) answer = dp[i];
    }

    cout << N - answer;
}
