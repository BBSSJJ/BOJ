import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static int[] population;
    static int[][] dp;
    static boolean[] visited;

    static List<List<Integer>> graph = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        population = new int[N + 1];
        dp = new int[N + 1][2];
        visited = new boolean[N + 1];

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<Integer>());
        }
        for (int i = 1; i <= N; i++) {
            population[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        dfs(1);
        System.out.println(Math.max(dp[1][0], dp[1][1]));
    }

    public static void dfs(int cur) {
        visited[cur] = true;
        dp[cur][1] = population[cur];

        for (int i = 0; i < graph.get(cur).size(); i++) {
            int next = graph.get(cur).get(i);
            if (visited[next])
                continue;
            dfs(next);
            dp[cur][0] += Math.max(dp[next][0], dp[next][1]);
            dp[cur][1] += dp[next][0];
        }
    }
}
