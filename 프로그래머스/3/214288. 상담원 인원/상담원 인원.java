import java.util.*;

class Solution {
    
    public static List<int[]>[] req;
    
    public int solution(int k, int n, int[][] reqs) {
        int answer = 0;
        req = new ArrayList[k + 1];
        
        for(int i = 1; i <= k; i++){
            req[i] = new ArrayList<>();
        }
        
        for(int i = 0; i < reqs.length; i++){
            req[reqs[i][2]].add(new int[] {reqs[i][0], reqs[i][1]});
        }
        
        
        int[] mentorCount = new int[k + 1];
        for(int i = 1; i <= k; i++){
            mentorCount[i] = 1;
        }
        
        for(int i = 0; i < n - k; i++){
            int maxLatencyDesc = 0;
            int maxNum = 0;
            for(int j = 1; j <= k; j++){
                int temp = calcLatency(j, mentorCount[j]) - calcLatency(j, mentorCount[j] + 1);
                if(temp > maxLatencyDesc) {
                    maxLatencyDesc = temp;
                    maxNum = j; 
                }
            }
            mentorCount[maxNum] += 1;
        }
        
        for(int j = 1; j <= k; j++){
            answer += calcLatency(j, mentorCount[j]);
        }
        
        return answer;
    }
    
    public int calcLatency(int num, int count){
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int latency = 0;
        
        for(int i = 0; i < count; i++){
            pq.offer(0);
        }
        
        for(int i = 0; i < req[num].size(); i++){
            int[] cur = req[num].get(i);
            if(pq.peek() <= cur[0]){
                pq.poll();
                pq.offer(cur[0] + cur[1]);
            } else{
                int temp = pq.poll();
                latency += (temp - cur[0]);
                pq.offer(temp + cur[1]);
            }
        }
        return latency;
    }
}