import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int answer = 0;

        for (int i = 0; i < N; i++) {

            char[] charArr = br.readLine().toCharArray();
            Stack<Character> stack = new Stack<>();
            for (char c : charArr) {
                if (c == 'A') {
                    if (stack.empty()) {
                        stack.push('A');
                        continue;
                    }
                    char top = stack.peek();
                    if (top == 'A') stack.pop();
                    else stack.push('A');
                }
                if (c == 'B') {
                    if (stack.empty()) {
                        stack.push('B');
                        continue;
                    }
                    char top = stack.peek();
                    if (top == 'B') stack.pop();
                    else stack.push('B');
                }
            }
            if (stack.empty()) answer++;
        }

        System.out.println(answer);

    }
}

