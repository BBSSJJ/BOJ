import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int[][] sharks; // 상어의 정보 / [0]->생사여부, [1]->x, [2]->y, [3]->속력, [4]->이동방향, [5]->크기
	static int dx[] = { 0, -1, 1, 0, 0 }; // 위 아래 오른쪽 왼쪽 순서, 0번째는 사용x
	static int dy[] = { 0, 0, 0, 1, -1 };
	static int[][] ocean; // 바다에 상어 저장
	static int[][] tmpOcean; // 상어 움직일 때 임시로 만들어둔 바다
	static int R, C, M;
	static int sizeSum; // 답

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		sharks = new int[M + 1][6];
		ocean = new int[R][C];
		sizeSum = 0;

		for (int i = 1; i <= M; i++) {	//상어 정보 입력, i가 상어의 고유 번호가 될 것임
			st = new StringTokenizer(br.readLine());
			sharks[i][0] = 1;	//생사여부 처음은 1
			sharks[i][1] = Integer.parseInt(st.nextToken()) - 1;	//x인덱스 0부터 시작해서 -1 해줌
			sharks[i][2] = Integer.parseInt(st.nextToken()) - 1;	//y인덱스 0부터 시작해서 -1 해줌
			sharks[i][3] = Integer.parseInt(st.nextToken());
			sharks[i][4] = Integer.parseInt(st.nextToken());
			sharks[i][5] = Integer.parseInt(st.nextToken());
		}

		for (int i = 1; i <= M; i++) {
			ocean[sharks[i][1]][sharks[i][2]] = i;
		}
		///////////////////////////////////////////////////// 여기까지 초기화///////

		// 실행
		for (int i = 0; i < C; i++) { //낚시꾼이 0부터 C-1까지 이동
			
			
			catchShark(i);	//낚시 먼저

			
			tmpOcean = new int[R][C];	// 상어 이동 겹치지 않도록 임시 저장할 바다 선어

			for (int j = 1; j <= M; j++) {	// sharks돌면서 
				if (sharks[j][0] == 1) // 살아있는 상어만 움직인다
					moveShark(j);
			}

			for (int j = 1; j <= M; j++) {	//다 움직인 후 살아있는 상어 찾아서 ocean에 저장해준다
				if (sharks[j][0] == 1) {
					ocean[sharks[j][1]][sharks[j][2]] = j;
				}
			}

		}

		System.out.println(sizeSum);

	}

	static void catchShark(int y) {		//상어잡기
		for (int i = 0; i < R; i++) {
			if (ocean[i][y] != 0) {		//바다가 0이 아닐 경우 상어임
				int shark = ocean[i][y];
				ocean[i][y] = 0;			//상어 자리 0으로
				sharks[shark][0] = 0;		//상어 죽었다고 표시
				sizeSum += sharks[shark][5];	//상어 무게 정답에 추가
				break;
			}
		}
	}

	static void moveShark(int shark) { // 인자로 받는 shark는 상어의 고유 번호
		int x = sharks[shark][1];
		int y = sharks[shark][2];
		int speed = sharks[shark][3];
		int dir = sharks[shark][4];
		ocean[x][y] = 0;		//움직일거니까 현재 위치는 바다에서 지워준다

		int length = (dir == 1 || dir == 2) ? R : C;	//dir 이 1이나 2이면 위아래로 움직이므로 폭은 R이 될것, 3 4의 경우 폭은 C


		int remain = speed % ((length - 1) * 2);	//iter만큼 돌고 남은 만큼은 직접 움직여주어야 함


		for (int i = 0; i < remain; i++) {	//직접 이동
			x += dx[dir];
			y += dy[dir];
			if (OOB(x, y)) {
				dir = changeDir(dir);
				x = x + dx[dir] * 2;
				y = y + dy[dir] * 2;
			}
		}

		// 상어 정보 업데이트
		sharks[shark][1] = x;
		sharks[shark][2] = y;
		sharks[shark][4] = dir;

		//임시 바다에 저장
		if (tmpOcean[x][y] != 0) {	//임시 바다에 이미 움직인 상어가 있으면
			int anotherShark = tmpOcean[x][y];	
			eatShark(shark, anotherShark, x, y);	//둘중 하나 먹어야 함
		} else {
			tmpOcean[x][y] = shark; //임시바다가 0인 경우는 상어 없으므로 상어 저장
		}
	}

	static void eatShark(int shark1, int shark2, int x, int y) {	//상어의 고유번호 2개 전달받고, 만난 위치도 전달받음
		int shark1Size = sharks[shark1][5];
		int shark2Size = sharks[shark2][5];
		if (shark1Size > shark2Size) {	//크기 비교 후 먹힐놈 선택
			tmpOcean[x][y] = shark1;	//임시 바다에 저장해주고
			sharks[shark2][0] = 0;		//먹힌 상어는 사망표시
		} else {

			tmpOcean[x][y] = shark2;
			sharks[shark1][0] = 0;
		}

	}

	static boolean OOB(int x, int y) {	//바다 밖으로 나갔는지 판단하는 함수
		if (x < 0 || y < 0 || x >= R || y >= C)
			return true;
		else
			return false;
	}

	static int changeDir(int dir) {	//반대 방향으로 바꿔주는 함수
		if (dir == 1)
			return 2;
		else if (dir == 2)
			return 1;
		else if (dir == 3)
			return 4;
		else if (dir == 4)
			return 3;
		return 0;
	}

}