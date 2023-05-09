#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E, K, u, v, w;
vector<pair<int, int>> graph[20001];
bool visited[20001];
int dist[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void djk(int start){
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()){
        int cur = pq.top().second;
        int cur_d = pq.top().first;
        pq.pop();

        if(visited[cur]) continue;
        
        visited[cur] = true;

        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i].first;
            int next_d = graph[cur][i].second;
            
            if(dist[next] > cur_d + next_d){
                dist[next] = cur_d + next_d;
                pq.push({dist[next], next});
            }
        
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> V >> E >> K;
    for(int i = 1; i<= E; i++){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    for(int i = 1; i <= V; i++){
        dist[i] = 1000000;
    }

    djk(K);

    for(int i = 1; i <= V; i++){
        if(dist[i] == 1000000)
            cout << "INF" << "\n";
        
        else
        cout << dist[i] << "\n"; 
    }
    return 0;
}