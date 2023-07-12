#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, n;
priority_queue<int, vector<int>, greater<int>> q;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        q.push(n);
    }

    int total_compare = 0;
    int card = 0;

    while (q.size() > 1)
    {
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        card = x + y;
        total_compare += card;

        q.push(card);
    }

    cout << total_compare << "\\n";
}