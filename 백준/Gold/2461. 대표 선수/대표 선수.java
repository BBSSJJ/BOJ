
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static int[][] group;
    static int[] pointer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        group = new int[N][M];
        pointer = new int[N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            pointer[i] = 0;
            for (int j = 0; j < M; j++) {
                group[i][j] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(group[i]);
        }
        
        int minGap = Integer.MAX_VALUE;

        while (true) {

            int minStat = Integer.MAX_VALUE;
            int maxStat = 0;
            int minStatGroup = 0;

            for (int i = 0; i < N; i++) {
                if (minStat > group[i][pointer[i]]) {
                    minStat = group[i][pointer[i]];
                    minStatGroup = i;
                }
                if (maxStat < group[i][pointer[i]]) {
                    maxStat = group[i][pointer[i]];
                }
            }
            int gap = maxStat - minStat;
            minGap = Integer.min(minGap, gap);


            if (pointer[minStatGroup] == M - 1) break;
            pointer[minStatGroup] += 1;
        }

        System.out.println(minGap);
    }
}
