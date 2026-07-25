import java.util.*;

class Solution {
    
    
    public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {
        
        List<int[]>[] graph = new ArrayList[n + 1];
        int[] intensities = new int[n + 1];
        Arrays.fill(intensities, Integer.MAX_VALUE);
        Arrays.sort(summits);
        
        for(int i = 1; i <= n; i++){
            graph[i] = new ArrayList<>();
        }
        
        for(int i = 0; i < paths.length; i++){
            graph[paths[i][0]].add(new int[] {paths[i][1], paths[i][2]});
            graph[paths[i][1]].add(new int[] {paths[i][0], paths[i][2]});
        }
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> {
            if(o1[1] != o2[1]) return o1[1] - o2[1];
            else return o1[0] - o2[0];
        });
        
        for(int gate : gates){
            pq.offer(new int[] {gate, 0});
            intensities[gate] = 0;
        } 
        
        while(!pq.isEmpty()){
            int[] cur = pq.poll();
            
            if(cur[1] > intensities[cur[0]]) continue;
            
            for(int i = 0; i < graph[cur[0]].size(); i++){
                int[] next = graph[cur[0]].get(i);
                if(intensities[next[0]] <= Math.max(cur[1], next[1])) continue;
                intensities[next[0]] = Math.max(cur[1], next[1]);
                if(Arrays.binarySearch(summits, next[0]) >= 0) continue;
                pq.offer(new int[] {next[0], intensities[next[0]]});
                
            }
        }
        int answer = summits[0];
        for(int summit : summits){
            if (intensities[summit] >= intensities[answer]) continue;
            intensities[answer] = intensities[summit];
            answer = summit;
        }
        return new int[] {answer, intensities[answer]};
        
    }
}