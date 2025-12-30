import java.util.*;
import java.io.*;

public class Main {
    static int N, answer;
    static int[][] board;
    static int[] dx = { -1, 0, 1, 0 }; // up, right, down, left
    static int[] dy = { 0, 1, 0, -1 };
    static int[] sx, sy;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        board = new int[N][N];
        sx = new int[] { N - 1, 0, 0, N - 1 };
        sy = new int[] { 0, 0, N - 1, N - 1 };

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        bt(0, board);
        System.out.println(answer);
    }

    public static void bt(int depth, int[][] cur) {
        if (depth == 5) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    answer = Math.max(answer, cur[i][j]);
                }
            }
            return;
        }

        for (int d = 0; d < 4; d++) {
            int[][] next = new int[N][N];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    next[i][j] = cur[i][j];
                }
            }
            move(d, next);
            bt(depth + 1, next);
        }
    }

    public static void move(int dir, int[][] next) {

        int nDir = (dir + 1) % 4;
        for (int i = 0; i < N; i++) {
            int bx = sx[dir] + dx[nDir] * i;
            int by = sy[dir] + dy[nDir] * i;
            int before = next[bx][by];
            List<Integer> tmp = new ArrayList<>();

            for (int j = 1; j < N; j++) {
                int cx = bx + dx[dir] * j;
                int cy = by + dy[dir] * j;
                if (next[cx][cy] == 0)
                    continue;
                if (before == -1) {
                    before = next[cx][cy];
                } else if (before != next[cx][cy]) {
                    tmp.add(before);
                    before = next[cx][cy];
                } else {
                    tmp.add(before * 2);
                    before = -1;
                }
            }
            if (before != -1) {
                tmp.add(before);
            }

            int idx = 0;
            for (int t = 0; t < tmp.size(); t++) {
                if (tmp.get(t) == 0)
                    continue;
                next[bx + dx[dir] * idx][by + dy[dir] * idx] = tmp.get(t);
                idx++;
            }
            for (; idx < N; idx++) {
                next[bx + dx[dir] * idx][by + dy[dir] * idx] = 0;
            }
        }
    }
}
