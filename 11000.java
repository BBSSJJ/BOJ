import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static Time[] timeTable;

    public static void main(String[] args) throws NumberFormatException, IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        timeTable = new Time[N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            timeTable[i] = new Time(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        //시작 시간 순으로 정렬!!!!!!
        Arrays.sort(timeTable);

        //pq에 끝 시간 넣고, 배열 순회하면서 만약 원소의 시작시간이 pq의 맨 앞(끝나는 시간)보다 크면 pq에서 하나 빼고 현재 원소의 끝 시간 넣어준다
        // 만약 원소의 시작 시간이 pq의 맨 앞보다 작으면, 강의실이 하나 더 필요한 것이므로 pq에 넣어준다.
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        pq.add(timeTable[0].end);

        for (int i = 1; i < N; i++) {
            if (pq.peek() > timeTable[i].start) {
                pq.add(timeTable[i].end);
            } else {
                pq.poll();
                pq.add(timeTable[i].end);
            }
        }

        System.out.println(pq.size());
    }
}

class Time implements Comparable<Time> {
    int start;
    int end;

    Time(int start, int end) {
        this.start = start;
        this.end = end;
    }

    @Override
    public int compareTo(Time o) {
        if (this.start - o.start > 0) return 1;
        else if (this.start - o.start == 0) {
            return this.end - o.end;
        } else return -1;
    }
}

