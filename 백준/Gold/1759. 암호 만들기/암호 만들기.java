import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int L, C;
	static char[] chars;
	static char[] selected;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());
		L = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());

		chars = new char[C];
		selected = new char[L];

		for (int i = 0; i < C; i++) {
			chars[i] = st.nextToken().charAt(0);
		}
		Arrays.sort(chars);

		select(0, 0);

	}

	public static void select(int depth, int cur) {
		if (depth == L) {
			StringBuilder sb = new StringBuilder();
			int vowel_count = 0;

			for (int i = 0; i < L; i++) {
				if (selected[i] == 'a' || selected[i] == 'e' || selected[i] == 'i' || selected[i] == 'o'
						|| selected[i] == 'u') {
					vowel_count++;
				}
			}
			if (vowel_count >= 1 && L - vowel_count >= 2) {
				for (int i = 0; i < L; i++) {
					sb.append(selected[i]);
				}
				System.out.println(sb);
			}
			return;
		}

		for (int i = cur; i < C; i++) {
			selected[depth] = chars[i];
			select(depth + 1, i + 1);
		}
	}

}
