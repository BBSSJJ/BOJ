// https://www.acmicpc.net/problem/1260
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, V, v1, v2;
vector<int> graph[1001];
bool visited[1001];

void dfs(int v){
    visited[v] = true;
    cout << v << " ";
    int size = graph[v].size();
    for(int i = 0; i < size; i++){
        int next = graph[v][i];
        if(!visited[next]){
            dfs(next);
        }
    }
}

void bfs(int v){
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        int size = graph[cur].size();
        for(int i = 0; i < size; i++){
            int next = graph[cur][i];
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
}


int main(){
    cin >> N >> M >> V;

    for(int i = 0; i < M; i++){
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for(int i = 1; i <= N; i++){
        if(!graph[i].empty()){
            sort(graph[i].begin(), graph[i].end());
        }
    }
    dfs(V);
    cout << "\n";
    for(int i = 1; i <= N; i++){
        visited[i] = false;
    }
    bfs(V);
}