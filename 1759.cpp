// 1759
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int L, C;
char c;
vector<char> chars;
vector<int> tmp;

int main() {
    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        cin >> c;
        chars.push_back(c);
    }

    sort(chars.begin(), chars.end());

    for (int i = 0; i < L; i++) {
        tmp.push_back(1);
    }
    for (int i = 0; i < C - L; i++) {
        tmp.push_back(0);
    }
    sort(tmp.begin(), tmp.end(), greater<>());

    do {
        vector<char> answer;
        int vowel_count = 0;
        for (int i = 0; i < C; i++) {
            if (tmp[i]) {
                answer.push_back(chars[i]);

                if (chars[i] == 'a' || chars[i] == 'e' || chars[i] == 'i' || chars[i] == 'o' || chars[i] == 'u') vowel_count++;
            }
        }
        if (vowel_count >= 1 && L - vowel_count >= 2) {
            for (int i = 0; i < L; i++) {
                cout << answer[i];
            }
            cout << "\n";
        }
    } while (prev_permutation(tmp.begin(), tmp.end()));
}