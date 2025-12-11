import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        char[][] board = new char[8][8];
        int visited[][] = new int[8][8];
        int[] dx = { 1, 0, -1, 0, 0, 1, 1, -1, -1 };
        int[] dy = { 0, 1, 0, -1, 0, 1, -1, 1, -1 };

        Queue<int[]> que = new LinkedList<>();
        que.add(new int[] { 7, 0, 0 });
        for (int i = 0; i < 8; i++) {
            String str = br.readLine();
            for (int j = 0; j < 8; j++) {
                board[i][j] = str.charAt(j);
                visited[i][j] = -1;
            }
        }

        for (int i = 7; i >= 0; i--) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == '#') {
                    que.add(new int[] { i, j, 1 });
                }
            }

        }

        visited[7][0] = 0;

        while (!que.isEmpty()) {
            int[] cur = que.poll();
            int type = cur[2];

            if (type == 0) {
                if (board[cur[0]][cur[1]] == '#')
                    continue;

                for (int i = 0; i < 9; i++) {
                    int nx = cur[0] + dx[i];
                    int ny = cur[1] + dy[i];
                    if (outOfBound(nx, ny))
                        continue;
                    if (visited[nx][ny] == visited[cur[0]][cur[1]] + 1)
                        continue;

                    if (board[nx][ny] == '#')
                        continue;

                    if (nx == 0 && ny == 7) {
                        System.out.println(1);
                        return;
                    }

                    visited[nx][ny] = visited[cur[0]][cur[1]] + 1;
                    que.add(new int[] { nx, ny, 0 });

                }
            } else {
                int nx = cur[0] + dx[0];
                int ny = cur[1] + dy[0];
                board[cur[0]][cur[1]] = '.';
                if (outOfBound(nx, ny))
                    continue;

                board[nx][ny] = '#';
                que.add(new int[] { nx, ny, 1 });
            }

        }

        System.out.println(0);

    }

    static boolean outOfBound(int x, int y) {
        return x < 0 || y < 0 || x >= 8 || y >= 8;
    }

}
