import java.util.*;
import java.io.*;

public class Main {

    static int N, M, K;
    static List<List<Integer>> friends;
    static int[] candy;
    static boolean visited[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        friends = new ArrayList<>();
        friends.add(new ArrayList<>());
        candy = new int[N + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            candy[i] = Integer.parseInt(st.nextToken());
            friends.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            friends.get(u).add(v);
            friends.get(v).add(u);
        }

        visited = new boolean[N + 1];

        List<int[]> data = new ArrayList<>();

        for (int n = 1; n <= N; n++) {
            if (visited[n])
                continue;
            Queue<Integer> que = new LinkedList<>();
            visited[n] = true;
            que.add(n);
            int count = candy[n];
            int size = 1;
            while (!que.isEmpty()) {
                int cur = que.poll();
                for (int i = 0; i < friends.get(cur).size(); i++) {
                    int next = friends.get(cur).get(i);
                    if (visited[next])
                        continue;
                    visited[next] = true;
                    que.add(next);
                    count += candy[next];
                    size += 1;
                }
            }
            data.add(new int[] { count, size });
        }

        // dp

        int[] dp = new int[K];

        for (int i = 0; i < data.size(); i++) {
            int curSize = data.get(i)[1];
            for (int j = K - 1; j >= curSize; j--) {
                dp[j] = Math.max(dp[j], dp[j - curSize] + data.get(i)[0]);
            }
        }

        System.out.println(dp[K - 1]);

    }

}
