#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
int N, M, u;
vector<int> parent;

int find_parent(int a) {
    if (parent[a] == a) return a;

    return parent[a] = find_parent(parent[a]);
}

void _union(int a, int b) {
    int aParent = find_parent(a);
    int bParent = find_parent(b);
    if (aParent > bParent) {
        parent[aParent] = bParent;
    } else {
        parent[bParent] = aParent;
    }
}

int main() {
    cin >> N >> M;
    parent = vector<int>(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> u;
            if (u == 1) {
                _union(i, j);
            }
        }
    }

    int root = 0;
    for (int i = 0; i < M; i++) {
        cin >> u;
        if (i == 0) {
            root = find_parent(u);
        } else if (find_parent(u) != root) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}