import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int R, C;
	static char[][] map;
	static boolean[][] visited;
	static int startX, startY, endX, endY;
	static int[] dx = { -1, 0, 1, 0 };
	static int[] dy = { 0, 1, 0, -1 };
	static int[] answer;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));// 입력을 위한 BufferedReader 생성
		StringTokenizer st;// 입력을 토큰 단위로 나누기 위한 StringTokenizer 생성

		st = new StringTokenizer(br.readLine()); // R과 C를 입력받은 줄 저장
		R = Integer.parseInt(st.nextToken()); // R 입력
		C = Integer.parseInt(st.nextToken()); // C 입력

		map = new char[R][C]; // 지도 초기화
		visited = new boolean[R][C]; // visited 배열 초기화
		answer = new int[2]; // 정답 x, y 저장할 배열 초기화

		for (int i = 0; i < R; i++) { // 입력받기
			map[i] = br.readLine().toCharArray();
			for (int j = 0; j < C; j++) {
				if (map[i][j] == 'M') { // M 위치 저장
					startX = i;
					startY = j;
				}
				if (map[i][j] == 'Z') { // Z 위치 저장
					endX = i;
					endY = j;
				}
			}
		}

		visited[startX][startY] = true;

		dfs(startX, startY, 0);

		// answer 보고 사방 탐색하여 연결이 필요한 방향 저장
		boolean[] direction = new boolean[4];
		for (int i = 0; i < 4; i++) {
			int nx = answer[0] + dx[i];
			int ny = answer[1] + dy[i];
			if (OOB(nx, ny))
				continue;
			if (map[nx][ny] != '.') {
				if (i == 0 && (map[nx][ny] == '|' || map[nx][ny] == '1' || map[nx][ny] == '4' || map[nx][ny] == '+'))
					direction[i] = true;
				if (i == 1 && (map[nx][ny] == '-' || map[nx][ny] == '3' || map[nx][ny] == '4' || map[nx][ny] == '+'))
					direction[i] = true;
				if (i == 2 && (map[nx][ny] == '|' || map[nx][ny] == '2' || map[nx][ny] == '3' || map[nx][ny] == '+'))
					direction[i] = true;
				if (i == 3 && (map[nx][ny] == '-' || map[nx][ny] == '1' || map[nx][ny] == '2' || map[nx][ny] == '+'))
					direction[i] = true;
			}
		}

		char road = '0'; // 필요한 도로 저장할 변수

		// 연결이 필요한 방향에 따라 도로 선택
		if (direction[0] && direction[1] && direction[2] && direction[3])
			road = '+';
		else if (direction[2] && direction[1])
			road = '1';
		else if (direction[0] && direction[1])
			road = '2';
		else if (direction[0] && direction[3])
			road = '3';
		else if (direction[2] && direction[3])
			road = '4';
		else if (direction[3] && direction[1])
			road = '-';
		else if (direction[0] && direction[2])
			road = '|';

		System.out.println((answer[0] + 1) + " " + (answer[1] + 1) + " " + road);

	}

	static void dfs(int x, int y, int from) { // from에 i 들어가면 됨 (이전에 온 방향)
		visited[x][y] = true; // 방문 설정
		if (map[x][y] == '|') { // 현재 노드가 | 일 경우
			if (from == 0) // 아래서 왔으면 위로 이동
				dfs(x - 1, y, from);
			if (from == 2) // 위에서 왔으면 아래로 이동
				dfs(x + 1, y, from);
		}
		if (map[x][y] == '-') { // 현재 노드가 -일 경우
			if (from == 1) // 왼쪽에서 왔으면 오른쪽으로 이동
				dfs(x, y + 1, from);
			if (from == 3) // 오른쪽에서 왔으면 왼쪽을 ㅗ이동
				dfs(x, y - 1, from);
		}
		if (map[x][y] == 'M') { // 현재 노드가 +나 M 일 경우
			for (int i = 0; i < 4; i++) { // 4방 탐색
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (OOB(nx, ny) || visited[nx][ny]) // 방문된 곳이면 continue
					continue;
				if (map[nx][ny] != '.') { // .이 아닌 곳으로 이동
					dfs(nx, ny, i);
				}
			}
		}
		if (map[x][y] == '+') {
			visited[x][y] = false;
			if (from == 0) // 아래서 왔으면 위로 이동
				dfs(x - 1, y, from);
			if (from == 2) // 위에서 왔으면 아래로 이동
				dfs(x + 1, y, from);
			if (from == 1) // 왼쪽에서 왔으면 오른쪽으로 이동
				dfs(x, y + 1, from);
			if (from == 3) // 오른쪽에서 왔으면 왼쪽을 ㅗ이동
				dfs(x, y - 1, from);
		}
		if (map[x][y] == '1') { // 현재 노드가 1일 경우
			if (from == 0) // 아래서 왔으면 오른쪽으로 이동
				dfs(x, y + 1, 1);
			if (from == 3) // 오른쪽에서 왔으면 아래로 이동
				dfs(x + 1, y, 2);
		}
		if (map[x][y] == '2') { // 현재 노드가 2일 경우
			if (from == 2) // 위에서 온 경우 오른쪽으로 이동
				dfs(x, y + 1, 1);
			if (from == 3) // 오른쪽에서 온 경우 위로 이동
				dfs(x - 1, y, 0);
		}
		if (map[x][y] == '3') { // 현재 노드가 3일 경우
			if (from == 1) // 왼쪽에서 온 경우 위로 이동
				dfs(x - 1, y, 0);
			if (from == 2) // 위에서 온 경우 왼쪽으로 이동
				dfs(x, y - 1, 3);
		}
		if (map[x][y] == '4') {// 현재 노드가 4일 경우
			if (from == 1) // 왼쪽에서 온 경우 아래로 이동
				dfs(x + 1, y, 2);
			if (from == 0) // 아래서 온 경우 왼쪽으로 이동
				dfs(x, y - 1, 3);
		}
		if (map[x][y] == '.') { // 현재 노드가ㅣ . 일 경우 도로가 필요한 것
			answer[0] = x; // 정답 배열에 x값 저장
			answer[1] = y; // 정답 배열에 y값 저장
		}
		if (map[x][y] == 'Z') // Z만나면 끝
			return; // 리턴
	}

	static boolean OOB(int x, int y) { // map 범위 나갔는지 판단하는 함수
		if (x < 0 || y < 0 || x >= R || y >= C)
			return true;
		else
			return false;
	}

}