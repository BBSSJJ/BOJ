#include <iostream>
#include <vector>

using namespace std;

int N, x;
int cost[1002][4];
int paint[1002][4];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> cost[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 3; j++) {
            if (j == 1) {
                paint[i][j] = min(paint[i - 1][2], paint[i - 1][3]) + cost[i][j];
            }
            if (j == 2) {
                paint[i][j] = min(paint[i - 1][1], paint[i - 1][3]) + cost[i][j];
            }
            if (j == 3) {
                paint[i][j] = min(paint[i - 1][1], paint[i - 1][2]) + cost[i][j];
            }
        }
    }
    int answer = min(paint[N][1], paint[N][2]);
    answer = min(answer, paint[N][3]);
    cout << answer << endl;
}