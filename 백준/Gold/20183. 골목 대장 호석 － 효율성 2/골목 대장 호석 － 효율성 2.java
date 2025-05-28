
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static int N, M, A, B;
    static long C;
    static List<List<Edge>> graph;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;


        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());   //교차로 개수
        M = Integer.parseInt(st.nextToken());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        C = Long.parseLong(st.nextToken());

        graph = new ArrayList<>();
        for (int i = 0; i < N + 1; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int dist = Integer.parseInt(st.nextToken());
            graph.get(u).add(new Edge(v, dist));
            graph.get(v).add(new Edge(u, dist));
        }

        int start = 1;
        int end = 1000000000;
        int ans = 1000000000;
        while (start < end) {
            int mid = (start + end) / 2;
            boolean success = dijkstra(mid);
            if (success) {
                end = mid;
//                ans = mid;
//                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
//        System.out.println(ans);
        System.out.println(start);
    }

    static boolean dijkstra(int target) {
        boolean[] visited = new boolean[N + 1];
        long[] dist = new long[N + 1];
        PriorityQueue<Edge> pq = new PriorityQueue<>();

        for (int i = 1; i <= N; i++) {
            dist[i] = Long.MAX_VALUE;
        }

        visited[A] = true;
        dist[A] = 0;
        pq.add(new Edge(A, 0));

        while (!pq.isEmpty()) {
            Edge e = pq.poll();
            int cur = e.no;
            long cDist = e.dist;
            if (cDist > dist[cur]) continue;

            for (Edge tmp : graph.get(cur)) {
                int next = tmp.no;
                long nDist = tmp.dist;
                if (nDist > target) continue;
                if (dist[next] <= dist[cur] + nDist) continue;
                dist[next] = dist[cur] + nDist;
                pq.add(new Edge(next, dist[next]));
            }
        }
        if (dist[B] > C) return false;
        else return true;
    }

    static class Edge implements Comparable<Edge> {
        int no;
        long dist;

        public Edge(int no, long dist) {
            this.no = no;
            this.dist = dist;
        }

        public int compareTo(Edge o) {
            return Long.compare(this.dist, o.dist);
        }
    }
}