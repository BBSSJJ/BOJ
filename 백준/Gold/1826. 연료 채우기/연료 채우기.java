import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        List<Village> villages = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            villages.add(new Village(a, b));
        }
        st = new StringTokenizer(br.readLine());
        int L = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());

        villages.sort(new Comparator<Village>() {
            @Override
            public int compare(Village v1, Village v2) {
                return v1.distance - v2.distance;
            }
        });

        PriorityQueue<Village> pq = new PriorityQueue<>();

        int gas = P;
        int destination = L;
        int idx = 0;
        int answer = 0;

        while (gas < destination) {
            while (idx < N && villages.get(idx).distance <= gas) {
                pq.offer(villages.get(idx));
                idx += 1;
            }
            if (pq.isEmpty())
                break;

            Village selected = pq.poll();
            answer += 1;
            gas += selected.gas;

        }

        if (gas < destination) {
            answer = -1;
        }
        System.out.println(answer);

    }

    static class Village implements Comparable<Village> {
        int distance;
        int gas;

        public Village(int distance, int gas) {
            this.distance = distance;
            this.gas = gas;
        }

        public int compareTo(Village v) {
            return v.gas - this.gas;
        }
    }
}
