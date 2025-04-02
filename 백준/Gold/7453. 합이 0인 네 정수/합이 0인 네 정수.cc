#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;

using namespace std;

int n;
ll answer;
vector<vector<int>> arr;
vector<vector<ll>> sums;
// 16000000
// n^2 다..아니면 n^2 log n
int main() {
    cin >> n;
    arr = vector<vector<int>>(4, vector<int>(n));
    sums = vector<vector<ll>>(2, vector<ll>());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[j][i];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sums[0].push_back((ll)arr[0][i] + arr[1][j]);
            sums[1].push_back((ll)arr[2][i] + arr[3][j]);
        }
    }

    sort(sums[0].begin(), sums[0].end());
    sort(sums[1].begin(), sums[1].end());

    for (int i = 0; i < n * n; i++) {
        ll cur = sums[0][i];
        answer += upper_bound(sums[1].begin(), sums[1].end(), cur * (-1)) - lower_bound(sums[1].begin(), sums[1].end(), cur * (-1));
    }
    cout << answer;
}