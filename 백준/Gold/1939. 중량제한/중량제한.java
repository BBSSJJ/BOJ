import java.util.*;
import java.io.*;

public class Main {

    static class Point {
        int num;
        int weight;

        public Point(int num, int weight) {
            this.num = num;
            this.weight = weight;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<int[]>());
        }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            graph.get(u).add(new int[] { v, w });
            graph.get(v).add(new int[] { u, w });
        }
        st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());

        int[] visited = new int[N + 1];
        Arrays.fill(visited, 0);
        visited[start] = Integer.MAX_VALUE;

        PriorityQueue<Point> pq = new PriorityQueue<>(new Comparator<Point>() {
            @Override
            public int compare(Point p1, Point p2) {
                return p2.weight - p1.weight;
            }
        });

        pq.add(new Point(start, Integer.MAX_VALUE));
        while (!pq.isEmpty()) {
            Point cur = pq.poll();

            if (visited[cur.num] > cur.weight)
                continue;

            for (int i = 0; i < graph.get(cur.num).size(); i++) {
                int[] next = graph.get(cur.num).get(i);
                int nextWeight = Math.min(next[1], visited[cur.num]);
                if (nextWeight > visited[next[0]]) {
                    visited[next[0]] = nextWeight;
                    pq.add(new Point(next[0], visited[next[0]]));
                }
            }
        }
        System.out.println(visited[end]);

    }
}
