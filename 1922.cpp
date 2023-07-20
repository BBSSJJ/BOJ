#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Kruscal Algorithm 이용

int N, M, u, v, c, answer;

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
        pq.push({c, {u, v}});
    }

    while (!pq.empty()) {
        int cur_u = pq.top().second.first;
        int cur_v = pq.top().second.second;
        int cur_c = pq.top().first;
        pq.pop();

        int parent_u = find_parent(cur_u);
        int parent_v = find_parent(cur_v);

        if (parent_u != parent_v) {
            // 연결
            parent[parent_u] = parent_v;
            answer += cur_c;

        } else
            continue;
    }

    cout << answer << endl;
}

// Prim Algorithm 이용
// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

// int parent[10001];
// vector<pair<int, int>> graph[10001];
// bool visited[10001];
// priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
// int V, E, A, B, C;
// int answer;

// int main() {

// 	cin >> V >> E;

// 	for (int i = 1; i <= V; i++) {
// 		parent[i] = i;
// 	}

// 	for (int i = 0; i < E; i++) {
// 		cin >> A >> B >> C;
// 		graph[A].push_back({ B, C });
// 		graph[B].push_back({ A, C });
// 	}

// 	q.push({ 0, 1 });
// 	while (!q.empty()) {
// 		int cur_dist = q.top().first;
// 		int cur = q.top().second;
// 		q.pop();

// 		//방문된 노드면 다음노드로
// 		if (visited[cur]) continue;

// 		//방문되지 않은 노드면 방문
// 		visited[cur] = true;
// 		answer += cur_dist;

// 		for (int i = 0; i < graph[cur].size(); i++) {
// 			int next = graph[cur][i].first;
// 			int next_dist = graph[cur][i].second;
// 			if (visited[next]) continue;
// 			q.push({ next_dist, next });
// 		}
// 	}

// 	cout << answer << endl;
// }