#include <iostream>

using namespace std;

int v[60];
int h[60];
int x1[60];  // j - i + 4
int x2[60];  // i + j
int N;
int answer;
void bt(int);

int main() {
    cin >> N;
    bt(0);
    cout << answer;
}

void bt(int x) {
    if (x == N) {
        answer++;
        return;
    }
    for (int j = 0; j < N; j++) {
        if (h[j] || x1[j - x + N] || x2[x + j])
            continue;
        else {
            h[j] = 1;
            x1[j - x + N] = 1;
            x2[x + j] = 1;
            bt(x + 1);
            h[j] = 0;
            x1[j - x + N] = 0;
            x2[x + j] = 0;
        }
    }
}