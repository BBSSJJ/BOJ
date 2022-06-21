//https://www.acmicpc.net/problem/2164
#include <iostream>
#include <queue>
using namespace std;

int N, tmp;
queue<int> q;
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        q.push(i);
    }
    for(int i = 0; i < N-1; i++){
        q.pop();
        tmp = q.front();
        q.pop();
        q.push(tmp);
    }
    cout << q.front() << endl;
}