// https://www.acmicpc.net/problem/17298
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N, n;
stack<int> s;
vector<int> A;
vector<int> NGE;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> n;
        A.push_back(n);
    }
    int Asize = A.size();
    for(int i = 0; i < Asize; i++){
        while(!s.empty()){
            if(s.top() > A[Asize - 1 - i]){
                break;
            }
            else{
                s.pop();
            }
        }
        if(s.empty()){
            NGE.push_back(-1);
            s.push(A[Asize - 1 - i]);
        }
        else{
            NGE.push_back(s.top());
            s.push(A[Asize - 1 - i]);

        }
    }
    for(int i = 0; i < Asize; i++){
        cout << NGE[Asize - 1 - i] << " ";
    }
}