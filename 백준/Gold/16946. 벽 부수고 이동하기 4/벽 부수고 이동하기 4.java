
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    static int N;
    static int M;

    static int[][] graph;
    static int[] parent;
    static int[] size;
    static boolean[][] visited;
    static int[][] answer;

    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        graph = new int[N][M];
        visited = new boolean[N][M];
        parent = new int[N * M];
        size = new int[N * M];
        answer = new int[N][M];

        for (int i = 0; i < N * M; i++) {
            parent[i] = i;
            size[i] = 0;
        }

        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            for (int j = 0; j < M; j++) {
                graph[i][j] = str.charAt(j) - '0';
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (graph[i][j] == 0 && !visited[i][j]) {
                    union(i, j);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                answer[i][j] = 0;
                if (graph[i][j] == 1) {
                    int count = 1;
                    Set<Integer> set = new HashSet<>();
                    for (int d = 0; d < 4; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        if (outOfBound(nx, ny)) continue;
                        int nIdx = nx * M + ny;
                        int nParent = parent[nIdx];
                        if (set.contains(nParent)) continue;
                        count += size[nParent];
                        set.add(nParent);
                    }
                    answer[i][j] = count % 10;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                System.out.print(answer[i][j]);
            }
            System.out.println();
        }


    }

    public static void union(int x, int y) {
        visited[x][y] = true;
        Queue<int[]> que = new LinkedList<int[]>();
        que.offer(new int[]{x, y});
        int idx = x * M + y;
        size[idx] = 1;

        while (!que.isEmpty()) {
            int[] cur = que.poll();
            for (int i = 0; i < 4; i++) {
                int nx = cur[0] + dx[i];
                int ny = cur[1] + dy[i];
                if (outOfBound(nx, ny) || visited[nx][ny] || graph[nx][ny] == 1) continue;
                visited[nx][ny] = true;
                que.offer(new int[]{nx, ny});
                int nIdx = nx * M + ny;
                parent[nIdx] = idx;
                size[idx]++;
            }
        }
    }

    public static boolean outOfBound(int x, int y) {
        return x < 0 || y < 0 || x >= N || y >= M;
    }


}