import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static int sx = 500;
    static int sy = 500;
    static List<int[]> squares;
    static int[][] board = new int[1001][1001];
    static int[] parent;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        squares = new ArrayList<int[]>();
        squares.add(new int[] { -1, -1, -1, -1 });
        parent = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            squares.add(new int[] { x1 + 500, y1 + 500, x2 + 500, y2 + 500 });

            parent[i] = i;
        }

        for (int i = 1; i <= N; i++) {
            int[] square = squares.get(i);
            for (int x = square[0]; x <= square[2]; x++) {
                if (board[x][square[1]] != 0) {
                    union(i, board[x][square[1]]);
                } else {
                    board[x][square[1]] = i;
                }
                if (board[x][square[3]] != 0) {
                    union(i, board[x][square[3]]);
                } else {
                    board[x][square[3]] = i;
                }
            }
            for (int y = square[1]; y <= square[3]; y++) {
                if (board[square[0]][y] != 0) {
                    union(i, board[square[0]][y]);
                } else {
                    board[square[0]][y] = i;
                }
                if (board[square[2]][y] != 0) {
                    union(i, board[square[2]][y]);
                } else {
                    board[square[2]][y] = i;
                }
            }
        }

        Set<Integer> groups = new HashSet<Integer>();
        for (int i = 1; i <= N; i++) {
            groups.add(findParent(i));
        }
        int answer = groups.size();
        if (board[500][500] != 0)
            answer -= 1;
        System.out.println(answer);
    }

    public static int findParent(int a) {
        if (parent[a] == a)
            return a;
        else
            return parent[a] = findParent(parent[a]);
    }

    public static void union(int a, int b) {
        int aParent = findParent(a);
        int bParent = findParent(b);
        if (aParent < bParent)
            parent[bParent] = aParent;
        if (aParent > bParent)
            parent[aParent] = bParent;
    }
}
