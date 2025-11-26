import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            int N = Integer.parseInt(br.readLine());
            int[] group = new int[200001];
            int[] groupSize = new int[200001];

            for (int i = 0; i < 200001; i++) {
                group[i] = i;
                groupSize[i] = 1;
            }

            int number = 0;
            Map<String, Integer> nameNo = new HashMap<String, Integer>();
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                String a = st.nextToken();
                String b = st.nextToken();
                if (!nameNo.containsKey(a)) {
                    nameNo.put(a, number);
                    number++;
                }
                if (!nameNo.containsKey(b)) {
                    nameNo.put(b, number);
                    number++;
                }
                int aNum = nameNo.get(a);
                int bNum = nameNo.get(b);
                union(aNum, bNum, group, groupSize);

                System.out.println(groupSize[findGroup(aNum, group)]);

            }
        }

    }

    public static int findGroup(int a, int[] group) {
        if (group[a] == a)
            return a;
        else
            return group[a] = findGroup(group[a], group);
    }

    public static void union(int a, int b, int[] group, int[] groupSize) {
        int aGroup = findGroup(a, group);
        int bGroup = findGroup(b, group);

        if (aGroup == bGroup)
            return;

        if (aGroup < bGroup) {
            group[bGroup] = aGroup;
            groupSize[aGroup] += groupSize[bGroup];
        } else if (aGroup > bGroup) {
            group[aGroup] = bGroup;
            groupSize[bGroup] += groupSize[aGroup];
        }
    }
}
