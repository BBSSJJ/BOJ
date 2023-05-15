#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, nn;
int office[8][8];
int office_tmp[8][8];
vector<pair<int, int>> cctv;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int count() {
	int c = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (office_tmp[i][j] == 0) {
				c += 1; 
			}
		}
	}
	return c;
}

void watch(int x, int y, int direction) {
	direction = direction % 4;
	while (1) {
		x += dx[direction];
		y += dy[direction];
		if (x < 0 || y < 0 || x >= N || y >= M) return;
		if (office_tmp[x][y] == 6) return;
		if (office_tmp[x][y] != 0) continue;
			office_tmp[x][y] = -1;
	}
}

void active_cctv(int j, int direction) {
	int x = cctv[j].first;
	int y = cctv[j].second;
	int type = office[x][y];

	if (type == 1) {
		watch(x, y, direction);
	}
	else if (type == 2) {
		watch(x, y, direction);
		watch(x, y, direction + 2);

	}
	else if (type == 3) {
		watch(x, y, direction);
		watch(x, y, direction + 1);
	}
	else if (type == 4) {
		watch(x, y, direction);
		watch(x, y, direction + 1);
		watch(x, y, direction + 2);
	}
	else if (type == 5) {
		watch(x, y, direction);
		watch(x, y, direction + 1);
		watch(x, y, direction + 2);
		watch(x, y, direction + 3);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> nn;
			office[i][j] = nn;
			office_tmp[i][j] = nn;
			if (nn != 0 && nn != 6) {
				cctv.push_back({ i, j });
			}
		}
	}
	int answer = 65;
	int cctv_count = cctv.size();

	int iter = 1;
	for (int i = 0; i < cctv_count; i++) {
		iter *= 4;
	}

	for (int i = 0; i < iter; i++) {
		int i_tmp = i;
		for (int j = 0; j < cctv_count; j++) {

			int direction = i_tmp % 4;

			active_cctv(j, direction);

			i_tmp = i_tmp / 4;
		}
		answer = min(answer, count());


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				office_tmp[i][j] = office[i][j];
			}
		}

	}
	cout << answer << endl;

}

// 0은 위, 1은 오른쪽, 2는 아래, 3은 왼쪽