import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static ArrayList<ArrayList<Integer>> graph;
    static int N;
    static int[] population;
    static int totalPopulation;
    static boolean selected[];
    static int parent[];
    static int gap = -1;

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        population = new int[N + 1];
        totalPopulation = 0;
        selected = new boolean[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            population[i] = Integer.parseInt(st.nextToken());
            totalPopulation += population[i];
        }

        graph = new ArrayList<ArrayList<Integer>>();

        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            int near = Integer.parseInt(st.nextToken());
            for (int j = 0; j < near; j++) {
                int next = Integer.parseInt(st.nextToken());
                graph.get(i).add(next);
            }
        }

        subSet(1);

        System.out.println(gap);

    }

    static void subSet(int idx) {
        if (idx == N + 1) {

            ArrayList<Integer> group1 = new ArrayList<>();
            ArrayList<Integer> group2 = new ArrayList<>();
            for (int i = 1; i <= N; i++) {
                if (selected[i])
                    group1.add(i);
                else
                    group2.add(i);
            }

            if (group1.isEmpty() || group2.isEmpty())
                return;

            if(isLinked(group1) && isLinked(group2)){
                int sum1 = 0;
                int sum2 = 0;
                for (int i = 1; i <= N; i++) {
                    if (selected[i])
                        sum1 += population[i];
                    else
                        sum2 += population[i];
                }
                if (gap == -1)
                    gap = Math.abs(sum1 - sum2);
                else
                    gap = Math.min(gap, Math.abs(sum1 - sum2));
            }

            return;
        }

        selected[idx] = true;
        subSet(idx + 1);
        selected[idx] = false;
        subSet(idx + 1);
    }

    static boolean isLinked(ArrayList<Integer> group){
        boolean[] visited = new boolean[N + 1];
        Queue<Integer> queue = new ArrayDeque<Integer>();
        queue.offer(group.get(0));
        int count = 1;
        visited[group.get(0)] = true;
        while (!queue.isEmpty()) {
            int cur = queue.poll();
            for (int i = 0; i < graph.get(cur).size(); i++) {
                int next = graph.get(cur).get(i);
                if (visited[next])
                    continue;
                visited[next] = true;
                if (!group.contains(next))
                    continue;
                queue.offer(next);
                count++;
            }
        }
        if (count != group.size())
            return false;

        return true;
    }



}
