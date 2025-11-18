// import java.util.*;
// import java.io.*;

// public class Main {

//     static int N, M;
//     static int sx, sy, ex, ey;
//     static char[][] board;
//     static int[][] distance;
//     static int[] dx = { -1, 0, 1, 0 };
//     static int[] dy = { 0, 1, 0, -1 };

//     public static void main(String[] args) throws IOException {
//         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//         StringTokenizer st = new StringTokenizer(br.readLine());

//         M = Integer.parseInt(st.nextToken());
//         N = Integer.parseInt(st.nextToken());

//         board = new char[N][M];
//         distance = new int[N][M];
//         sx = -1;

//         for (int i = 0; i < N; i++) {
//             String str = br.readLine();
//             for (int j = 0; j < M; j++) {
//                 board[i][j] = str.charAt(j);
//                 if (board[i][j] == 'C') {
//                     if (sx == -1) {
//                         sx = i;
//                         sy = j;
//                     } else {
//                         ex = i;
//                         ey = j;
//                     }
//                 }
//                 distance[i][j] = Integer.MAX_VALUE;
//             }
//         }

//         distance[sx][sy] = 0;
//         PriorityQueue<Point> pq = new PriorityQueue<>();
//         pq.add(new Point(sx, sy, -1, 0));

//         while (!pq.isEmpty()) {
//             Point cur = pq.poll();

//             if (distance[cur.x][cur.y] < cur.mCount)
//                 continue;

            
//             for (int i = 0; i < 4; i++) {
//                 int nx = cur.x + dx[i];
//                 int ny = cur.y + dy[i];
//                 int nDist = cur.mCount;
//                 if (i != cur.beforeDir)
//                     nDist++;
//                 if (outOfBound(nx, ny) || board[nx][ny] == '*')
//                     continue;
//                 if (distance[nx][ny] < nDist)
//                     continue;
//                 distance[nx][ny] = nDist;
//                 pq.offer(new Point(nx, ny, i, nDist));
//             }
//         }

//         System.out.println(distance[ex][ey] - 1);
//     }

//     public static boolean outOfBound(int x, int y) {
//         return (x < 0 || y < 0 || x >= N || y >= M);
//     }

//     public static class Point implements Comparable<Point> {
//         int x;
//         int y;
//         int beforeDir;
//         int mCount;

//         public Point(int x, int y, int beforeDir, int mCount) {
//             this.x = x;
//             this.y = y;
//             this.beforeDir = beforeDir;
//             this.mCount = mCount;
//         }
        
//         @Override
//         public int compareTo(Point p) {
//             return this.mCount - p.mCount;
//         }
//     }
// }


import java.util.*;
import java.io.*;

public class Main {

    static int N, M;
    static int sx, sy, ex, ey;
    static char[][] board;
    static int[][][] distance;
    static int[] dx = { -1, 0, 1, 0 };
    static int[] dy = { 0, 1, 0, -1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        board = new char[N][M];
        distance = new int[N][M][4];
        sx = -1;

        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            for (int j = 0; j < M; j++) {
                board[i][j] = str.charAt(j);
                if (board[i][j] == 'C') {
                    if (sx == -1) {
                        sx = i;
                        sy = j;
                    } else {
                        ex = i;
                        ey = j;
                    }
                }
                for(int d = 0; d < 4; d++){
                    distance[i][j][d] = Integer.MAX_VALUE;
                }
                
            }
        }

        distance[sx][sy][0] = 0;
        distance[sx][sy][1] = 0;
        distance[sx][sy][2] = 0;
        distance[sx][sy][3] = 0;

        PriorityQueue<Point> pq = new PriorityQueue<>();
        pq.add(new Point(sx, sy, 0, 0));
        pq.add(new Point(sx, sy, 1, 0));
        pq.add(new Point(sx, sy, 2, 0));
        pq.add(new Point(sx, sy, 3, 0));

        while (!pq.isEmpty()) {
            Point cur = pq.poll();

            if (distance[cur.x][cur.y][cur.beforeDir] < cur.mCount)
                continue;

            
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                int nDist = cur.mCount;
                if (i != cur.beforeDir)
                    nDist++;
                if (outOfBound(nx, ny) || board[nx][ny] == '*')
                    continue;
                if (distance[nx][ny][i] <= nDist)
                    continue;
                distance[nx][ny][i] = nDist;
                pq.offer(new Point(nx, ny, i, nDist));
            }
        }

        int answer = Integer.MAX_VALUE;
        for(int i = 0; i < 4; i++){
            answer = Math.min(answer, distance[ex][ey][i]);
        }
        System.out.println(answer);
    }

    public static boolean outOfBound(int x, int y) {
        return (x < 0 || y < 0 || x >= N || y >= M);
    }

    public static class Point implements Comparable<Point> {
        int x;
        int y;
        int beforeDir;
        int mCount;

        public Point(int x, int y, int beforeDir, int mCount) {
            this.x = x;
            this.y = y;
            this.beforeDir = beforeDir;
            this.mCount = mCount;
        }
        
        @Override
        public int compareTo(Point p) {
            return this.mCount - p.mCount;
        }
    }
}
