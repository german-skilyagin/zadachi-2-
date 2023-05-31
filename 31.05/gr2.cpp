#include <iostream>
#include <vector>
using namespace std;

const int N = 105;
int dist[N][N];
void floyd_warshall(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) { dist[i][j] = 0; }
            else { dist[i][j] = INT_MAX; }
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w; 
        dist[v][u] = w; 
    }
    floyd_warshall(n);
    int max_time = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] != INT_MAX && dist[i][j] > max_time) {
                max_time = dist[i][j];
            }
        }
    }
    cout << max_time << endl;
    return 0;
}