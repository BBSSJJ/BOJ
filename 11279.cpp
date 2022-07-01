// https://www.acmicpc.net/problem/11279
#include <iostream>
#include <queue>

using namespace std;

int N, x;
priority_queue<int> p;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        if(x == 0){
            if(p.empty()){
                cout << 0 << "\n";
            }
            else{
                cout << p.top() << "\n";
                p.pop();
            }
        }
        else{
            p.push(x);
        }
    }
}