import java.util.*;

class Solution {
    
    int[] dx = {1, 0, -1, 0};
    int[] dy = {0, 1, 0, -1};
    int N;
    int M;
    
    
    public int solution(String[] storage, String[] requests) {        
        N = storage.length;
        M = storage[0].length();
        Character[][] status = new Character[N + 2][M + 2];
        
        for(int i = 0; i < N + 2; i++){
            for(int j = 0; j < M + 2; j++){
                status[i][j] = '0';
            }
        }
        
        for(int i = 1 ; i <= N; i++){
            String str = storage[i - 1];
            for(int j = 1; j <= M; j++){
                status[i][j] = str.charAt(j - 1);
            }
        }
        
        int answer = N * M;
        
        for(int r = 0; r < requests.length; r++){
            String request = requests[r];
            Character target = request.charAt(0);
            
            if(request.length() == 1){
                answer -= type1(status, target);
            } else {
                answer -= type2(status, target);
            }
        }
        
        
        return answer;
    }
    
    public boolean outOfBound(int x, int y){
        return x < 0 || y < 0 || x >= N + 2 || y >= M + 2;
    }
    
    public int type1(Character[][] status, Character target){
        Queue<int[]> que = new LinkedList<>();
        que.offer(new int[] {0, 0});
        boolean[][] visited = new boolean[N + 2][M + 2];
        int count = 0;
        
        while(!que.isEmpty()){
            int[] cur = que.poll();
            for(int i = 0; i < 4; i++){
                int nx = cur[0] + dx[i];
                int ny = cur[1] + dy[i];
                if(outOfBound(nx, ny) || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                if(status[nx][ny] == target){
                    status[nx][ny] = '0';
                    count++;
                } else if(status[nx][ny] == '0'){
                    que.offer(new int[] {nx, ny});
                }
            }
        }
        return count;
    }
    
    public int type2(Character[][] status, Character target){
        int count = 0;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                if(status[i][j] != target) continue;
                status[i][j] = '0';
                count++;
            }
        }
        return count;
    }
}