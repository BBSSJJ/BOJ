import java.util.*;
import java.io.*;

public class Main {
    static int N, M, K, result;
    static int[][] board, distance;
    static List<Point> dusts;
    static int[] dx = { 1, 0, -1, 0 };
    static int[] dy = { 0, 1, 0, -1 };

    static class Point {
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        while (true) {
            st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken());
            N = Integer.parseInt(st.nextToken());
            if (N == 0 && M == 0)
                break;
            board = new int[N][M];
            dusts = new ArrayList<>();

            dusts = new ArrayList<>();
            dusts.add(new Point(-1, -1));
            int sx = -1;
            int sy = -1;
            K = 1;
            for (int i = 0; i < N; i++) {
                String str = br.readLine();
                for (int j = 0; j < M; j++) {
                    board[i][j] = str.charAt(j);
                    if (board[i][j] == '*') {
                        board[i][j] = K++;
                        dusts.add(new Point(i, j));
                    }
                    if (board[i][j] == 'o') {
                        sx = i;
                        sy = j;
                        board[i][j] = 0;
                    }
                }
            }
            dusts.set(0, new Point(sx, sy));

            if (!initDistance()) {
                System.out.println(-1);
                continue;
            }

            result = Integer.MAX_VALUE;
            boolean[] selected = new boolean[K];
            selected[0] = true;
            dfs(0, 1, 0, selected);

            System.out.println(result);
        }

    }

    static void dfs(int cur, int count, int dist, boolean[] selected) {
        if (count == K) {
            result = Math.min(result, dist);
            return;
        }
        for (int i = 0; i < K; i++) {
            if (selected[i])
                continue;
            selected[i] = true;
            dfs(i, count + 1, dist + distance[cur][i], selected);
            selected[i] = false;
        }
    }

    static boolean initDistance() {
        distance = new int[K][K];
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                if (i == j)
                    distance[i][j] = 0;
                else
                    distance[i][j] = -1;
            }
        }

        for (int k = 0; k < K; k++) {
            Point start = dusts.get(k);
            int[][] visited = new int[N][M];
            for (int i = 0; i < N; i++) {
                Arrays.fill(visited[i], -1);
            }

            Queue<Point> que = new LinkedList<>();
            que.offer(start);
            visited[start.x][start.y] = 0;
            while (!que.isEmpty()) {
                Point cur = que.poll();
                for (int i = 0; i < 4; i++) {
                    int nx = cur.x + dx[i];
                    int ny = cur.y + dy[i];
                    if (outOfBound(nx, ny) || visited[nx][ny] != -1 || board[nx][ny] == 'x')
                        continue;

                    visited[nx][ny] = visited[cur.x][cur.y] + 1;

                    if (board[nx][ny] != '.')
                        distance[board[start.x][start.y]][board[nx][ny]] = visited[nx][ny];

                    que.offer(new Point(nx, ny));
                }
            }
        }
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                if (distance[i][j] == -1)
                    return false;
            }
        }

        return true;

    }

    static boolean outOfBound(int x, int y) {
        return x < 0 || y < 0 || x >= N || y >= M;
    }
}
