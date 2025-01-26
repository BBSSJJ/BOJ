#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int N;
string b, before, after;

int main() {
    cin >> N >> b >> after;
    int answer = INT_MAX;

    // 0번째 눌렀을 때
    int count = 1;
    before = b;
    before[0] = before[0] == '0' ? '1' : '0';
    before[1] = before[1] == '0' ? '1' : '0';
    for (int i = 1; i < N - 1; i++) {
        if (before[i - 1] != after[i - 1]) {
            before[i - 1] = before[i - 1] == '0' ? '1' : '0';
            before[i] = before[i] == '0' ? '1' : '0';
            before[i + 1] = before[i + 1] == '0' ? '1' : '0';
            count++;
        }
    }
    if (before[N - 2] != after[N - 2]) {
        before[N - 2] = before[N - 2] == '0' ? '1' : '0';
        before[N - 1] = before[N - 1] == '0' ? '1' : '0';
        count++;
    }
    bool success = true;
    for (int i = 0; i < N; i++) {
        if (before[i] != after[i]) {
            success = false;
        }
    }
    if (success) {
        answer = min(answer, count);
    }

    // 0번째 안눌렀을 때
    count = 0;
    before = b;
    for (int i = 1; i < N - 1; i++) {
        if (before[i - 1] != after[i - 1]) {
            before[i - 1] = before[i - 1] == '0' ? '1' : '0';
            before[i] = before[i] == '0' ? '1' : '0';
            before[i + 1] = before[i + 1] == '0' ? '1' : '0';
            count++;
        }
    }
    if (before[N - 2] != after[N - 2]) {
        before[N - 2] = before[N - 2] == '0' ? '1' : '0';
        before[N - 1] = before[N - 1] == '0' ? '1' : '0';
        count++;
    }
    success = true;
    for (int i = 0; i < N; i++) {
        if (before[i] != after[i]) {
            success = false;
        }
    }
    if (success) {
        answer = min(answer, count);
    }

    if (answer == INT_MAX)
        cout << -1;
    else
        cout << answer;
}