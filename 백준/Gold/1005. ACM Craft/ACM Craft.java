
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static int T, N, K, W;
    static int[] inDegree;
    static int[] waitTime;
    static boolean[] visited;
    static ArrayList<Integer>[] graph;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());
        for (int t = 0; t < T; t++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            inDegree = new int[N + 1];
            waitTime = new int[N + 1];
            graph = new ArrayList[N + 1];
            visited = new boolean[N + 1];

            for (int i = 1; i <= N; i++) {
                inDegree[i] = 0;
                graph[i] = new ArrayList<Integer>();
                visited[i] = false;
            }


            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= N; i++) {
                int n = Integer.parseInt(st.nextToken());
                waitTime[i] = n;
            }
            for (int i = 0; i < K; i++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                inDegree[v]++;
                graph[u].add(v);
            }

            st = new StringTokenizer(br.readLine());
            W = Integer.parseInt(st.nextToken());


            PriorityQueue<Node> pq = new PriorityQueue<>();
            for (int i = 1; i <= N; i++) {
                if (inDegree[i] == 0) {
                    pq.offer(new Node(waitTime[i], i));

                }
            }

            while (!pq.isEmpty()) {
                Node curNode = pq.poll();
                waitTime[curNode.num] = curNode.time;
                if (curNode.num == W) {
                    System.out.println(curNode.time);
                    break;
                }
                for (int i = 0; i < graph[curNode.num].size(); i++) {
                    int next = graph[curNode.num].get(i);
                    inDegree[next] -= 1;
                    if (inDegree[next] == 0) {
                        pq.offer(new Node(curNode.time + waitTime[next], next));
                    }
                }
            }
        }
    }

    static class Node implements Comparable<Node> {
        int time;
        int num;

        public Node(int time, int num) {
            this.time = time;
            this.num = num;
        }

        @Override
        public int compareTo(Node n) {
            return this.time - n.time;
        }
    }
}