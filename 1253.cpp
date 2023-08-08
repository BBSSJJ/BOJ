#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, n;
vector<int> v;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    int answer = 0;
    for (int i = 0; i < N; i++) {
        int target = v[i];
        int start = 0;
        int end = N - 1;
        while (start < end) {
            int sum = v[start] + v[end];

            if (sum == target) {
                if (start != i && end != i) {
                    answer++;
                    break;
                }
                if (start == i) start++;
                if (end == i) end--;
            } else if (sum <= target)
                start++;
            else
                end--;
        }
    }
    cout << answer;
}