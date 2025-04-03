#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    int maxResult = 0;
    int minResult = INT_MAX;
    cin >> N;

    vector<int> numbers(3);
    vector<vector<int>> dp1(2, vector<int>(3, 0));
    vector<vector<int>> dp2(2, vector<int>(3, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> numbers[j];
        }

        dp1[1][0] = numbers[0] + max(dp1[0][0], dp1[0][1]);
        dp1[1][1] = numbers[1] + max(dp1[0][0], max(dp1[0][1], dp1[0][2]));
        dp1[1][2] = numbers[2] + max(dp1[0][1], dp1[0][2]);

        dp2[1][0] = numbers[0] + min(dp2[0][0], dp2[0][1]);
        dp2[1][1] = numbers[1] + min(dp2[0][0], min(dp2[0][1], dp2[0][2]));
        dp2[1][2] = numbers[2] + min(dp2[0][1], dp2[0][2]);

        for (int j = 0; j < 3; j++) {
            dp1[0][j] = dp1[1][j];
            dp2[0][j] = dp2[1][j];
        }
    }

    for (int j = 0; j < 3; j++) {
        maxResult = max(maxResult, dp1[1][j]);
        minResult = min(minResult, dp2[1][j]);
    }
    cout << maxResult << " " << minResult;
}