
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb;


        int N = Integer.parseInt(st.nextToken());

        Node root = new Node();

        for (int n = 0; n < N; n++) {
            sb = new StringBuilder();
            st = new StringTokenizer(br.readLine());
            String nickname = st.nextToken();
            int nicknameLength = nickname.length();
            boolean aliasMade = false;
            Node curNode = root;
            for (int i = 0; i < nicknameLength; i++) {
                char curChar = nickname.charAt(i);
                if (curNode.next[curChar - 'a'] == null) {
                    Node newNode = new Node();
                    if (!aliasMade) {
                        sb.append(curChar);
                        aliasMade = true;
                    }
                    curNode.next[curChar - 'a'] = newNode;
                    curNode = newNode;
                } else {
                    curNode = curNode.next[curChar - 'a'];
                    sb.append(curChar);
                }
            }
            if(curNode.sameNicknameCount == 0){
                curNode.sameNicknameCount = 1;
            }
            else{
                curNode.sameNicknameCount += 1;
                sb.append(curNode.sameNicknameCount);
            }
            System.out.println(sb.toString());
        }

    }


    static class Node {
        int sameNicknameCount = 0;
        public Node[] next = new Node[26];
    }
}


/*
지문이 그지같다.
예제 2번 입력예시에서
baekjoon 이 두번째로 들어가면 bae가 되어야 하는거 아닌가? 왜 beakj이지
 */