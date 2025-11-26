import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long N = Long.parseLong(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());

        for (int q = 0; q < Q; q++) {
            st = new StringTokenizer(br.readLine());
            long a = Long.parseLong(st.nextToken()) - 1;
            long b = Long.parseLong(st.nextToken()) - 1;
            long answer = 0;

            if (K == 1) {
                answer = Math.abs(a - b);
                System.out.println(answer);
                continue;
            }

            while (true) {
                if (a > b) {
                    a = (a - 1) / K;
                    answer += 1;
                } else if (a < b) {
                    b = (b - 1) / K;
                    answer += 1;
                } else {
                    break;
                }
            }

            System.out.println(answer);
        }
    }
}
