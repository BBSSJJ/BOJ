// https://www.acmicpc.net/problem/11286
// priority queue 구현 시 compare structure 구현하는 방법 묻는 문제!
#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

struct compare{
bool operator()(int a, int b){
    if(abs(a) == abs(b)){
        return a > b;
    }
    return abs(a) > abs(b);
}
};

priority_queue<int, vector<int>, compare> pq;
int N, x;


int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        if(x == 0){
            if(pq.empty()){
                cout << 0 << endl;
            }
            else{
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        else{
            pq.push(x);
        }
    }
}