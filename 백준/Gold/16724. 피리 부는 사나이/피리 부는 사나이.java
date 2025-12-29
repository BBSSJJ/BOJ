import java.util.*;
import java.io.*;

public class Main {
    static int N, M, cycleCount;
    static char[][] board;
    static int[][] group;
    static int[] dx = { -1, 1, 0, 0 }; // Up, Down, Left, Right
    static int[] dy = { 0, 0, -1, 1 };
    static int[][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        board = new char[N][M];
        visited = new int[N][M];
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            board[i] = line.toCharArray();
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j] == 0) {
                    dfs(i, j);
                }
            }
        }
        System.out.println(cycleCount);

    }

    public static int getDirection(int x, int y) {
        char cell = board[x][y];
        if (cell == 'U')
            return 0;
        if (cell == 'D')
            return 1;
        if (cell == 'L')
            return 2;
        if (cell == 'R')
            return 3;
        return -1;
    }

    public static void dfs(int x, int y) {
        visited[x][y] = 1;
        int dir = getDirection(x, y);
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (visited[nx][ny] == 0) {
            dfs(nx, ny);
        } else if (visited[nx][ny] == 1) {
            cycleCount++;
        }
        visited[x][y] = 2;
    }

}
