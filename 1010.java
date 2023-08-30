import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static long[][] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int T = Integer.parseInt(st.nextToken());

		for (int t = 0; t < T; t++) {
			st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());

			if (M > N) {
				int tmp = M;
				M = N;
				N = tmp;
			}

			dp = new long[N + 1][M + 1];
			dp[0][0] = 1;
			for (int i = 1; i <= N; i++) {
				dp[i][0] = 1;
				for (int j = 1; j <= M; j++) {
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
				}
			}
			System.out.println(dp[N][M]);
		}

	}

}
