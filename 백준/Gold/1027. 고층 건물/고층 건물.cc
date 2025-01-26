#include <iostream>
#include <vector>

using namespace std;
int N;

int main() {
    cin >> N;
    vector<int> height(N);
    for (int i = 0; i < N; i++) {
        cin >> height[i];
    }
    int answer = 0;
    for (int i = 0; i < N; i++) {
        int curHeight = height[i];
        int count = 0;

        double inclination = -99999999999;
        for (int j = i - 1; j >= 0; j--) {
            int nextHeight = height[j];
            double curInclination = (nextHeight - curHeight) / (double)(i - j);  // double형으로 변환해붜야 함
            if (curInclination > inclination) {
                inclination = curInclination;
                count++;
            }
        }
        inclination = -99999999999;
        for (int j = i + 1; j < N; j++) {
            int nextHeight = height[j];
            double curInclination = (nextHeight - curHeight) / (double)(j - i);
            if (curInclination > inclination) {
                inclination = curInclination;
                count++;
            }
        }
        answer = max(answer, count);
    }
    cout << answer;
}