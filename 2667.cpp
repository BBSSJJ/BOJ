#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int N;
int map[25][25];
int visited[25][25];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;

bool OOB(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= N)
        return true;
    else
        return false;
}

int bfs(int x, int y)
{
    int group = 1;
    q.push({x, y});
    visited[x][y] = 1;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (OOB(nx, ny) || visited[nx][ny])
                continue;
            if (map[nx][ny] == 0)
                continue;
            else
            {
                group += 1;
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    return group;
}

int main()
{
    string s;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            map[i][j] = s[j] - '0';
        }
    }

    vector<int> answer;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && map[i][j] == 1)
                answer.push_back(bfs(i, j));
        }
    }
    sort(answer.begin(), answer.end());

    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << "\n";
    }
}