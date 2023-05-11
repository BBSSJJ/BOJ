#include <iostream>
#include <stack>
using namespace std;

int N;
int h;
stack<int> st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    long long answer = 0;
    while (N--) {
        cin >> h;
        while (!st.empty() && st.top() <= h) {
            st.pop();
        }
        answer = answer + st.size();
        st.push(h);
    }
    cout << answer << "\n";
    return 0;
}