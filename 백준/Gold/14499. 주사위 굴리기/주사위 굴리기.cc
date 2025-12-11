#include <iostream>

using namespace std;

int N, M, K, dir;
int map[20][20];
// int dice[4][3] = { {0, 2, 0},{4, 1, 3},{0, 5, 0},{0, 6, 0} };
int dice[4][3];


int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

bool OOB(int x, int y) {
	return (x < 0 || y < 0 || x >= N || y >= M);
}

void rollDice(int dir) {
	if (dir == 0) {	//동쪽
		int tmp = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = dice[3][1];
		dice[3][1] = tmp;
	}
	else if (dir == 1) {//서쪽
		int tmp = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = dice[3][1];
		dice[3][1] = tmp;
	}
	else if (dir == 2) {//북쪽
		int tmp = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = dice[3][1];
		dice[3][1] = tmp;
	}
	else if (dir == 3) {//남쪽
		int tmp = dice[3][1];
		dice[3][1] = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = dice[0][1];
		dice[0][1] = tmp;
	}

}
int main() {
	int sx = 0;
	int sy = 0;

	cin >> N >> M >> sx >> sy >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int nx = sx;
	int ny = sy;
	

	for (int i = 0; i < K; i++) {
		cin >> dir;
		dir -= 1;

		nx += dx[dir];
		ny += dy[dir];
		if (OOB(nx, ny)) {
			nx -= dx[dir];
			ny -= dy[dir];
			continue;
		}

		rollDice(dir);

		if (map[nx][ny] == 0) {
			map[nx][ny] = dice[3][1];
		}
		else {
			dice[3][1] = map[nx][ny];
			map[nx][ny] = 0;
		}



		cout << dice[1][1] << "\n";

	}
}