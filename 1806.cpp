#include <iostream>
#include <vector>
using namespace std;

int N, S, n;
vector<int> numbers;
int main() {
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> n;
        numbers.push_back(n);
    }

    int st = 0;
    int ed = 0;
    int sum = numbers[st];
    int answer = 99999999;

    while (ed <= N && st <= ed) {
        if (sum < S) {
            ed++;
            sum += numbers[ed];
        } else if (sum >= S) {
            answer = min(answer, ed - st + 1);
            sum -= numbers[st];
            st++;
        }
        if (ed >= N) break;
    }
    if (answer == 99999999)
        cout << 0 << endl;
    else
        cout << answer << endl;
}
