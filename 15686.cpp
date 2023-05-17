#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
int city[50][50];

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int visited[14];

int calculate_distance(){
    int sum = 0;
    for(int i = 0; i < house.size(); i++){
        int min_distance = 100000;
        for(int j = 0; j < chicken.size(); j++){
            if(visited[j]){
                int distance = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
                min_distance = min(distance, min_distance);
            }
        }
        sum += min_distance;
    }
    return sum;
}

int answer = 100000;
void select_chicken(int x, int count){
    if(count == M){
        answer = min(calculate_distance(), answer);
        return;
    }
    for(int i = x; i < chicken.size(); i++){
        if(visited[i]) continue;
        visited[i] = 1;
        select_chicken(i, count + 1);
        visited[i] = 0;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> city[i][j];

            if(city[i][j] == 1){
                house.push_back({i, j});
            }
            else if(city[i][j] == 2){
                chicken.push_back({i, j});
            }
        }
    }

    select_chicken(0 , 0);

    cout << answer << "\n";
    
    
}
