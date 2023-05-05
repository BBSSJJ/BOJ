#include <iostream>
using namespace std;
int dp[5002];
string s;
int main() {
    cin >> s;
    dp[0] = 1;
    dp[1] = 1;

    if (s[0] == '0') {
        cout << '0' << endl;
        return 0;
    }

    for (int i = 1; i < s.length(); i++) {
        int cur = s[i] - '0';
        int bef = s[i - 1] - '0';
        if (cur == 0) {
            if (bef > 2 || bef == 0) {
                cout << '0' << endl;
                return 0;
            } else {
                dp[i + 1] = dp[i - 1] % 1000000;
            }
        } else {
            if (bef == 0) {
                dp[i + 1] = dp[i] % 1000000;
            } else if (cur <= 6 && bef <= 2) {
                dp[i + 1] = (dp[i - 1] % 1000000 + dp[i] % 1000000) % 1000000;
            } else if (cur <= 6 && bef > 2) {
                dp[i + 1] = dp[i] % 1000000;
            } else if (cur > 6 && bef < 2) {
                dp[i + 1] = (dp[i - 1] % 1000000 + dp[i] % 1000000) % 1000000;
            } else if (cur > 6 && bef >= 2) {
                dp[i + 1] = dp[i] % 1000000;
            }
        }
    }
    cout << dp[s.length()] << endl;
}