#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int N, M, u, v;
vector<pair<int, int>> location;
vector<pair<double, pair<int, int>>> vec;
int dist_map[1001][1001];
int parent[1001];

int find_parent(int a) {
    int par = parent[a];
    while (par != a) {
        a = par;
        par = parent[a];
    }
    return par;
}

bool link(int a, int b) {
    int a_par = find_parent(a);
    int b_par = find_parent(b);

    if (a_par == b_par)
        return false;
    else
        parent[a_par] = b_par;
    return true;
}

int main() {
    cin >> N >> M;
    location.push_back({-1, -1});
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < N; i++) {
        cin >> u >> v;
        location.push_back({u, v});
    }

    for (int j = 0; j < M; j++) {
        cin >> u >> v;
        vec.push_back({0, {u, v}});
    }

    for (int i = 1; i <= N; i++) {
        int cx = location[i].first;
        int cy = location[i].second;
        for (int j = i + 1; j <= N; j++) {
            int nx = location[j].first;
            int ny = location[j].second;
            double dist = sqrt(pow((double)(cx - nx), 2) + pow((double)(cy - ny), 2));
            vec.push_back({dist, {i, j}});
        }
    }

    sort(vec.begin(), vec.end());

    double answer = 0;

    for (int i = 0; i < vec.size(); i++) {
        int a = vec[i].second.first;
        int b = vec[i].second.second;
        double dist = vec[i].first;
        if (!link(a, b)) continue;
        answer += dist;
    }

    cout << fixed;
    cout.precision(2);
    cout << answer << endl;
}