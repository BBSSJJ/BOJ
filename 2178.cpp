#include <queue>
#include <iostream>
using namespace std;

int N, M, depth;
string str;
int graph[100][100];
int visited[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> q;

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < M; j++)
        {
            graph[i][j] = str[j] - '0';
        }
    }

    q.push({0, 0});
    visited[0][0] = 1;
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M && graph[nx][ny] != 0 && visited[nx][ny] == 0)
            {
                visited[nx][ny] = visited[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << visited[N - 1][M - 1] << endl;
}