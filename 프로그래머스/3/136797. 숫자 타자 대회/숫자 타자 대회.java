class Solution {
    int dist[][] = {
        {1, 7, 6, 7, 5, 4, 5, 3, 2, 3},
        {7, 1, 2, 4, 2, 3, 5, 4, 5, 6},
        {6, 2, 1, 2, 3, 2, 3, 5, 4, 5},
        {7, 4, 2, 1, 5, 3, 2, 6, 5, 4},
        {5, 2, 3, 5, 1, 2, 4, 2, 3, 5},
        {4, 3, 2, 3, 2, 1, 2, 3, 2, 3},
        {5, 5, 3, 2, 4, 2, 1, 5, 3, 2},
        {3, 4, 5, 6, 2, 3, 5, 1, 2, 4},
        {2, 5, 4, 5, 3, 2, 3, 2, 1, 2},
        {3, 6, 5, 4, 5, 3, 2, 4, 2, 1}
    };
    
    public int solution(String numbers) {
        int answer = Integer.MAX_VALUE;
        int dp[][][] = new int[10][10][numbers.length()];

        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 10; j++)
                for(int k = 0; k < numbers.length(); k++)
                    dp[i][j][k] = Integer.MAX_VALUE;
        
        dp[numbers.charAt(0) - '0'][6][0] = dist[4][numbers.charAt(0) - '0']; 
        dp[4][numbers.charAt(0) - '0'][0] = dist[6][numbers.charAt(0) - '0']; 
        
        for(int k = 1; k < numbers.length(); k++){
            int target = numbers.charAt(k) - '0';
            
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 10; j++){
                    if(dp[i][j][k - 1] == Integer.MAX_VALUE) continue;
                    if(i == j) continue;
                    // 왼쪽 움직일 때
                    dp[target][j][k] = Math.min(dp[target][j][k], dist[i][target] + dp[i][j][k - 1]);
                    // 오른쪽 움직일 때
                    dp[i][target][k] = Math.min(dp[i][target][k], dist[target][j] + dp[i][j][k - 1]);
                }
            }
        }
        
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                answer = Math.min(answer, dp[i][j][numbers.length() - 1]);
            }
        }
        
        return answer;
    }
}