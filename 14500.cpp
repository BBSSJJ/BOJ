#include <iostream>

using namespace std;

int N, M;
int graph[500][500];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool visited[500][500];
int answer;

int find_sum(int x, int y, int depth){
    int val = graph[x][y];
    int max_sum = 0;
    visited[x][y] = true;


    if(depth == 4){
        visited[x][y] = false;

        return val;
    }

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny]) continue;
        max_sum = max(find_sum(nx, ny, depth + 1), max_sum);
    }
    visited[x][y] = false;
    return max_sum + val;
}
//왼쪽이 막힌 경우 -> 1가지
int shape1(int x, int y){
    return graph[x][y] + graph[x][y + 1] + graph[x - 1][y] + graph[x + 1][y];
}

//오른쪽이 막힌 경우 -> 1가지

int shape2(int x, int y){
    return graph[x][y] + graph[x][y - 1] + graph[x - 1][y] + graph[x + 1][y];

}
//위가 막힌 경우 -> 1가지

int shape3(int x, int y){
    return graph[x][y] + graph[x][y - 1] + graph[x][y + 1] + graph[x + 1][y];

}
//아래가 막힌 경우 -> 1가지

int shape4(int x, int y){
    return graph[x][y] + graph[x][y - 1] + graph[x][y + 1] + graph[x - 1][y];

}

//안막혔으면 -> 4가지

//두 군데 막혔으면 패스




int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j< M; j++){
            cin >> graph[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M ;j++){
            answer = max(find_sum(i , j, 1), answer);
            visited[i][j] = false;
            if(i == 0 && j == 0) continue;
            else if(i == N-1 && j == 0) continue;
            else if (i == 0 && j == M - 1) continue;
            else if (i == N - 1 && j == M - 1) continue;
            if(i == 0) answer = max(shape3(i, j), answer);
            else if(i == N - 1) answer = max(shape4(i, j), answer);
            else if(j == 0) answer = max(shape1(i, j), answer);
            else if(j == M - 1) answer = max(shape2(i, j), answer);
            else{
                answer = max(shape1(i,j), answer);
                answer = max(shape2(i,j), answer);
                answer = max(shape3(i,j), answer);
                answer = max(shape4(i,j), answer);
            }
            
        }
    }
    cout << answer << "\n";
}
