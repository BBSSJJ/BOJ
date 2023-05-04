#include <iostream>

using namespace std;

int n, k;
long long dp[201][201];

int main(){
    cin >> n >> k;
    for(int i = 0; i <= n; i++){
        dp[1][i] = 1;
    }
    if(k < 2){
        cout << dp[k][n] << endl;
        return 0;
    }
    for(int i = 2; i <= k; i++){
        for(int j = 0; j <= n; j++){
            for(int m = 0; m <= j; m++){
                dp[i][j] = (dp[i][j] % 1000000000 + dp[i - 1][m] % 1000000000) % 1000000000;
            }
        }
    }

    cout << dp[k][n] << endl;
}