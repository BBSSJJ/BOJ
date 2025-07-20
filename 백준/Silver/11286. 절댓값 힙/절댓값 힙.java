import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());

		PriorityQueue<Integer> pQue = new PriorityQueue<>();
		PriorityQueue<Integer> nQue = new PriorityQueue<>(Comparator.reverseOrder());

		for (int i = 0; i < N; i++) {
			int num = Integer.parseInt(br.readLine());
			if (num == 0) {
				int out = 0;
				if (nQue.isEmpty() && pQue.isEmpty())
					out = 0;
				else if (nQue.isEmpty())
					out = pQue.poll();
				else if (pQue.isEmpty())
					out = nQue.poll();
				else {
					if (-nQue.peek() > pQue.peek())
						out = pQue.poll();
					else
						out = nQue.poll();
				}

				System.out.println(out);

			} else if (num < 0)
				nQue.offer(num);
			else if (num > 0)
				pQue.offer(num);
		}
	}

}
