import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int N, answer;
    static boolean[] operateFirst;
    static String expression;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        operateFirst = new boolean[N];
        expression = br.readLine();
        answer = Integer.MIN_VALUE; // 0으로 하면 안됨. 정신차려

        for (int i = 0; i < N; i++) {
            operateFirst[i] = false;
        }

        makeAll(1);

        System.out.println(answer);
    }

    public static void makeAll(int idx) {
        if (idx >= N) {
            answer = Math.max(answer, calculate());
            return;
        }

        // 선택 안함
        makeAll(idx + 2);

        // 선택 함
        if (idx == 1 || !operateFirst[idx - 2]) {
            operateFirst[idx] = true;
            makeAll(idx + 2);
            operateFirst[idx] = false;
        }
    }

    public static int calculate() {
        int result = expression.charAt(0) - '0';
        for (int i = 1; i < N; i += 2) {
            if (i + 2 < N && operateFirst[i + 2]) {
                int b = expression.charAt(i + 1) - '0';
                int c = expression.charAt(i + 3) - '0';
                int tmp = operate(b, expression.charAt(i + 2), c);
                result = operate(result, expression.charAt(i), tmp);
                i += 2; // 조심하자. for문으로 다시 들어가서 +2 된다.
            } else {
                result = operate(result, expression.charAt(i), expression.charAt(i + 1) - '0');
            }
        }
        return result;
    }

    public static int operate(int a, char op, int b) {
        if (op == '+') return a + b;
        else if (op == '-') return a - b;
        else if (op == '*') return a * b;
        return 0;
    }
}
