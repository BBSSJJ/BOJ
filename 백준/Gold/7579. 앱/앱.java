import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] memories = new int[N];
        int[] costs = new int[N];
        int[] dp = new int[10001];
        for (int i = 0; i <= 10000; i++) {
            dp[i] = 0;
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            memories[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            costs[i] = Integer.parseInt(st.nextToken());
        }
        int answer = Integer.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            // 정방향으로 올라가면 중복사용 가능해진다
            // for (int j = costs[i]; j <= 10000; j++) {
            //     dp[j] = Math.max(dp[j], dp[j - costs[i]] + memories[i]);
            //     if (dp[j] >= M)
            //         answer = Math.min(answer, j);
            // }
            for (int j = 10000; j >= costs[i]; j--) {
                dp[j] = Math.max(dp[j], dp[j - costs[i]] + memories[i]);
                if(dp[j] >= M)
                    answer = Math.min(answer, j);
            }
        }
        System.out.println(answer);


    }
}
