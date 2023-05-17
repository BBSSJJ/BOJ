#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, m, num;
vector<int> numbers;
vector<char> methods;
int max_result = -1000000000;
int min_result = 1000000000;
void calculate() {
    sort(methods.begin(), methods.end());
    do {
        int result = numbers[0];
        for (int i = 0; i < N - 1; i++) {
            if (methods[i] == '+') {
                result = result + numbers[i + 1];
            } else if (methods[i] == '-') {
                result = result - numbers[i + 1];
            } else if (methods[i] == '*') {
                result = result * numbers[i + 1];
            } else if (methods[i] == '/') {
                result = result / numbers[i + 1];
            }
        }
        max_result = max(max_result, result);
        min_result = min(min_result, result);
    } while (next_permutation(methods.begin(), methods.end()));
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        numbers.push_back(num);
    }
    for (int i = 0; i < 4; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            if (i == 0) {
                methods.push_back('+');
            } else if (i == 1) {
                methods.push_back('-');
            } else if (i == 2) {
                methods.push_back('*');
            } else if (i == 3) {
                methods.push_back('/');
            }
        }
    }
    calculate();
    cout << max_result << "\n" << min_result;
}