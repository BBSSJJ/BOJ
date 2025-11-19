import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String number = st.nextToken();
        int N = number.length();
        int K = Integer.parseInt(st.nextToken());

        Set<String> visited;
        Queue<String> que = new LinkedList<>();

        if (N == 1) {
            System.out.println(-1);
            return;
        }

        que.offer(number);
        int answer = -1;

        for (int k = 0; k < K; k++) {
            visited = new HashSet();
            int qSize = que.size();

            for (int q = 0; q < qSize; q++) {
                String cur = que.poll();

                for (int i = 0; i < N; i++) {
                    for (int j = i + 1; j < N; j++) {
                        if (i == 0 && cur.charAt(j) == '0')
                            continue;
                        String next = swap(cur, i, j);
                        if (visited.contains(next))
                            continue;
                        visited.add(next);
                        que.add(next);

                        if (k == K - 1) {
                            answer = Math.max(answer, Integer.parseInt(next));
                        }
                    }
                }
            }
        }
        
        System.out.println(answer);

    }
    
    public static String swap(String num, int a, int b) {
        char[] after = num.toCharArray();
        char tmp = after[a];
        after[a] = after[b];
        after[b] = tmp;
        return new String(after);
    }
}
