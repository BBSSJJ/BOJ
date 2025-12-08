import java.util.*;
import java.io.*;

public class Main {
    static int N, L, R, X;
    static int[] A;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());
        A = new int[N];
        int answer = 0;

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        for (int bitmask = 1; bitmask < (1 << N); bitmask++) {
            int sum = 0;
            int easiest = Integer.MAX_VALUE;
            int hardest = 0;

            for (int i = 0; i < N; i++) {
                if ((bitmask & (1 << i)) != 0) {
                    sum += A[i];
                    easiest = Math.min(easiest, A[i]);
                    hardest = Math.max(hardest, A[i]);
                }
            }
            if (L <= sum && sum <= R && X <= (hardest - easiest)) {
                answer += 1;
            }
        }
        System.out.println(answer);
    }
}
