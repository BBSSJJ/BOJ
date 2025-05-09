
import java.util.*;
import java.io.*;

public class Main {


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        ArrayList[] graph = new ArrayList[N + 1];
        int[] indegree = new int[N + 1];
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();


        for(int i = 1; i <= N; i++){
            graph[i] = new ArrayList<Integer>();
            indegree[i] = 0;
        }


        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            graph[u].add(v);
            indegree[v]++;
        }
        for(int i = 1; i <= N; i++){
            if(indegree[i] == 0) pq.add(i);
        }

        while(!pq.isEmpty()){
            int cur = pq.poll();
            sb.append(cur);
            sb.append(" ");
            for(int i = 0; i < graph[cur].size(); i++){
                int next = (int) graph[cur].get(i);
                if(--indegree[next] == 0) pq.add(next);
            }
        }


        System.out.print(sb.toString());
    }

}
