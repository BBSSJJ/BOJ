import java.util.*;
import java.io.*;

public class Main {
    static int T, N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            N = Integer.parseInt(br.readLine());

            int[] sum = new int[N + 1];
            int[][] dp = new int[N + 1][N + 1];

            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= N; i++) {
                int file = Integer.parseInt(st.nextToken());
                sum[i] = sum[i - 1] + file; // 누적합
            }

            // DP테이블 만들기
            for (int i = 1; i <= N; i++) { // 1부터 n까지 DP테이블 만들기
                for (int from = 1; from + i <= N; from++) { // from-to 묶음별 최댓값 구하기
                    int to = from + i;
                    dp[from][to] = Integer.MAX_VALUE;
                    for (int mid = from; mid < to; mid++) { // from-mid , mid+1-to 두개 묶음으로 최댓값 구하기
                        dp[from][to] = Math.min(dp[from][to],
                                dp[from][mid] + dp[mid + 1][to] + sum[to] - sum[from - 1]);
                    }
                }
            }
            System.out.println(dp[1][N]);
        }
    }
}
