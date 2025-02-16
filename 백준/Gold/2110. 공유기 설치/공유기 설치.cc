#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> house;
int N, C, x;

bool success(int hop) {
    int start = 0;
    int count = 1;

    for (int i = 0; i < N; i++) {
        if (house[start] + hop <= house[i]) {
            start = i;
            count++;
        }
    }

    return count >= C;
}

int main() {
    cin >> N >> C;

    for (int i = 0; i < N; i++) {
        cin >> x;
        house.push_back(x);
    }

    sort(house.begin(), house.end());

    int right = (house[N - 1] - house[0] + 1) * 2 / C;
    int left = 0;

    int answer = 0;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (success(mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer;
}