// 13913
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool OOB(int x)
{
    if (x < 0 || x > 100000)
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int visited[100001];
    queue<pair<int, int>> que;
    int time = 0;

    for (int i = 0; i < 100001; i++)
    {
        visited[i] = -1;
    }

    int N, M;
    cin >> N >> M;

    que.push({N, 0});

    visited[N] = N;

    while (!que.empty())
    {
        int cx = que.front().first;
        int ctime = que.front().second;
        que.pop();

        // case 1
        int ntime = ctime + 1;

        int nx = cx + 1;
        if (!OOB(nx) && visited[nx] == -1)
        {
            visited[nx] = cx;
            que.push({nx, ntime});
            if (nx == M)
            {
                time = ntime;
                break;
            }
        }

        // case 2
        nx = cx - 1;
        if (!OOB(nx) && visited[nx] == -1)
        {
            visited[nx] = cx;
            que.push({nx, ntime});
            if (nx == M)
            {
                time = ntime;
                break;
            }
        }

        // case 3
        nx = cx * 2;
        if (!OOB(nx) && visited[nx] == -1)
        {
            visited[nx] = cx;
            que.push({nx, ntime});
            if (nx == M)
            {
                time = ntime;
                break;
            }
        }
    }

    int cur = M;
    stack<int> st;
    while (visited[cur] != cur)
    {
        st.push(cur);
        cur = visited[cur];
    }

    cout << time << "\n";
    cout << cur << " ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}