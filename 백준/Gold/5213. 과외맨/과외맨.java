import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static int[][] board;
    static int[][] area;
    static int[] before;
    static int[] dx = { 1, 0, -1, 0 };
    static int[] dy = { 0, 1, 0, -1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        board = new int[N][2 * N];
        area = new int[N][2 * N];
        before = new int[N * N + 1];

        int num = 1;
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < N; j++) {
                    st = new StringTokenizer(br.readLine());
                    int a = Integer.parseInt(st.nextToken());
                    int b = Integer.parseInt(st.nextToken());
                    board[i][j * 2] = a;
                    board[i][j * 2 + 1] = b;
                    area[i][j * 2] = num;
                    area[i][j * 2 + 1] = num;
                    num += 1;
                }
            } else {
                for (int j = 0; j < N - 1; j++) {
                    st = new StringTokenizer(br.readLine());
                    int a = Integer.parseInt(st.nextToken());
                    int b = Integer.parseInt(st.nextToken());
                    board[i][j * 2 + 1] = a;
                    board[i][j * 2 + 2] = b;
                    area[i][j * 2 + 1] = num;
                    area[i][j * 2 + 2] = num;
                    num += 1;
                }
            }

        }

        bfs();

        int target = 0;
        for (int i = N * N; i >= 0; i--) {
            if (before[i] != 0) {
                target = i;
                break;
            }
        }
        List<Integer> route = new ArrayList<>();
        route.add(target);
        while (before[target] != target) {
            route.add(before[target]);
            target = before[target];
        }

        System.out.println(route.size());
        for (int i = route.size() - 1; i >= 0; i--) {
            System.out.print(route.get(i) + " ");
        }

    }

    static void bfs() {
        Queue<int[]> que = new LinkedList<>();
        que.offer(new int[] { 0, 1 });
        before[1] = 1;

        while (!que.isEmpty()) {
            int[] cur = que.poll();

            for (int i = 0; i < 4; i++) {
                int nx = cur[0] + dx[i];
                int ny = cur[1] + dy[i];
                if (outOfBound(nx, ny))
                    continue;
                if (area[nx][ny] == 0)
                    continue;
                if (before[area[nx][ny]] != 0)
                    continue;
                if (board[nx][ny] != board[cur[0]][cur[1]])
                    continue;

                before[area[nx][ny]] = area[cur[0]][cur[1]];

                que.offer(new int[] { nx, ny });
                if (!outOfBound(nx, ny + 1) && area[nx][ny] == area[nx][ny + 1])
                    que.offer(new int[] { nx, ny + 1 });
                else if (!outOfBound(nx, ny - 1) && area[nx][ny] == area[nx][ny - 1])
                    que.offer(new int[] { nx, ny - 1 });
            }
        }
    }

    static boolean outOfBound(int x, int y) {
        return x < 0 || y < 0 || x >= N || y >= N * 2;
    }

}
