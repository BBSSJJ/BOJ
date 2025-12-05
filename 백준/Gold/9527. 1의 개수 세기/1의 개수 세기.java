import java.util.*;
import java.io.*;

public class Main {

    static long[] dp = new long[56];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long A = Long.parseLong(st.nextToken());
        long B = Long.parseLong(st.nextToken());

        dp[1] = 1;
        for (int i = 2; i < 56; i++) {
            dp[i] = dp[i - 1] * 2 + (long) Math.pow(2, i - 1);
        }

        System.out.println(count(B) - count(A - 1));

    }

    public static long count(long num) {
        int pos = 55; // 자리 수
        long cnt = 0;
        while (num > 0) {
            if ((num & (1L << pos)) != 0) {
                cnt += dp[pos] + (num - (1L << pos)) + 1L;
                num ^= (1L << pos); // masking &=(1<<pos)-1;
            }
            pos--;
        }
        return cnt;
    }

}

// 참고: https://sogogi486.tistory.com/59
