#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dp[301];
int N, n;
vector<int> stairs;

int main() {
    cin >> N;
    stairs.push_back(0);
    for (int i = 0; i < N; i++) {
        cin >> n;
        stairs.push_back(n);
    }
    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];
    dp[3] = max(dp[1] + stairs[3], dp[0] + stairs[2] + stairs[3]);

    for (int i = 4; i <= N; i++) {
        dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
    }

    cout << dp[N] << "\n";
}