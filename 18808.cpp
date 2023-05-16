#include <iostream>
using namespace std;

int N, M, K, R, C;
int r, c, t;
int notebook[40][40];
int sticker[40][40];
int tmpsticker[40][40];

bool attach() {
	for (int i = 0; i < N - R + 1; i++) {
		for (int j = 0; j < M - C + 1; j++) {

			bool success = true;
			for (int p = 0; p < R; p++) {
				if (success == false) break;
				for (int q = 0; q < C; q++) {
					if (notebook[i + p][j + q] == 1 && sticker[p][q] == 1) {
						success = false;
						break;
					}
				}
			}

			if (success) {
				for (int p = 0; p < R; p++) {
					for (int q = 0; q < C; q++) {
						if (sticker[p][q] == 1)
							notebook[i + p][j + q] = 1;
					}
				}
				return true;
			}
		}
	}
	return false;
}
void rotate() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			tmpsticker[i][j] = sticker[i][j];
		}
	}

	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			sticker[i][j] = tmpsticker[R - 1 - j][i];
		}
	}
	int tmp = R;
	R = C;
	C = tmp;
}

int main() {
	cin >> N >> M >> K;
	
	for (int i = 0; i < K; i++) {
		cin >> R >> C;
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				cin >> t;
				sticker[r][c] = t;
				tmpsticker[r][c] = t;
			}
		}

		int iter = 4;
		while (iter--) {
			if (attach()) break;
			else rotate();

		}

	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (notebook[i][j] == 1) answer++;
		}
	}
	cout << answer << "\n";
}