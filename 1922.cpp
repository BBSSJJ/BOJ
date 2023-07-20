#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, u, v, c, answer;


//Kruscal
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int parent[1001];
int find_parent(int a) {
	int cur = a;
	while (parent[cur] != 0) {
		cur = parent[cur];
	}
	return cur;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> c;
		pq.push({ c, {u, v} });
	}



	//Kruscal
	while (!pq.empty()) {
		int cur_u = pq.top().second.first;
		int cur_v = pq.top().second.second;
		int cur_c = pq.top().first;
		pq.pop();


		int parent_u = find_parent(cur_u);
		int parent_v = find_parent(cur_v);


		if (parent_u != parent_v) {
			//연결
			parent[parent_u] = parent_v;
			answer += cur_c;

		}
		else
			continue;
	}

	cout << answer << endl;


}