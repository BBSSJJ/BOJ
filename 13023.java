import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	static int N, M;
	static ArrayList<ArrayList<Integer>> relation;
	static boolean answer;
	static boolean[] visited;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		visited = new boolean[N];
		relation = new ArrayList<ArrayList<Integer>>();

		for (int i = 0; i < N; i++) {
			relation.add(new ArrayList<Integer>());
		}

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int to = Integer.parseInt(st.nextToken());
			int from = Integer.parseInt(st.nextToken());
			relation.get(to).add(from);
			relation.get(from).add(to);
		}

		for (int i = 0; i < N; i++) {
			if (!answer) {
				visited[i] = true;
				dfs(i, 0);
				visited[i] = false;
			}
		}

		if (answer)
			System.out.println(1);
		else
			System.out.println(0);

	}

	public static void dfs(int a, int depth) {
		if (depth == 4) {
			answer = true;
			return;
		}
		for (int i = 0; i < relation.get(a).size(); i++) {
			int next = relation.get(a).get(i);
			if (!visited[next]) {
				visited[next] = true;
				dfs(next, depth + 1);
				visited[next] = false;
			}
		}
	}

}
