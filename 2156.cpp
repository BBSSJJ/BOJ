#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, n;
vector<int> vec;
int liter[10001];
int dp[10001];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> liter[i];
    }
    dp[1] = liter[1];
    dp[2] = liter[1] + liter[2];
    dp[3] = max({dp[1] + liter[3], liter[2] + liter[3], dp[2]});
    if (N < 4) {
        cout << dp[N] << endl;
        return 0;
    }
    for (int i = 4; i <= N; i++) {
        dp[i] = max({dp[i - 2] + liter[i], liter[i - 1] + dp[i - 3] + liter[i], dp[i - 1]});
    }
    cout << dp[N] << endl;
}