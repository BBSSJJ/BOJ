import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static int[][] dist;
    static int[][] dp; // dp[i][j]: i번째 도시까지 j비트마스크로 방문했을 때의 최소 비용
    static int INF = 987654321;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        dist = new int[N][N];
        dp = new int[N][2 << N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                dist[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < N; i++) {
            Arrays.fill(dp[i], -1);
        }
        System.out.println(dfs(0, 1));
    }

    static int dfs(int cur, int bit) {
        if (bit == (1 << N) - 1) {
            if (dist[cur][0] == 0)
                return INF;
            else
                return dp[cur][bit] = dist[cur][0];
        }

        if (dp[cur][bit] != -1)
            return dp[cur][bit];

        dp[cur][bit] = INF;

        for (int i = 0; i < N; i++) {
            if (dist[cur][i] == 0)
                continue;
            if ((bit & (1 << i)) != 0)
                continue;

            dp[cur][bit] = Math.min(dp[cur][bit], dfs(i, bit | (1 << i)) + dist[cur][i]);
        }

        return dp[cur][bit];
    }
}

// https://www.acmicpc.net/board/view/119776