
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, n;
vector<int> numbers;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n;
        numbers.push_back(n);
    }
    sort(numbers.begin(), numbers.end());

    int answer = 0;
    int nIdx = -1;
    int pIdx = N;
    for (int i = 0; i < N; i++) {
        if (numbers[i] <= 0) nIdx = i;
        if (numbers[i] > 1) {
            pIdx = i;
            break;
        }
    }
    answer += (pIdx - nIdx - 1);

    for (int i = 0; i <= nIdx; i += 2) {
        if (i == nIdx)
            answer += numbers[i];
        else
            answer += (numbers[i] * numbers[i + 1]);
    }
    for (int i = N - 1; i >= pIdx; i -= 2) {
        if (i == pIdx)
            answer += numbers[i];
        else
            answer += (numbers[i] * numbers[i - 1]);
    }
    cout << answer;
}
