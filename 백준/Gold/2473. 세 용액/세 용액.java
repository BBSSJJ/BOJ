import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static List<Integer> numbers = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            numbers.add(Integer.parseInt(st.nextToken()));
        }

        numbers.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return a - b;
            }
        });

        long answer = Long.MAX_VALUE;
        int a = 0;
        int b = 0;
        int c = 0;
        for (int i = 0; i <= N - 3; i++) {
            int fixed = i;
            int start = i + 1;
            int end = N - 1;

            while (start < end) {
                long result = (long) numbers.get(fixed) + numbers.get(start) + numbers.get(end);
                if (answer > Math.abs(result)) {
                    answer = Math.abs(result);
                    a = fixed;
                    b = start;
                    c = end;
                }
                if (result > 0) {
                    end--;
                } else if (result == 0) {
                    break;
                } else {
                    start++;
                }
            }
        }
        System.out.println(numbers.get(a) + " " + numbers.get(b) + " " + numbers.get(c));

    }
}
