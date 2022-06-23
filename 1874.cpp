// https://www.acmicpc.net/problem/1874
// 수열의 숫자(num) 들어올 때, 다음 스택에 들어갈 수 있는 숫자(n)과 크기를 비교해서
// num이 n보다 작으면 stack에서 pop시키면서 찾고, 만약 stack의 top보다 num이 커버리면 만들 수 없는 수열
// 또, 찾다가 stack의 size가 0이 되버리면 만들 수 없는 수열
// num이 n보다 크면, n이 num이 될 때 까지 push한 후 pop시켜준다.
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
stack<int> s;
vector<char> v;
int n, num;
int main()
{
    cin >> n;

    int next = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (next <= num)
        {
            while (next <= num)
            {
                s.push(next);
                v.push_back('+');
                next++;
            }
            s.pop();
            v.push_back('-');
        }
        else if (next > num)
        {
            while (s.top() != num)
            {
                if (s.top() > num || s.size() == 0)
                {
                    cout << "NO" << endl;
                    return 0;
                }
                s.pop();
                v.push_back('-');
            }
            s.pop();
            v.push_back('-');
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }
}