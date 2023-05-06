#include <iostream>
#include <vector>
using namespace std;

int graph[101][101];
int n, m, p, q, c;
int main() {
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = 987654321;
        }
    }
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> p >> q >> c;
        graph[p][q] = min(graph[p][q], c);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                graph[j][k] = min(graph[j][i] + graph[i][k], graph[j][k]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] >= 987654321)
                cout << "0 ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}