#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;
int visited[100001];
bool found = false;
vector<int> answer_vector;


int main(){
    cin >> N >> K;
    queue<pair<int, int>> que;
    for(int i = 0; i < 100001; i++){
        visited[i] = 100001;
    }

    que.push({N, 0});
    if(N == K){
        cout << 0 << "\n" << 1 << endl;
        return 0;
    }
    while(!que.empty()){
        int cur = que.front().first;
        int cur_depth = que.front().second;
        que.pop();

        if(cur - 1 == K){
            answer_vector.push_back(cur_depth + 1);
        }
        if(cur - 1 >= 0 && visited[cur - 1] >= cur_depth + 1){
            visited[cur - 1] = cur_depth + 1;
            que.push({cur - 1, cur_depth + 1});
        }
        
        if(cur + 1 == K){
            answer_vector.push_back(cur_depth + 1);
        }
        if(cur + 1 <= 100000 && visited[cur + 1] >= cur_depth + 1){
            visited[cur + 1] = cur_depth + 1;
            que.push({cur + 1, cur_depth + 1});
        }

        if(cur * 2 == K){
            answer_vector.push_back(cur_depth + 1);
        }
        if(cur * 2 <= 100000 && visited[cur * 2] >= cur_depth + 1){
            visited[cur * 2] = cur_depth + 1;
            que.push({cur * 2, cur_depth + 1});
        }
    }
    int min_depth = 100001;
    for(int i = 0; i < answer_vector.size(); i++){
        min_depth = min(answer_vector[i], min_depth);
    }
    int count = 0;
    for(int i = 0; i < answer_vector.size(); i++){
        if(answer_vector[i] == min_depth){
            count++;
        }
    }
    cout << min_depth << "\n" << count << endl;
}