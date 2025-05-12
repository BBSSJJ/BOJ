
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;

//heap을 2개 써서, 하나는 중간값보다 작은 것들, 하나는 중간 값보다 큰 것들
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        int mid = Integer.parseInt(br.readLine());
        sb.append(mid);
        sb.append("\n");

        PriorityQueue<Integer> small = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> big = new PriorityQueue<>();

        for (int i = 1; i < N; i++) {
            int n = Integer.parseInt(br.readLine());
            if (n < mid) small.add(n);
            else big.add(n);

            if(big.size() > small.size() + 1){
                small.add(mid);
                mid = big.poll();
            } else if(big.size() < small.size()){
                big.add(mid);
                mid = small.poll();
            }

            sb.append(mid);
            sb.append("\n");
        }

        System.out.println(sb);
    }
}