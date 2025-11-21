import java.util.*;
import java.io.*;

public class Main {
    public static int N, sx, sy, ex, ey;
    public static char[][] board;
    public static int[] dx = { 1, 0, -1, 0 };
    public static int[] dy = { 0, 1, 0, -1 };

    public static boolean outOfBound(int x, int y) {
        return x < 0 || y < 0 || x >= N || y >= N;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        board = new char[N][N];

        sx = -1;
        for (int i = 0; i < N; i++) {
            String tmp = br.readLine();
            for (int j = 0; j < N; j++) {
                board[i][j] = tmp.charAt(j);
                if (board[i][j] == '#') {
                    if (sx != -1) {
                        ex = i;
                        ey = j;
                    } else {
                        sx = i;
                        sy = j;
                    }
                }
            }
        }
        dijkstra();

    }
    
    public static void dijkstra() {
        int[][][] mirror = new int[N][N][4];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < 4; k++) {
                    if (i == sx && j == sy)
                        mirror[i][j][k] = 0;
                    else
                        mirror[i][j][k] = Integer.MAX_VALUE;
                }
            }
        }
        
        PriorityQueue<Status> pq = new PriorityQueue<Status>();
        pq.offer(new Status(sx, sy, 0, 0));
        pq.offer(new Status(sx, sy, 0, 1));
        pq.offer(new Status(sx, sy, 0, 2));
        pq.offer(new Status(sx, sy, 0, 3));

        while (!pq.isEmpty()) {
            Status cur = pq.poll();

            if (mirror[cur.x][cur.y][cur.beforeDir] < cur.mCount)
                continue;

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (outOfBound(nx, ny) || board[nx][ny] == '*')
                    continue;
                int nmCount = cur.mCount;
                if (board[cur.x][cur.y] == '.' && cur.beforeDir != i)
                    continue;
                if (board[cur.x][cur.y] == '!' && cur.beforeDir != i)
                    nmCount += 1;
                if (mirror[nx][ny][i] <= nmCount)
                    continue;

                mirror[nx][ny][i] = nmCount;
                pq.offer(new Status(nx, ny, nmCount, i));
            }
        }
        int answer = Integer.MAX_VALUE;
        for (int i = 0; i < 4; i++) {
            answer = Math.min(mirror[ex][ey][i], answer);
        }
        System.out.println(answer);
    }

    public static class Status implements Comparable<Status> {
        int x;
        int y;
        int mCount;
        int beforeDir;

        public Status(int x, int y, int mCount, int beforeDir) {
            this.x = x;
            this.y = y;
            this.mCount = mCount;
            this.beforeDir = beforeDir;
        }

        public int compareTo(Status st) {
            return mCount - st.mCount;
        }
    }
}
