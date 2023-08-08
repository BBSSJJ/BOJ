// #13904
// 점수 순으로 정렬 후, date를 배열의 index로 생각하여 높은 점수부터
// 배열의 date번 째 index에 넣는다. 이미 있으면 하루 씩 앞당긴다.
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, d, w;
int answer;
int task_date[1001];

vector<pair<int, int>> task;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> d >> w;
        task.push_back({w, d});
    }

    sort(task.begin(), task.end());

    for (int i = N - 1; i >= 0; i--) {
        int date = task[i].second;
        int score = task[i].first;

        int tmp = date;

        while (task_date[tmp] != 0) {
            tmp--;
            if (tmp == 0) break;
        }
        if (tmp == 0) continue;
        task_date[tmp] = score;
    }

    for (int i = 0; i < 1001; i++) {
        answer += task_date[i];
    }

    cout << answer;
}