import java.util.*;
import java.io.*;

public class Main {
    public static int N, M, K;
    public static String target;
    public static char[][] board;
    public static int[][][] dp;
    public static int[] dx = { 1, 0, -1, 0 };
    public static int[] dy = { 0, 1, 0, -1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        board = new char[N][M];
        dp = new int[N][M][81];

        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            for (int j = 0; j < M; j++) {
                board[i][j] = str.charAt(j);
                for (int k = 0; k < 81; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        target = br.readLine();

        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == target.charAt(0)) {
                    dfs(i, j, 0);
                    answer += dp[i][j][0];
                }
            }
        }

        System.out.println(answer);
    }

    public static void dfs(int x, int y, int idx) {
        if (idx == target.length() - 1) {
            dp[x][y][idx] = 1;
            return;
        }

        dp[x][y][idx] = 0;
        for (int k = 1; k <= K; k++) {
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i] * k;
                int ny = y + dy[i] * k;
                if (outOfBound(nx, ny))
                    continue;
                if (board[nx][ny] != target.charAt(idx + 1))
                    continue;
                if (dp[nx][ny][idx + 1] == -1)
                    dfs(nx, ny, idx + 1);
                dp[x][y][idx] += dp[nx][ny][idx + 1];

            }
        }

    }

    public static boolean outOfBound(int x, int y) {
        return x < 0 || y < 0 || x >= N || y >= M;
    }

}
