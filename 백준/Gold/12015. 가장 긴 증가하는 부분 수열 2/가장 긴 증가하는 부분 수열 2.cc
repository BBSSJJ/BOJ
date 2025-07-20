
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, num;
    cin >> N;
    vector<int> lis;
    vector<int>::iterator iter;
    cin >> num;
    lis.push_back(num);
    for (int i = 1; i < N; i++) {
        cin >> num;
        if (lis[lis.size() - 1] >= num) {
            iter = lower_bound(lis.begin(), lis.end(), num);
            *iter = num;
        } else {
            lis.push_back(num);
        }
    }
    cout << lis.size();
}