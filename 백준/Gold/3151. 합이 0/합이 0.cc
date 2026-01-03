#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;

int main() {
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    long long answer = 0;

    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
            long long cnt = v[i] + v[j];
            int idx1 =
                lower_bound(v.begin() + j + 1, v.end(), -1 * cnt) - v.begin();
            int idx2 =
                upper_bound(v.begin() + j + 1, v.end(), -1 * cnt) - v.begin();
            answer += idx2 - idx1;
        }
    }
    cout << answer;
}
