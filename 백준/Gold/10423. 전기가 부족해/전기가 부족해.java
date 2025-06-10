import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, M, K, u, v, w;
    static List<int[]>[] graph;
    static boolean[] visited;
    static int[] parent;
    static Set<Integer> hasElectric = new HashSet<Integer>();
    static List<Integer> starts = new ArrayList<Integer>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        graph = new ArrayList[N + 1];
        visited = new boolean[N + 1];
        parent = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<int[]>();
            visited[i] = false;
            parent[i] = i;
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < K; i++) {
            u = Integer.parseInt(st.nextToken());
            hasElectric.add(u);
            starts.add(u);
        }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());
            graph[u].add(new int[]{v, w});
            graph[v].add(new int[]{u, w});
        }

        PriorityQueue<Edge> pq = new PriorityQueue<>();

        for (int i = 0; i < K; i++) {
            int start = starts.get(i);
            visited[start] = true;
            for (int j = 0; j < graph[start].size(); j++) {
                pq.offer(new Edge(start, graph[start].get(j)[0], graph[start].get(j)[1]));
            }
        }

        int answer = 0;
        while (!pq.isEmpty()) {
            Edge e = pq.poll();
            int from = e.from;
            int to = e.to;
            int weight = e.weight;
            if (visited[to]) continue;
            if (!union(from, to)) continue;
//            System.out.println("select " + to);
            visited[to] = true;
            answer += e.weight;
            for (int i = 0; i < graph[to].size(); i++) {
                if (visited[graph[to].get(i)[0]]) continue;
                pq.offer(new Edge(to, graph[to].get(i)[0], graph[to].get(i)[1]));
            }
        }

        System.out.println(answer);
    }


    //u, v 순서 항상 주의, 앞쪽이 발전기 있는 도시여야 함
    static boolean union(int u, int v) {

        int uParent = findParent(u);
        int vParent = findParent(v);

//        System.out.println("ancestor of " + u + " is " + uParent);
//        System.out.println("ancestor of " + v + " is " + vParent);

        if (uParent == vParent) return false;
        if (hasElectric.contains(vParent)) return false;

        parent[v] = uParent;
        return true;
    }

    static int findParent(int u) {
        if (u != parent[u]) {
            return parent[u] = findParent(parent[u]);
        } else {
            return u;
        }
    }


    static class Edge implements Comparable<Edge> {
        int from;
        int to;
        int weight;

        public Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }

        public int compareTo(Edge o) {
            return this.weight - o.weight;
        }
    }
}