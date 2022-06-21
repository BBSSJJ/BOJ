#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int K, N, tmp;
queue<int> q;
vector<int> v;

int main(){
cin >> N >> K;
for(int i = 1; i <= N; i++){
    q.push(i);
}
while(!q.empty()){
    for(int i = 0; i < K - 1; i++){
        tmp = q.front();
        q.pop();
        q.push(tmp);
    }
    tmp = q.front();
    q.pop();
    v.push_back(tmp);
}

vector<int>::iterator iter;
cout << "<";
for(iter = v.begin(); iter != v.end() - 1; iter++){
    cout << *iter << ", ";
}
cout << *(iter) << ">" << endl;
}