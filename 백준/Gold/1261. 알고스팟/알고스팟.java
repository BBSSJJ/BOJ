import java.util.*;
import java.io.*;

public class Main {

    static int N, M;
    static int[][] board;
    static int[] dx = { 1, 0, -1, 0 };
    static int[] dy = { 0, 1, 0, -1 };

    static class Node implements Comparable<Node> {
        int count;
        int x;
        int y;

        public Node(int count, int x, int y) {
            this.count = count;
            this.x = x;
            this.y = y;
        }

        public int compareTo(Node n) {
            return this.count - n.count;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        board = new int[N][M];
        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            for (int j = 0; j < M; j++) {
                board[i][j] = str.charAt(j) - '0';
            }
        }

        System.out.println(dijkstra());

    }

    public static int dijkstra() {
        int[][] visited = new int[N][M];
        for (int i = 0; i < N; i++) {
            Arrays.fill(visited[i], Integer.MAX_VALUE);
        }
        visited[0][0] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(0, 0, 0));

        while (!pq.isEmpty()) {
            Node cur = pq.poll();

            if (cur.count > visited[cur.x][cur.y])
                continue;

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                int nCount = 0;
                if (outOfBound(nx, ny))
                    continue;
                if (board[nx][ny] == 1)
                    nCount += 1;
                if (visited[nx][ny] <= cur.count + nCount)
                    continue;
                visited[nx][ny] = cur.count + nCount;
                pq.offer(new Node(visited[nx][ny], nx, ny));
            }
        }
        return visited[N - 1][M - 1];
    }

    public static boolean outOfBound(int x, int y) {
        return x < 0 || y < 0 || x >= N || y >= M;
    }
}