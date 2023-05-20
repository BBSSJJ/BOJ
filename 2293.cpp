#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K, k;

int dp[10001];

vector<int> coin;
int main(){

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> k;
        coin.push_back(k);
    }
    dp[0] = 1;

    for(int i = 0; i < N; i++){
        for(int j = 1; j <= K; j++){
            if(j - coin[i] >= 0){
                dp[j] += dp[j -coin[i]] ;
            }
        }
    }

    cout<< dp[K] << "\n";

}