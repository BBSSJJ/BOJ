import java.io.*;
import java.util.*;

public class Main {

    static LinkedList<int[]>[][] turnOn;
    static boolean[][] visited;
    static boolean[][] light;
    static int N, M;
    static int[] dx = { -1, 1, 0, 0 };
    static int[] dy = { 0, 0, -1, 1 };
    static int answer = 1;

    public static boolean outOfBound(int x, int y) {
        return (x < 0 ||  y < 0 || x >= N || y >= N);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        visited = new boolean[N][N];
        light = new boolean[N][N];

        turnOn = new LinkedList[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                turnOn[i][j] = new LinkedList<>();
            }
        }
        light[0][0] = true;
        visited[0][0] = true;

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a, b, c, d;
            a = Integer.parseInt(st.nextToken()) - 1;
            b = Integer.parseInt(st.nextToken()) - 1;
            c = Integer.parseInt(st.nextToken()) - 1;
            d = Integer.parseInt(st.nextToken()) - 1;
            turnOn[a][b].add(new int[] { c, d });
        }
        
        Queue<int[]> que = new LinkedList<>();
        que.add(new int[] { 0, 0 });
        while (!que.isEmpty()) {
            int[] cur = que.poll();

            // 불 켜기
            for (int[] next : turnOn[cur[0]][cur[1]]) {
                if (light[next[0]][next[1]])
                    continue;
                light[next[0]][next[1]] = true;
                answer++;
                // 새로 켜진 방이 이미 방문한 방과 인접하면 이동 가능
                for (int i = 0; i < 4; i++) {
                    int px = next[0] + dx[i];
                    int py = next[1] + dy[i];
                    if (outOfBound(px, py))
                        continue;
                    if (visited[px][py]) {
                        visited[next[0]][next[1]] = true;
                        que.add(new int[] { next[0], next[1] });
                        break;
                    }
                }
            }

            // 이동
            for (int i = 0; i < 4; i++) {
                int nx = cur[0] + dx[i];
                int ny = cur[1] + dy[i];
                if (outOfBound(nx, ny))
                    continue;
                if (!light[nx][ny] || visited[nx][ny])
                    continue;
                visited[nx][ny] = true;
                que.add(new int[] { nx, ny });
            }

        }
        

        System.out.println(answer);
    }
}
