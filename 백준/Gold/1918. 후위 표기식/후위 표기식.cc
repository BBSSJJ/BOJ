#include <iostream>
#include <stack>
#include <string>

using namespace std;

string s;

// void dfs(string str) { char cur = str[0];
//     if(str[2] ==
// }

int main() {
    cin >> s;
    stack<char> operation;

    for (int i = 0; i < s.length(); i++) {
        char cur = s[i];
        if (cur == '(') {
            operation.push(cur);
        } else if (cur == ')') {
            while (!operation.empty() && operation.top() != '(') {
                cout << operation.top();
                operation.pop();
            }
            if (operation.top() == '(') operation.pop();

        } else if (cur == '-' || cur == '+') {
            while (!operation.empty() && operation.top() != '(') {
                cout << operation.top();
                operation.pop();
            }
            operation.push(cur);
        } else if (cur == '*' || cur == '/') {
            while (!operation.empty() && (operation.top() == '*' || operation.top() == '/')) {
                cout << operation.top();
                operation.pop();
            }
            operation.push(cur);
        } else {
            cout << cur;
        }
    }
    while (!operation.empty()) {
        cout << operation.top();
        operation.pop();
    }
}