// import java.io.*;
// import java.util.*;

// public class Main {
//     public static void main(String[] args) throws IOException {
//         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//         StringTokenizer st;

//         int T = Integer.parseInt(br.readLine());

//         for (int k = 0; k < T; k++) {
//             st = new StringTokenizer(br.readLine());
//             int n = Integer.parseInt(st.nextToken()); // 교차로 개수
//             int m = Integer.parseInt(st.nextToken()); // 도로 개수
//             int t = Integer.parseInt(st.nextToken()); // 목적지 개수
//             st = new StringTokenizer(br.readLine());
//             int s = Integer.parseInt(st.nextToken()); // 출발지
//             int g = Integer.parseInt(st.nextToken());
//             int h = Integer.parseInt(st.nextToken());

//             ArrayList<ArrayList<int[]>> graph = new ArrayList<ArrayList<int[]>>();

//             for (int i = 0; i <= n; i++) {
//                 graph.add(new ArrayList<>());
//             }

//             for (int i = 0; i < m; i++) {
//                 st = new StringTokenizer(br.readLine());
//                 int u = Integer.parseInt(st.nextToken());
//                 int v = Integer.parseInt(st.nextToken());
//                 int w = Integer.parseInt(st.nextToken());
//                 graph.get(u).add(new int[] { v, w });
//                 graph.get(v).add(new int[] { u, w });
//             }

//             int[] targets = new int[t];
//             for (int i = 0; i < t; i++) {
//                 int u = Integer.parseInt(br.readLine());
//                 targets[i] = u;
//             }
//             Arrays.sort(targets);

//             int[][] distance = new int[n + 1][2];
//             for (int i = 0; i <= n; i++) {
//                 distance[i][0] = 100_000_000;
//                 distance[i][1] = 0;
//             }
//             distance[s][0] = 0;
//             distance[s][1] = s;

//             PriorityQueue<Move> pq = new PriorityQueue<Move>();
//             pq.offer(new Move(0, s, s));

//             while (!pq.isEmpty()) {
//                 Move cur = pq.poll();

//                 if (cur.dist > distance[cur.to][0])
//                     continue;

//                 distance[cur.to][1] = cur.from;

//                 for (int i = 0; i < graph.get(cur.to).size(); i++) {
//                     int next = graph.get(cur.to).get(i)[0];
//                     int nDist = graph.get(cur.to).get(i)[1];

//                     if (distance[next][0] <= cur.dist + nDist)
//                         continue;

//                     distance[next][0] = cur.dist + nDist;
//                     pq.offer(new Move(distance[next][0], cur.to, next));
//                 }
//             }

//             for (int i = 0; i < t; i++) {
//                 int cur = targets[i];
//                 int before = distance[cur][1];
//                 while (cur != before) {
//                     if ((cur == g && before == h) || (cur == h && before == g)) {
//                         System.out.print(targets[i] + " ");
//                         break;
//                     }
//                     cur = before;
//                     before = distance[cur][1];
//                 }
//             }
//             System.out.println();

//         }

//     }
    
//     public static class Move implements Comparable<Move> {
//         int dist;
//         int from;
//         int to;

//         public Move(int dist, int from, int to) {
//             this.dist = dist;
//             this.from = from;
//             this.to = to;
//         }

//         public int compareTo(Move m) {
//             return this.dist - m.dist;
//         }

//     }
// }
// 이렇게 하면, 최단경로가 여러개일 때 문제가 생긴다...이런



import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        for (int k = 0; k < T; k++) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken()); // 교차로 개수
            int m = Integer.parseInt(st.nextToken()); // 도로 개수
            int t = Integer.parseInt(st.nextToken()); // 목적지 개수
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken()); // 출발지
            int g = Integer.parseInt(st.nextToken());
            int h = Integer.parseInt(st.nextToken());

            ArrayList<ArrayList<int[]>> graph = new ArrayList<ArrayList<int[]>>();

            for (int i = 0; i <= n; i++) {
                graph.add(new ArrayList<>());
            }

            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                int w = Integer.parseInt(st.nextToken());
                graph.get(u).add(new int[] { v, w });
                graph.get(v).add(new int[] { u, w });
            }

            int[] targets = new int[t];
            for (int i = 0; i < t; i++) {
                int u = Integer.parseInt(br.readLine());
                targets[i] = u;
            }
            Arrays.sort(targets);

            int[][] distance = new int[3][n + 1];
            dijkstra(0, graph, distance, g, n); // g에서 출발
            dijkstra(1, graph, distance, h, n); // h에서 출발
            dijkstra(2, graph, distance, s, n); // s에서 출발

            int ghDist = distance[0][h];
            for (int i = 0; i < t; i++) {
                int target = targets[i];
                if ((distance[0][s] + distance[1][target] + ghDist == distance[2][target]) ||
                        (distance[1][s] + distance[0][target] + ghDist == distance[2][target])) {
                    System.out.print(target + " ");
                }
            }
            System.out.println();
            

        }

    }
    
    public static void dijkstra(int type, ArrayList<ArrayList<int[]>> graph, int[][] distance, int s, int n) {
            for (int i = 0; i <= n; i++) {
                distance[type][i] = Integer.MAX_VALUE;
            }
            distance[type][s] = 0;

            PriorityQueue<Move> pq = new PriorityQueue<Move>();
            pq.offer(new Move(0, s));

            while (!pq.isEmpty()) {
                Move cur = pq.poll();

                if (cur.dist > distance[type][cur.to])
                    continue;

                for (int i = 0; i < graph.get(cur.to).size(); i++) {
                    int next = graph.get(cur.to).get(i)[0];
                    int nDist = graph.get(cur.to).get(i)[1];

                    if (distance[type][next] <= cur.dist + nDist)
                        continue;

                    distance[type][next] = cur.dist + nDist;
                    pq.offer(new Move(distance[type][next], next));
                }
            }
    }
    
    public static class Move implements Comparable<Move> {
        int dist;
        int to;

        public Move(int dist, int to) {
            this.dist = dist;
            this.to = to;
        }

        public int compareTo(Move m) {
            return this.dist - m.dist;
        }

    }
}