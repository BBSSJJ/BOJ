//13144
//결과 long long type인 것 조심
#include <iostream>
#include <vector>


using namespace std;

int visited[100001];
vector<int> v;
int N;
long long answer;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for(int i = 0 ; i < N; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	int st = 0;
	int ed = 0;

	
	for (int st = 0; st < N; st++) {
		while (ed < N) {
			if (visited[v[ed]] == 1) break;
			visited[v[ed]] = 1;
			ed++;
		}
		answer += (ed - st);
		visited[v[st]] = 0;
	}
	cout << answer;
}