#include <iostream>

using namespace std;

int N, k;
int S[1000];

void divide(int n, int k) {
    if (k == 0) {
        if (n == 1) {
            cout << "m";
            return;
        } else {
            cout << "o";
            return;
        }
    }

    if (n <= S[k - 1]) {
        divide(n, k - 1);
    } else if (n > S[k - 1] + k + 3) {
        divide(n - (S[k - 1] + k + 3), k - 1);
    } else {
        int _n = n - S[k - 1];
        if (_n == 1) {
            cout << "m";
            return;
        } else {
            cout << "o";
            return;
        }
    }
}

int main() {
    cin >> N;
    S[0] = 3;

    k = 1000;

    for (int i = 1; i < 1000; i++) {
        S[i] = S[i - 1] * 2 + i + 3;
        if (N < S[i]) {
            k = min(k, i);
        }
    }

    divide(N, k);
}