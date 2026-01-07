#include <algorithm>
#include <iostream>

using namespace std;

int N, M, L, n;

int main() {
    cin >> N >> M >> L;
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(L);
    for (int i = 0; i < N; i++) {
        cin >> n;
        vec.push_back(n);
    }
    sort(vec.begin(), vec.end());

    int start = 1;
    int end = L - 1;
    int mid;

    while (start < end) {
        mid = (start + end) / 2;
        int totalCount = 0;
        for (int i = 1; i < vec.size(); i++) {
            int gap = vec[i] - vec[i - 1];
            int count = gap / mid;
            if (gap % mid == 0) count -= 1;
            totalCount += count;
        }
        if (totalCount > M)
            start = mid + 1;
        else
            end = mid;
    }
    cout << start;
}