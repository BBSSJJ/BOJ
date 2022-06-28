// https://www.acmicpc.net/problem/2493
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N, n;
stack<int> s_height;
stack<int> s_num;
vector<int> answer;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> n;
    
        if(s_height.empty()){
            s_height.push(n);
            s_num.push(i + 1);
            answer.push_back(0);
        }
        else{
            while(s_height.top() < n){
                s_height.pop();
                s_num.pop();
                if(s_height.empty())
                    break;
            }
            if(s_height.empty()){
                s_height.push(n);
                s_num.push(i + 1);
                answer.push_back(0);
            }
            else{
                answer.push_back(s_num.top());
                s_height.push(n);
                s_num.push(i + 1);
            }
        }
    }
    int answer_size = answer.size();
    for(int i = 0; i <answer_size; i++){
        cout << answer[i] << " ";
    }
}