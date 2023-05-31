#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

const int N = 100005;
vector<pair<int, int>> adj[N];
int dist[N];
bool visited[N];
void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) { continue; }
        visited[u] = true;
        for (auto v : adj[u]) {
            int w = v.first;
            int to = v.second;
            if (dist[to] > dist[u] + w) {
                dist[to] = dist[u] + w;
                pq.push({ dist[to], to }); 
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ w, v });
        adj[v].push_back({ w, u });
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    dist[1] = 0;
    dijkstra(1);
    cout << dist[n] << endl;
    return 0;
}
