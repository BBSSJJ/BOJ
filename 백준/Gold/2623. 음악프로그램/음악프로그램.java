import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static int[] indegree;
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static ArrayList<Integer> result = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        indegree = new int[N + 1];
        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int count = Integer.parseInt(st.nextToken());
            int u = Integer.parseInt(st.nextToken());
            int v;
            for (int j = 0; j < count - 1; j++) {
                v = Integer.parseInt(st.nextToken());
                graph.get(u).add(v);
                indegree[v]++;
                u = v;
            }
        }

        topologicalSort();

        if (result.size() != N) {
            System.out.println(0);
        } else {
            for (int i = 0; i < result.size(); i++) {
                System.out.println(result.get(i));
            }
        }

    }

    public static void topologicalSort() {
        Queue<Integer> que = new LinkedList<>();
        for (int i = 1; i <= N; i++) {
            if (indegree[i] == 0) {
                que.offer(i);
            }
        }

        while (!que.isEmpty()) {
            int cur = que.poll();
            result.add(cur);
            for (int i = 0; i < graph.get(cur).size(); i++) {
                int next = graph.get(cur).get(i);
                indegree[next] -= 1;
                if (indegree[next] == 0) {
                    que.offer(next);
                }
            }
        }

    }
}