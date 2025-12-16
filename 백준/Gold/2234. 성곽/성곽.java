import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static int[] dx = { 0, -1, 0, 1 };
    static int[] dy = { -1, 0, 1, 0 };
    static int[][] castle;
    static int[][] visited;
    static List<Integer> sizeList = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        castle = new int[N][M];
        visited = new int[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                castle[i][j] = Integer.parseInt(st.nextToken());
                visited[i][j] = -1;
            }
        }

        int num = 0;
        int maxSize = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (visited[i][j] == -1) {
                    int size = calcRoom(num++, i, j);
                    sizeList.add(size);
                    maxSize = Integer.max(maxSize, size);
                }
            }
        }

        System.out.println(num);
        System.out.println(maxSize);
        System.out.println(calcSumMaxSize());

    }

    static int calcRoom(int num, int x, int y) {
        Queue<int[]> que = new LinkedList<>();
        que.offer(new int[] { x, y });
        visited[x][y] = num;
        int size = 1;

        while (!que.isEmpty()) {
            int[] cur = que.poll();
            int cx = cur[0];
            int cy = cur[1];
            List<Integer> directions = getDirections(castle[cx][cy]);
            for (int i = 0; i < directions.size(); i++) {
                int nx = cx + dx[directions.get(i)];
                int ny = cy + dy[directions.get(i)];
                if (visited[nx][ny] != -1)
                    continue;
                visited[nx][ny] = num;
                que.offer(new int[] { nx, ny });
                size++;
            }
        }
        return size;
    }

    static List<Integer> getDirections(int num) {
        List<Integer> directions = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            if ((num & 1) == 0) {
                directions.add(i);
            }
            num = num >> 1;
        }
        return directions;
    }

    static int calcSumMaxSize() {
        int sumMaxSize = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                        continue;
                    if (visited[nx][ny] == visited[i][j])
                        continue;
                    sumMaxSize = Integer.max(sumMaxSize, sizeList.get(visited[nx][ny]) + sizeList.get(visited[i][j]));
                }
            }
        }
        return sumMaxSize;
    }
}
