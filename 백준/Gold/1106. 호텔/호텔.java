import java.io.*;
import java.util.*;

public class Main {
    static int C, N;
    static int costs[], people[];
    static int dp[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        C = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        costs = new int[N + 1];
        people = new int[N + 1];
        dp = new int[100001];

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            costs[i] = Integer.parseInt(st.nextToken());
            people[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i <= N; i++) {
            for (int j = costs[i]; j < dp.length; j++) {
                dp[j] = Integer.max(dp[j], dp[j - costs[i]] + people[i]);
            }
        }
        int answer = 0;

        for (int i = 1; i < dp.length; i++) {
            if (dp[i] >= C) {
                answer = i;
                break;
            }
        }
        System.out.println(answer);
    }
}