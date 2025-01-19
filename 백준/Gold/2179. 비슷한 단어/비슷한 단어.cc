#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N, answerLen, firstNum, secondNum;
string word, tmp;

int main() {
    cin >> N;
    vector<string> words;
    map<string, int> m;
    map<string, int>::iterator it;

    for (int i = 0; i < N; i++) {
        cin >> word;
        words.push_back(word);

        for (int j = 1; j <= word.length(); j++) {
            tmp = word.substr(0, j);
            it = m.find(tmp);
            if (it == m.end()) {
                m.insert({tmp, i});
                continue;
            }
            if (answerLen > tmp.length()) continue;
            if (answerLen == tmp.length() && firstNum <= it->second) continue;  // 이거 중요
            answerLen = tmp.length();
            firstNum = it->second;
            secondNum = i;
        }
    }
    if (answerLen == 0) {
        firstNum = 0;
        secondNum = 1;
    }
    cout << words[firstNum] << "\n" << words[secondNum];
}