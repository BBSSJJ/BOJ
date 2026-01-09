import java.io.*;
import java.util.*;

public class Main {
    static int N, L;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuffer sb = new StringBuffer();
        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());

        Deque<int[]> deq = new ArrayDeque<>();

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int num = Integer.parseInt(st.nextToken());
            while (!deq.isEmpty() && deq.peekLast()[0] > num) {
                deq.pollLast();
            }
            deq.add(new int[] { num, i });
            if (deq.peekFirst()[1] == i - L)
                deq.pollFirst();

            sb.append(deq.peekFirst()[0] + " ");
        }
        System.out.println(sb.toString());
    }
}
