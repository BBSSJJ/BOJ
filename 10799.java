import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[] charArr = br.readLine().toCharArray();
        Stack<Integer> stack = new Stack<>();
        int answer = 0;

        for (int i = 0; i < charArr.length; i++) {
            if (charArr[i] == '(') {
                stack.push(-1);
            }
            else if(charArr[i] == ')'){
                int top = stack.pop();
                if(top == -1)
                    stack.push(1);
                else {
                    int lazerCount = top;
                    while(stack.peek() != -1){
                        lazerCount += stack.pop();
                    }
                    stack.pop();
                    stack.push(lazerCount);
                    answer += (lazerCount + 1);
                }
            }
        }
        System.out.println(answer);
    }
}

