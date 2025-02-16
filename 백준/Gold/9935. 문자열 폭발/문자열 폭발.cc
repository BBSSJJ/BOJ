#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string str, pattern;
    cin >> str >> pattern;
    int sLen = str.length();
    int pLen = pattern.length();

    vector<char> vec;

    for (int i = 0; i < sLen; i++) {
        char cur = str[i];
        vec.push_back(cur);

        if (vec.size() < pLen) continue;

        int idx = vec.size() - 1;

        for (int j = 0; j < pLen; j++) {
            if (pattern[pLen - 1 - j] != vec[idx - j]) break;
            if (j == pLen - 1)
                for (int k = 0; k < pLen; k++) vec.pop_back();
        }
    }
    if (vec.empty())
        cout << "FRULA";
    else {
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i];
        }
    }
}