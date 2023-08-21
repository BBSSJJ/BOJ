import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb;
        StringTokenizer st;


        int T = Integer.parseInt(br.readLine());

        for (int test = 1; test <= T; test++) {

            char[] order = br.readLine().toCharArray();

            int N = Integer.parseInt(br.readLine());
            Deque<Integer> dq = new ArrayDeque<>();

            String str = br.readLine();
            st = new StringTokenizer(str.substring(1, str.length() - 1), ",");

            int[] numbers = new int[N];
            for (int i = 0; i < N; i++) {
                dq.offerLast(Integer.parseInt(st.nextToken()));
            }

            int direction = 1;
            for (int i = 0; i < order.length; i++) {
                if (order[i] == 'R') {
                    direction = direction == 1 ? -1 : 1;
                } else if (order[i] == 'D') {
                    if (dq.isEmpty()) {
                        direction = 0;
                        break;
                    } else if (direction == 1) {
                        dq.pollFirst();
                    } else if (direction == -1) {
                        dq.pollLast();
                    }
                }
            }

            sb = new StringBuilder();

            if (direction == 0) {
                sb.append("error");
            } else if (dq.isEmpty()) {
                sb.append("[]");
            } else if (direction == 1) {
                sb.append("[");
                while (!dq.isEmpty()) {
                    if (dq.size() == 1) {
                        sb.append(dq.pollFirst()).append("]");
                        break;
                    }
                    sb.append(dq.pollFirst()).append(",");
                }

            } else if (direction == -1) {
                sb.append("[");
                while (!dq.isEmpty()) {
                    if (dq.size() == 1) {
                        sb.append(dq.pollLast()).append("]");
                        break;
                    }
                    sb.append(dq.pollLast()).append(",");
                }
            }
            System.out.println(sb);
        }
    }
}