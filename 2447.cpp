#include <iostream>

using namespace std;

int N;
char shape[7000][7000];

void draw(int x, int y, int n) {
    if (n == 3) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 1 && j == 1) continue;
                shape[x + i][y + j] = '*';
            }
        }
        return;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            draw(x + (n / 3) * i, y + (n / 3) * j, n / 3);
        }
    }
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            shape[i][j] = ' ';
        }
    }

    draw(0, 0, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << shape[i][j];
        }
        cout << "\n";
    }
}