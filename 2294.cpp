#include <iostream>
using namespace std;
int n, k;
int v[101];
int dp[10001];

int main(){
    cin >> n >> k;

    for(int i = 1 ; i <= 10001; i++){
        dp[i] = 9999999;
    }

    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = v[i]; j <= k; j++){
            dp[j] = min(dp[j], dp[j - v[i]] + 1);
        }
    }

    if(dp[k] == 9999999){
    cout << -1 << endl;
    }
    else{
    cout << dp[k] << endl;
    }
}
