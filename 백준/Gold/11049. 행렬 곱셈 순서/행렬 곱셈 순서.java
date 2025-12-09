import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int[][] matrix = new int[N][2];
        int dp[][] = new int[N][N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            matrix[i][0] = Integer.parseInt(st.nextToken());
            matrix[i][1] = Integer.parseInt(st.nextToken());
        }

        for (int gap = 1; gap <= N; gap++) {
            for (int i = 0; i + gap < N; i++) {
                dp[i][i + gap] = Integer.MAX_VALUE;

                for (int j = i; j < i + gap; j++) {
                    dp[i][i + gap] = Math.min(dp[i][i + gap],
                            dp[i][j] + dp[j + 1][i + gap] + matrix[i][0] * matrix[j][1] * matrix[i + gap][1]);
                }
            }
        }
        System.out.println(dp[0][N - 1]);
    }
}
