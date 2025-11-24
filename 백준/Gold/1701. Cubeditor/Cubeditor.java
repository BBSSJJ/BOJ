import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int N = str.length();
        int result = 0;

        for (int i = 0; i < N; i++) {
            String cur = str.substring(i);
            int len = cur.length();

            int[] pi = new int[len];

            int idx = 0;

            for (int j = 1; j < len; j++) {
                while (idx > 0 && cur.charAt(j) != cur.charAt(idx)) {
                    idx = pi[idx - 1];
                }
                if (cur.charAt(j) == cur.charAt(idx)) {
                    idx += 1;
                    pi[j] = idx;
                    result = Math.max(result, idx);
                }
            }
        }
        System.out.println(result);
    }
}
