import java.util.*;

class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        
        int[] serverCount = new int[24];
        
        for(int i = 0; i < 24; i++){
            int cover = serverCount[i] * m;
            if(players[i] > cover){
                int addCount = (players[i] - cover) / m;
                for(int j = 0; j < k && i + j < 24; j++){
                    serverCount[i + j] += addCount;
                }
                answer += addCount;
            }
        }
        
        
        return answer;
    }
}