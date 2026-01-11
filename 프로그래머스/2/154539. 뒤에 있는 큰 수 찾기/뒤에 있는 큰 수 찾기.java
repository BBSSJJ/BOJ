import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        int N = numbers.length;
        int[] answer = new int[N];
        
        Stack<int[]> st = new Stack<int[]>();
        for(int i = 0; i < N; i++){
            while(!st.isEmpty() && st.peek()[0] < numbers[i]){
                int[] cur = st.pop();
                answer[cur[1]] = numbers[i];
            }
            st.push(new int[] {numbers[i], i});
        }
        while(!st.isEmpty()){
            int[] cur = st.pop();
            answer[cur[1]] = -1;
        }
        
        return answer;
    }
}