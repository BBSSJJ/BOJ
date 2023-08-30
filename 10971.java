import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int[][] map;
    static boolean[] visited;
    static int min = Integer.MAX_VALUE;
    static int cost;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        map = new int[N][N];
        visited = new boolean[N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        visited[0] = true;
        cost = 0;
        dfs(1, 0);

        System.out.println(min);

    }

    static void dfs(int count, int from) {

        if (count == N) {
            if (map[from][0] == 0) return;
            cost += map[from][0];
            min = Math.min(min, cost);
            cost -= map[from][0];

            return;
        }

        for (int i = 0; i < N; i++) {
            if (visited[i])
                continue;
            if (map[from][i] == 0) continue;
            visited[i] = true;
            cost += map[from][i];
            dfs(count + 1, i);
            visited[i] = false;
            cost -= map[from][i];
        }
    }

}