import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static int[] inOrder;
    static int[] postOrder;
    static int[] inOrderIdx;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        inOrder = new int[N];
        inOrderIdx = new int[N + 1];
        postOrder = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            inOrder[i] = Integer.parseInt(st.nextToken());
            inOrderIdx[inOrder[i]] = i;
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            postOrder[i] = Integer.parseInt(st.nextToken());
        }

        dq(0, N - 1, 0, N - 1);

    }

    static void dq(int is, int ie, int ps, int pe) {
        if (is > ie || ps > pe)
            return;

        int root = postOrder[pe];
        int rootIdx = inOrderIdx[root];

        System.out.print(root + " ");

        int leftLen = rootIdx - is;

        dq(is, rootIdx - 1, ps, ps + leftLen - 1);
        dq(rootIdx + 1, ie, ps + leftLen, pe - 1);

    }
}
