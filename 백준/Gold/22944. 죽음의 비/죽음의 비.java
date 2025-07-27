
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int N, H, D, sx, sy;
    static Character[][] board;
    static int[][] visited;
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};

    static class Status {
        int x;
        int y;
        int health;
        int umbrella;
        int dist;

        public Status(int x, int y, int health, int umbrella, int dist) {
            this.x = x;
            this.y = y;
            this.health = health;
            this.umbrella = umbrella;
            this.dist = dist;
        }
    }

    public static boolean outOfBound(int x, int y) {
        return x < 0 || y < 0 || x >= N || y >= N;
    }

    public static int bfs() {
        Queue<Status> que = new LinkedList<>();
        que.offer(new Status(sx, sy, H, 0, 0));
        visited[sx][sy] = H;


        while (!que.isEmpty()) {
            Status cur = que.poll();

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                int numbrella = cur.umbrella;
                int nhealth = cur.health;
                int ndist = cur.dist + 1;
                if (outOfBound(nx, ny)) continue;
                // 먼저 죽여야 언먹는다!

                if (board[nx][ny] == 'E') {
                    return ndist;
                }
                if (board[nx][ny] == 'U') numbrella = D;
                if (numbrella >= 1) numbrella -= 1;
                else nhealth -= 1;
                if (nhealth <= 0) continue;
                if (visited[nx][ny] >= nhealth + numbrella) continue;
                visited[nx][ny] = nhealth + numbrella;
                que.offer(new Status(nx, ny, nhealth, numbrella, ndist));


            }
        }
        return -1;
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());


        board = new Character[N][N];
        visited = new int[N][N];

        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            for (int j = 0; j < N; j++) {
                board[i][j] = str.charAt(j);
                if (board[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
            }
        }

        System.out.println(bfs());


    }
}
