#include <iostream>
#include <queue>
using namespace std;
int n, m;
int graph[50][50];
int visited[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
string str;

int dfs(int i, int j){
    int _max = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = 1;
    while(!q.empty()){
        int _x = q.front().first;
        int _y = q.front().second;
        q.pop();

        for(int k = 0; k < 4; k++){
            int nx = _x + dx[k];
            int ny = _y + dy[k];

            if(nx >= 0 && ny >= 0 && nx < n && ny <m && graph[nx][ny] == 1){
                if(visited[nx][ny]==0){
                    q.push({nx, ny});
                    visited[nx][ny] = visited[_x][_y] + 1;
                    _max = max(_max, visited[nx][ny]);
                }
            }
        }
    }
    return _max;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> str;
        for(int j = 0; j < m; j++){
            if(str[j] == 'W')
                graph[i][j] = 0;
            else if(str[j] == 'L')
                graph[i][j] = 1;
        }
    }

    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(graph[i][j] == 1){
                result = max(dfs(i, j), result);
                for(int k = 0; k < n; k++){
                    for(int l = 0; l < m; l++){
                        visited[k][l] = 0;
                    }
                }
            }

        }
    }

    cout << result - 1  << endl;

}