#include <iostream>
#include <algorithm>

using namespace std;

int N;
int triangle[501][501];
int dp[501][501];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> triangle[i][j];
            if(i == N){
                dp[i][j] = triangle[i][j];
            }
        }
    }


    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
        }
    }


    cout << dp[1][1] << "\n";
}