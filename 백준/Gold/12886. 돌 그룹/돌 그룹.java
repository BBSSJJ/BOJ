import java.util.*;
import java.io.*;

public class Main {
	
	public static int A, B, C;
	public static boolean[][] visited;
	public static int answer = 0;
    public static void main(String[] args) throws IOException{
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	
    	A = Integer.parseInt(st.nextToken());
    	B = Integer.parseInt(st.nextToken());
    	C = Integer.parseInt(st.nextToken());
    	
    	if( (A + B + C) % 3 != 0) {
    		System.out.println("0");
    		return ;
    	}
        
    	simulate();
    	System.out.println(answer);
    }
    
    public static void simulate() {
    	Queue<Node> q = new LinkedList<>();
    	
    	boolean[][] visited = new boolean[2001][2001];
    	
    	q.offer(new Node(A, B, C));
    	visited[A][B] = true;
    	
    	while(!q.isEmpty()) {
    		Node temp = q.poll();
    		int a = temp.a;
    		int b = temp.b;
    		int c = temp.c;
    		
    		if(a == b && b==c) {
    			answer = 1;
    			return ;
    		}
    		
    		//개수가 다른 두개 골라서 연산
    		if(a != b) {
    			int na = a > b ? a - b : a + a;
    			int nb = a > b ? b + b : b - a;
    			
    			if(visited[na][nb] == false) {
    				q.offer(new Node(na, nb, c));
    				visited[na][nb] = true; //
    			}
    		}
    		
    		if(b != c) {
    			int nb = b > c ? b - c : b + b;
    			int nc = b > c ? c + c : c - b;
    			if(visited[nb][nc] == false) {
    				q.offer(new Node(a, nb, nc));
    				visited[nb][nc] = true;
    			}
    		}
    		
    		if(a != c) {
    			int na = a > c ? a - c : a + a;
    			int nc = a > c ? c + c : c - a;
    			if(visited[na][nc] == false) {
    				q.offer(new Node(na, b, nc));
    				visited[na][nc] = true;
    			}
    		}
    		
    	}
    	
    }
}
 
class Node{
	int a;
	int b;
	int c;
	public Node(int a, int b, int c) {
		this.a=a;
		this.b=b;
		this.c=c;
	}
}