import java.util.*;

class Solution {
    
    List<Integer>[] graph;
    int N;
    int answer;
    boolean[] status;
    
    public int solution(int[] info, int[][] edges) {
        answer = 0;
        graph = new ArrayList[info.length];
        N = info.length;
        status = new boolean[1 << N];
        for(int i = 0; i < (1 << N); i++){
            status[i] = false;
        }
        
        for(int i = 0; i < info.length; i++){
            graph[i] = new ArrayList<>();
        }
        for(int i = 0; i < edges.length; i++){
            graph[edges[i][0]].add(edges[i][1]);
        }
        
        backTracking(0, 1, 0, 0, info);
        
        
        
        return answer;
    }
    
    public void backTracking(int cur, int visited, int sheepCount, int wolfCount, int[] info){
        
        visited |= (1 << cur);
        if(status[visited]) return;
        
        if(info[cur] == 0){
            sheepCount += 1;
        } else {
            wolfCount += 1;
        }
        
        if(wolfCount >= sheepCount) return;
        answer = Math.max(answer, sheepCount);
        
        for(int i = 0; i < N; i++){
            if((visited & (1 << i)) == 0) continue;
            
            for(int j = 0; j < graph[i].size(); j++){
                int next = graph[i].get(j);
                if((visited & (1 << next)) != 0) continue;
                backTracking(next, visited, sheepCount, wolfCount, info);
            }
        }
        
        status[visited] = true;
    }
}