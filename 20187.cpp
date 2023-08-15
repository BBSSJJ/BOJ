#include <iostream>
#include <vector>

using namespace std;
int K;
char c;
int hole;
int cx, cy;
int N;
vector<char> fold;
vector<vector<int>> paper;

int main() {
    cin >> K;

    N = 1 << K;
    paper.resize(N);
    for (int i = 0; i < N; i++) {
        paper[i].resize(N, 0);
    }

    int xLength = N;
    int yLength = N;

    for (int i = 0; i < K * 2; i++) {
        cin >> c;
        fold.push_back(c);
        if (c == 'D') {
            xLength /= 2;
            cx += xLength;
        }
        if (c == 'U') {
            xLength /= 2;
        }
        if (c == 'R') {
            yLength /= 2;
            cy += yLength;
        }
        if (c == 'L') {
            yLength /= 2;
        }
    }

    cin >> hole;
    paper[cx][cy] = hole;

    int xSize = 1;
    int ySize = 1;

    for (int t = K * 2 - 1; t >= 0; t--) {
        c = fold[t];
        if (c == 'R') {
            for (int i = 0; i < xSize; i++) {
                for (int j = 0; j < ySize; j++) {
                    int cur = paper[cx + i][cy + j];
                    if (cur == 1 || cur == 3) paper[cx + i][cy - j - 1] = cur - 1;
                    if (cur == 0 || cur == 2) paper[cx + i][cy - j - 1] = cur + 1;
                }
            }
            cy -= ySize;
            ySize *= 2;
        } else if (c == 'L') {
            for (int i = 0; i < xSize; i++) {
                for (int j = 0; j < ySize; j++) {
                    int cur = paper[cx + i][cy + j];
                    if (cur == 1 || cur == 3) paper[cx + i][cy + ySize * 2 - j - 1] = cur - 1;
                    if (cur == 0 || cur == 2) paper[cx + i][cy + ySize * 2 - j - 1] = cur + 1;
                }
            }
            ySize *= 2;
        } else if (c == 'U') {
            for (int i = 0; i < xSize; i++) {
                for (int j = 0; j < ySize; j++) {
                    int cur = paper[cx + i][cy + j];
                    if (cur == 2 || cur == 3) paper[cx + xSize * 2 - i - 1][cy + j] = cur - 2;
                    if (cur == 0 || cur == 1) paper[cx + xSize * 2 - i - 1][cy + j] = cur + 2;
                }
            }
            xSize *= 2;
        } else if (c == 'D') {
            for (int i = 0; i < xSize; i++) {
                for (int j = 0; j < ySize; j++) {
                    int cur = paper[cx + i][cy + j];
                    if (cur == 2 || cur == 3) paper[cx - i - 1][cy + j] = cur - 2;
                    if (cur == 0 || cur == 1) paper[cx - i - 1][cy + j] = cur + 2;
                }
            }
            cx -= xSize;
            xSize *= 2;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << paper[i][j] << " ";
        }
        cout << "\n";
    }
}