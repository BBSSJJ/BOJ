import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static Point[] points = new Point[4];
    static int[] dx = { 1, 0, -1, 0 };
    static int[] dy = { 0, 1, 0, -1 };

    public static boolean outOfBound(int x, int y) {
        return x < 0 || y < 0 || x >= N || y >= M;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken()) + 1;
        M = Integer.parseInt(st.nextToken()) + 1;
        // N+1, M+1

        for (int i = 0; i < 4; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            points[i] = new Point(x, y);
        }

        int answer = Integer.MAX_VALUE;
        int first, second;
        List<Point> used = new ArrayList<>();
        first = bfs(points[0], points[1], points[2], points[3], used);
        second = bfs(points[2], points[3], points[0], points[1], used);

        if (first != -1 && second != -1)
            answer = first + second;

        used = new ArrayList<>();
        first = bfs(points[2], points[3], points[0], points[1], used);

        second = bfs(points[0], points[1], points[2], points[3], used);

        if (first != -1 && second != -1)
            answer = Math.min(answer, first + second);

        if (answer == Integer.MAX_VALUE)
            System.out.println("IMPOSSIBLE");
        else {
            System.out.println(answer);
        }

    }

    static int bfs(Point start, Point end, Point no1, Point no2, List<Point> used) {
        int count = 1;
        Point[][] visited = new Point[N][M];
        if (used.size() != 0) {
            for (int i = 0; i < used.size(); i++) {
                visited[used.get(i).x][used.get(i).y] = new Point(-1, -1);
            }
        }

        Queue<Point> que = new LinkedList<>();
        que.add(new Point(start.x, start.y));
        visited[start.x][start.y] = new Point(start.x, start.y);

        boolean finished = false;

        while (!que.isEmpty()) {
            Point cur = que.poll();

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (outOfBound(nx, ny) || visited[nx][ny] != null)
                    continue;
                if ((nx == no1.x && ny == no1.y) || (nx == no2.x && ny == no2.y))
                    continue;
                visited[nx][ny] = cur;
                que.offer(new Point(nx, ny));
                if (nx == end.x && ny == end.y) {
                    finished = true;
                    break;
                }
            }
            if (finished)
                break;
        }

        if (visited[end.x][end.y] == null)
            return -1;

        Point cur = visited[end.x][end.y];
        boolean flag = false;
        if (used.size() == 0) {
            used.add(end);
            used.add(start);
            flag = true;
        }

        while (!(cur.x == start.x && cur.y == start.y)) {
            if (flag) {
                used.add(cur);
            }
            count += 1;

            cur = visited[cur.x][cur.y];
        }

        return count;
    }

    static class Point {
        int x;
        int y;

        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

}
