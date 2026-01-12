import java.util.*;
import java.io.*;

class Solution {
    public int solution(int x, int y, int n) {
        
        Queue<Integer> que = new LinkedList<Integer>();
        int[] visited = new int[y + 1];
        Arrays.fill(visited, -1);
        visited[x] = 0;
        que.offer(x);
        
        while(!que.isEmpty()){
            int cur = que.poll();
            int A = cur + n;
            int B = cur * 2;
            int C = cur * 3;
            if (A <= y && visited[A] == -1) {
                visited[A] = visited[cur] + 1;
                que.offer(A);
            }
            if (B <= y && visited[B] == -1) {
                visited[B] = visited[cur] + 1;
                que.offer(B);
            }
            if (C <= y && visited[C] == -1) {
                visited[C] = visited[cur] + 1;
                que.offer(C);
            }
        }
        
        return visited[y];
    }
}