#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, n;
vector<int> value;
int main(){
    cin >> N;
    for(int i = 0 ; i < N; i++){
        cin >> n;
        value.push_back(n);
    }
    
    sort(value.begin(), value.end());

    int start = 0;
    int end = N - 1;
    int answer = 200000002;
    while(start < end){
        int mix = value[start] + value[end];
        if(mix == 0){
            answer = 0;
            break;
        }
        else if(mix < 0){
            start++;
        }
        else if(mix > 0){
            end--;
        }
        if(abs(mix) < abs(answer)){
            answer = mix;
        }
    }

    cout << answer;
}