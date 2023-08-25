import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());


        int[] belt = new int[N];
        int[] type = new int[d + 1];

        for (int i = 0; i < N; i++) {
            belt[i] = Integer.parseInt(br.readLine());
        }

        int start = 0;
        int end = k;

        int typeCount = 0;
        for (int i = 0; i < k; i++) {
            if (type[belt[i]] == 0) {
                typeCount++;
            }
            type[belt[i]]++;
        }
        if (type[c] == 0) {
            typeCount++;
        }
        type[c]++;

        int typeCountMax = typeCount;

        while (start <= N - 1) {
            type[belt[start]] -= 1;
            if (type[belt[start]] == 0) typeCount--;

            if (type[belt[end]] == 0) typeCount++;
            type[belt[end]] += 1;

            typeCountMax = Math.max(typeCountMax, typeCount);

            start++;
            if (end == N - 1) end = 0;
            else end++;

        }

        System.out.println(typeCountMax);

    }

}