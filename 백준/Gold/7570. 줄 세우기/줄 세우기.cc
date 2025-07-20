#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int dp[1000001];
int lis;

int main() {
	cin >> N;
	int n;
	for (int i = 0; i < N; i++) {
		cin >> n; 
		dp[n] = dp[n - 1] + 1;
		lis = max(lis, dp[n]);
	}
	cout << N - lis;
	return 0;
}