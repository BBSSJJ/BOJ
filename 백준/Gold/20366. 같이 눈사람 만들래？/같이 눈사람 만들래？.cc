#include <algorithm>
#include <climits>
#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, h;
    cin >> N;
    vector<int> height;
    vector<pair<int, pair<int, int>>> sums;

    for (int i = 0; i < N; i++) {
        cin >> h;
        height.push_back(h);
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            sums.push_back({height[i] + height[j], {i, j}});
        }
    }
    sort(sums.begin(), sums.end());
    int start = 0;
    int end = 1;
    int minGap = INT_MAX;

    // 시작점 기준으로 네게 다 다른거쓰는 가장 작은것 찾아내고 차이 저장하면 된다.
    // while (start < sums.size() - 1) {
    //     int curGap = sums[end].first - sums[start].first;
    //     set<int> used;
    //     used.insert(sums[start].second.first);
    //     used.insert(sums[start].second.second);
    //     used.insert(sums[end].second.first);
    //     used.insert(sums[end].second.second);
    //     if (used.size() != 4) {
    //         if (end == sums.size() - 1) {
    //             start++;
    //             end = start + 1;
    //         } else
    //             end++;
    //         continue;
    //     }

    //     if (curGap < minGap) {
    //         minGap = curGap;
    //     }
    //     start++;
    //     end = start + 1;
    //     continue;
    // }

    vector<int> used;
    int curGap;
    for (int i = 0; i < sums.size(); i++) {
        used.push_back(sums[i].second.first);
        used.push_back(sums[i].second.second);
        for (int j = i + 1; j < sums.size(); j++) {
            if (find(used.begin(), used.end(), sums[j].second.first) == used.end() && find(used.begin(), used.end(), sums[j].second.second) == used.end()) {
                curGap = sums[j].first - sums[i].first;
                if (minGap > curGap) {
                    minGap = curGap;
                }
                break;
            }
        }
        used.clear();
    }
    cout << minGap;
}